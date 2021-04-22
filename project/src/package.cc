#include "package.h"
#include "json_helper.h"

namespace csci3081 {

Package::Package(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id) {
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

Package::~Package() {
    delete vectorPosition;
    delete vectorDirection;
}

int Package::GetId() const  {
    return id;
}

const std::string& Package::GetName()   {
    return name;
}

const std::vector<float>& Package::GetPosition() const  {
    return position;
}

const std::vector<float>& Package::GetDirection() const {
    return direction;
}


Vector3D Package::GetVectorPosition()   {
    return *vectorPosition;
}

Vector3D Package::GetVectorDirection()  {
    return *vectorDirection;
}

float Package::GetRadius() const    {
    return 1.0;
}

int Package::GetVersion() const {
    return 0.0;
}

void Package::SetPosition(std::vector<float> position)  {
    this->position = position;
    vectorPosition->SetVector(position);
}

bool Package::IsDynamic() const {
    return true;
}

bool Package::GetTravelStatus() {
    return travelStatus;
}

bool Package::GetDeliveryStatus()   {
    return deliveryStatus;
}

void Package::SetTraveling(bool isTraveling)    {
    travelStatus = isTraveling;
}

void Package::Delivered()   {
    deliveryStatus = true;
    travelStatus = false;
}

}//namespace csci3081