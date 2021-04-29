#include "drone_battery_decorator.h"
#include "json_helper.h"
#include <iostream>

namespace csci3081 {

DroneBatteryDecorator::DroneBatteryDecorator(Drone *drone) {
    this->decoratedDrone = drone;
    double charge = decoratedDrone->GetCharge();
    details_ = decoratedDrone->GetDetails();

    //get the battery capacity
    bool contains = JsonHelper::ContainsKey(details_, "battery_capacity");
    if(contains){
      batteryCapacity = JsonHelper::GetDouble(details_, "battery_capacity");
    }
    else{
      batteryCapacity = 10000.0;
    }

    //check initial color of battery
    isRed = charge >= 0 && charge <= batteryCapacity*0.25;
    isOrange = charge > batteryCapacity*0.25 && charge <= batteryCapacity*0.5;
    isYellow = charge > batteryCapacity*0.5 && charge <= batteryCapacity*0.75;
    isGreen = charge > batteryCapacity*0.75 && charge <= batteryCapacity;
}

DroneBatteryDecorator::~DroneBatteryDecorator() {
  delete decoratedDrone;
}

int DroneBatteryDecorator::GetId() const {
  return decoratedDrone->GetId();
}

const picojson::object& DroneBatteryDecorator::GetDetails() {
    return decoratedDrone->GetDetails();
}

const std::string& DroneBatteryDecorator::GetName() {
  return decoratedDrone->GetName();
}

const std::vector<float>& DroneBatteryDecorator::GetPosition() const {
  return decoratedDrone->GetPosition();
}

const std::vector<float>& DroneBatteryDecorator::GetDirection() const {
  return decoratedDrone->GetDirection();
}

Vector3D DroneBatteryDecorator::GetVectorPosition() {
  return decoratedDrone->GetVectorPosition();
}

Vector3D DroneBatteryDecorator::GetVectorDirection()  {
 return decoratedDrone->GetVectorDirection();
}

float DroneBatteryDecorator::GetRadius() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedDrone->GetRadius();
}

int DroneBatteryDecorator::GetVersion() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedDrone->GetVersion();
}

bool DroneBatteryDecorator::IsDynamic() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedDrone->IsDynamic();
}

void DroneBatteryDecorator::Update(float dt)  {
  decoratedDrone->Update(dt); //call update function
  double charge = decoratedDrone->GetCharge();//get battery charge
  //check what color battery should be
  bool red = charge >= 0 && charge <= batteryCapacity*0.25;
  bool orange = charge > batteryCapacity*0.25 && charge <= batteryCapacity*0.5;
  bool yellow = charge > batteryCapacity*0.5 && charge <= batteryCapacity*0.75;
  bool green = charge > batteryCapacity*0.75 && charge <= batteryCapacity;
  //update battery color if battery charge reaches a point where color should change
  if(red && !isRed){
    details_["color"] = picojson::value("0xff0000");
    NotifyBatteryColor("updateDetails", decoratedDrone, details_);
    isRed = red;
  }
  else if(orange && !isOrange){
    details_["color"] = picojson::value("0xffa500");
    NotifyBatteryColor("updateDetails", decoratedDrone, details_);
    isOrange = orange;
  }
  else if (yellow && !isYellow){
    details_["color"] = picojson::value("0xffff00");
    NotifyBatteryColor("updateDetails", decoratedDrone, details_);
    isYellow = yellow;
  }
  else if(green && !isGreen){
    details_["color"] = picojson::value("0x00ff00");
    NotifyBatteryColor("updateDetails", decoratedDrone, details_);
    isGreen = green;
  }
}

void DroneBatteryDecorator::PickUp()  {
  decoratedDrone->PickUp();
}

void DroneBatteryDecorator::DropOff() {
  decoratedDrone->DropOff();
}

int DroneBatteryDecorator::GetCharge()  {
  return decoratedDrone->GetCharge();
}

void DroneBatteryDecorator::SetDeliveryObject(DeliveryObject* delivery) {
  decoratedDrone->SetDeliveryObject(delivery);
}

bool DroneBatteryDecorator::IsScheduled() {
  return decoratedDrone->IsScheduled();
}
bool DroneBatteryDecorator::DoesHavePackage() {
  return decoratedDrone->DoesHavePackage();
}

}//namespace csci3081