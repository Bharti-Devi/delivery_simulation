#include "basic_robot.h"
#include "json_helper.h"
#include <iostream>

namespace csci3081  {

BasicRobot::BasicRobot(std::vector<float> pos, std::vector<float> direction, const picojson::object& details, 
            int id, DeliveryManager* manager, Pathfinder* strategy) {
  this->position = pos;
  this->direction = direction;
  this->vectorPosition = new Vector3D(position);
  this->vectorDirection = new Vector3D(direction);
  this->manager = manager;
  this->delivery = NULL;
  this->strategy = strategy;

  name = JsonHelper::GetString(details, "name");
  speed = 30.0;

  if (JsonHelper::ContainsKey(details, "battery_capacity")) {
    battery = Battery(JsonHelper::GetDouble(details, "battery_capacity"));
  }
  else {
    battery = Battery();
  }

  this->id = id;
  hasPackage = false;
  scheduled = false;

  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
  details_ = details;

  JsonHelper::AddValueToJsonObject(details_, "color",  picojson::value("0x00ff00"));
  NotifyBatteryColor("updateDetails", this, details_);
}

BasicRobot::~BasicRobot() {
  delete vectorPosition;
  delete vectorDirection;
}

int BasicRobot::GetId() const {
  return id;
}

const std::string& BasicRobot::GetName() {
  return name;
}

const std::vector<float>& BasicRobot::GetPosition() const {
  return position;
}

const std::vector<float>& BasicRobot::GetDirection() const {
  return direction;
}

Vector3D BasicRobot::GetVectorPosition() {
  return *vectorPosition;
}

Vector3D BasicRobot::GetVectorDirection()  {
 return *vectorDirection;
}

float BasicRobot::GetRadius() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return 1;
}

int BasicRobot::GetVersion() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return 0;
}

bool BasicRobot::IsDynamic() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return true;
}

void BasicRobot::Update(float dt)  {

  // Ensure that this robot has some work to do. If not, return immediately.
  if (!scheduled) {
    if (battery.GetIsEmpty()) {
      return;
    }

    DeliveryObject *newDelivery = manager->GetWork(this); // starts to move towards a package
    if (newDelivery == nullptr) {
      return;
    }

    SetDeliveryObject(newDelivery);
    this->NotifyPackage("scheduled", newDelivery->GetPackage());
    this->NotifyMovingVehicle("moving", this, packagePath); // notify that robot is moving to a package
  }

  // We will set stopCondition and break out from the main update loop when a stopping condition is met.
  enum StopCondition { SUCCESS, DEPLETED, NOWORK };
  StopCondition stopCondition = StopCondition::SUCCESS;

  // Set up a currentPath pointer, which we will maintain to point to
  // the path we are following (this depends on whether we are carrying
  // a package to a customer or just flying to a package)
  std::vector< std::vector<float> > *currentPath;

  if (hasPackage) {
    currentPath = &customerPath;
  }
  else {
    currentPath = &packagePath;
  }

  // Compute the distance robot will travel if kept busy during the whole update cycle.
  float timeLimitedDistance = dt * speed;
  float batteryLimitedDistance = battery.GetCurCharge() * speed;
  float remainingDistance; // Travelable distance

  if (timeLimitedDistance < batteryLimitedDistance) {
    remainingDistance = timeLimitedDistance;
    stopCondition = StopCondition::SUCCESS;
  }
  else {
    remainingDistance = batteryLimitedDistance;
    stopCondition = StopCondition::DEPLETED;
  }

  // Upon exit of the main loop, differenceVector is parallel to instantaneous motion direction, or previous direction if unmoving.
  Vector3D differenceVector = Vector3D(direction);
  Vector3D newPosition = Vector3D(position);

  // Main loop: Move until the robot has met any stopping condition
  while (true) {

    // Move until we need to switch to new path, or distance budget is exhausted
    // Upon exit of loop, differenceVector is parallel to instantaneous movement direction
    // of robot, and newPosition is where it should have reached.
    while (currentPath->size() > 0) {
      Vector3D nextRoutePoint = Vector3D(currentPath->back());
      differenceVector = nextRoutePoint - newPosition;
      
      if (differenceVector.Magnitude() < remainingDistance) {
        remainingDistance -= differenceVector.Magnitude();
        battery.DepleteCharge(differenceVector.Magnitude());
        newPosition = currentPath->back();
        currentPath->pop_back();
      }
      else {
        differenceVector.Normalize();
        newPosition = newPosition + (differenceVector * remainingDistance);
        battery.DepleteCharge(remainingDistance / speed);
        goto FINISH;
      }
    }

    // Try to pick up or deliver package. This should always succeed.
    if (!hasPackage) {
      if (delivery->PickUp(newPosition.GetVector())) { // Put code that should execute when packages are picked up here
        hasPackage = true;
        currentPath = &customerPath;
        this->NotifyPackage("en route", delivery->GetPackage());
        this->NotifyMovingVehicle("moving", this, customerPath); // notify that robot is moving to a customer
      }
      else {
        std::cout << "This robot is stuck. Empty path and unable to do anything." << std::endl;
      }

    }
    else {
      if (delivery->DropOff(newPosition.GetVector())) { // Put code that should execute when packages are dropped off here
        hasPackage = false;
        currentPath = &packagePath;
        this->NotifyPackage("delivered", delivery->GetPackage());
        DeliveryObject *newDelivery = manager->GetWork(this);

        if (newDelivery == nullptr) {
          stopCondition = StopCondition::NOWORK;
          goto FINISH;
        }

        SetDeliveryObject(newDelivery);
        this->NotifyMovingVehicle("moving", this, packagePath); // notify that robot is moving to a package
        this->NotifyPackage("scheduled", newDelivery->GetPackage());
      }
      else {
        std::cout << "This robot is stuck. Empty path and unable to do anything." << std::endl;
      }
    }
  }

  FINISH:

  // Set position and direction of package and robot
  differenceVector.Normalize();
  direction = differenceVector.GetVector();
  position = newPosition.GetVector();
  
  if (delivery) delivery->Update(dt, position);

  // Code specific to reason for stopping
  switch (stopCondition) {
    case SUCCESS:
      // Nothing to do
    break;

    case DEPLETED:
      battery.SetCurCharge(0.0);  // because fp math might leave a small but useless amount of charge in battery
      if (hasPackage) {
        delivery->Drop(position);
        hasPackage = false;
      }
      manager->AcceptDroppedPackageReport(delivery);
      scheduled = false;
      this->NotifyIdleVehicle("idle", this);  // notify that robot isn't moving
    break;
    
    case NOWORK:
      scheduled = false;
      this->NotifyIdleVehicle("idle", this);  // notify that robot isn't moving
    break;

    default:

    break;
  }

  return;
}

void BasicRobot::PickUp()  {
  if (delivery->PickUp(position)) {
    hasPackage = true;
  }
}

void BasicRobot::DropOff() {
  if (delivery->DropOff(position)) {
    hasPackage = false;
    scheduled = false;
    delete delivery;
  }
}

int BasicRobot::GetCharge()  {
  return battery.GetCurCharge();
}

void BasicRobot::SetDeliveryObject(DeliveryObject* delivery) {
  this->delivery = delivery;
  this->packagePath = manager->GetGraph()->GetPath(delivery->GetPackagePosition(), position);
  this->customerPath = manager->GetGraph()->GetPath(delivery->GetCustomerPosition(), delivery->GetPackagePosition());
  scheduled = true;
}

bool BasicRobot::IsScheduled() {
  return scheduled;
}

bool BasicRobot::DoesHavePackage() {
  return hasPackage;
}

}//namespace csci3081