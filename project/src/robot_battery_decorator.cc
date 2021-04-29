#include "robot_battery_decorator.h"
#include "json_helper.h"
#include <iostream>

namespace csci3081  {

RobotBatteryDecorator::RobotBatteryDecorator(Robot *robot) {
    this->decoratedRobot = robot;
    double charge = decoratedRobot->GetCharge();
    details_ = decoratedRobot->GetDetails();

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

RobotBatteryDecorator::~RobotBatteryDecorator() {
  delete decoratedRobot;
}

int RobotBatteryDecorator::GetId() const {
  return decoratedRobot->GetId();
}

const picojson::object& RobotBatteryDecorator::GetDetails() {
    return decoratedRobot->GetDetails();
}

const std::string& RobotBatteryDecorator::GetName() {
  return decoratedRobot->GetName();
}

const std::vector<float>& RobotBatteryDecorator::GetPosition() const {
  return decoratedRobot->GetPosition();
}

const std::vector<float>& RobotBatteryDecorator::GetDirection() const {
  return decoratedRobot->GetDirection();
}

Vector3D RobotBatteryDecorator::GetVectorPosition() {
  return decoratedRobot->GetVectorPosition();
}

Vector3D RobotBatteryDecorator::GetVectorDirection()  {
 return decoratedRobot->GetVectorDirection();
}

float RobotBatteryDecorator::GetRadius() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedRobot->GetRadius();
}

int RobotBatteryDecorator::GetVersion() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedRobot->GetVersion();
}

bool RobotBatteryDecorator::IsDynamic() const {
  // TODO: This is just a stub for compilation
  // Currently not in use.
  return decoratedRobot->IsDynamic();
}

void RobotBatteryDecorator::Update(float dt)  {
  decoratedRobot->Update(dt); //call update function
  double charge = decoratedRobot->GetCharge();//get battery charge
  //check what color battery should be
  bool red = charge >= 0 && charge <= batteryCapacity*0.25;
  bool orange = charge > batteryCapacity*0.25 && charge <= batteryCapacity*0.5;
  bool yellow = charge > batteryCapacity*0.5 && charge <= batteryCapacity*0.75;
  bool green = charge > batteryCapacity*0.75 && charge <= batteryCapacity;
  //update battery color if battery charge reaches a point where color should change
  if(red && !isRed){
    details_["color"] = picojson::value("0xff0000");
    NotifyBatteryColor("updateDetails", decoratedRobot, details_);
    isRed = red;
  }
  else if(orange && !isOrange){
    details_["color"] = picojson::value("0xffa500");
    NotifyBatteryColor("updateDetails", decoratedRobot, details_);
    isOrange = orange;
  }
  else if (yellow && !isYellow){
    details_["color"] = picojson::value("0xffff00");
    NotifyBatteryColor("updateDetails", decoratedRobot, details_);
    isYellow = yellow;
  }
  else if(green && !isGreen){
    details_["color"] = picojson::value("0x00ff00");
    NotifyBatteryColor("updateDetails", decoratedRobot, details_);
    isGreen = green;
  }
}

void RobotBatteryDecorator::PickUp()  {
  decoratedRobot->PickUp();
}

void RobotBatteryDecorator::DropOff() {
  decoratedRobot->DropOff();
}

int RobotBatteryDecorator::GetCharge()  {
  return decoratedRobot->GetCharge();
}

void RobotBatteryDecorator::SetDeliveryObject(DeliveryObject* delivery) {
  decoratedRobot->SetDeliveryObject(delivery);
}

bool RobotBatteryDecorator::IsScheduled() {
  return decoratedRobot->IsScheduled();
}

bool RobotBatteryDecorator::DoesHavePackage() {
  return decoratedRobot->DoesHavePackage();
}

}//namespace csci3081