#include "basic_package.h"
#include "json_helper.h"

namespace csci3081 {

BasicPackage::BasicPackage(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id) {
    this->position = pos;
    this->direction = direction;
    this->vectorPosition = new Vector3D(pos);
    this->vectorDirection = new Vector3D(direction);

    name = "package";
    travelStatus = false;
    deliveryStatus = false;
    this->id = id;

    details_ = obj;
}

BasicPackage::~BasicPackage() {
    delete vectorPosition;
    delete vectorDirection;
}

int BasicPackage::GetId() const  {
    return id;
}

const std::string& BasicPackage::GetName()   {
    return name;
}

const std::vector<float>& BasicPackage::GetPosition() const  {
    return position;
}

const std::vector<float>& BasicPackage::GetDirection() const {
    return direction;
}


Vector3D BasicPackage::GetVectorPosition()   {
    return *vectorPosition;
}

Vector3D BasicPackage::GetVectorDirection()  {
    return *vectorDirection;
}

float BasicPackage::GetRadius() const    {
    return 1.0;
}

int BasicPackage::GetVersion() const {
    return 0.0;
}

void BasicPackage::SetPosition(std::vector<float> position)  {
    this->position = position;
    vectorPosition->SetVector(position);
}

bool BasicPackage::IsDynamic() const {
    return true;
}

bool BasicPackage::GetTravelStatus() {
    return travelStatus;
}

bool BasicPackage::GetDeliveryStatus()   {
    return deliveryStatus;
}

void BasicPackage::SetTraveling(bool isTraveling)    {
    travelStatus = isTraveling;
}

void BasicPackage::Delivered()   {
    deliveryStatus = true;
    travelStatus = false;
}

}//namespace csci3081