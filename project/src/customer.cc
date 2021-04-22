#include "customer.h"

namespace csci3081 {

Customer::Customer(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id)   {
    this->position = pos;
    this->direction = direction;
    this->vectorPosition = new Vector3D(pos);
    this->vectorDirection = new Vector3D(direction);
    name = "customer";
    havePackage = false;
    this->id = id;

    details_ = obj;
}

Customer::~Customer()   {
    delete vectorPosition;
    delete vectorDirection;
}

int Customer::GetId() const {
    return id;
}

const std::string& Customer::GetName()  {
    return name;
}

const std::vector<float>& Customer::GetPosition() const {
    return position;
}

const std::vector<float>& Customer::GetDirection() const    {
    return direction;
}

Vector3D Customer::GetVectorPosition()  {
    return *vectorPosition;
}

Vector3D Customer::GetVectorDirection() {
    return *vectorDirection;
}

float Customer::GetRadius() const   {
    return 1.0;
}

int Customer::GetVersion() const    {
    return 0.0;
}

bool Customer::GetHavePackage() {
    return havePackage;
}

bool Customer::IsDynamic() const    {
    return true;
}

void Customer::RecievePackage() {
    havePackage = true;
}

}//namespace csci3081