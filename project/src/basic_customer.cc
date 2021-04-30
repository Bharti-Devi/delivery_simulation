#include "basic_customer.h"
#include "json_helper.h"

namespace csci3081 {

BasicCustomer::BasicCustomer(std::vector<float> position, std::vector<float> direction, const picojson::object& obj, int id)    {
    this->position = position;
    this->direction = direction;
    this->vectorPosition = new Vector3D(position);
    this->vectorDirection = new Vector3D(direction);

    name = "customer";
    this->id = id;

    details_ = obj;
}

BasicCustomer::~BasicCustomer() {
    delete vectorPosition;
    delete vectorDirection;
}

int BasicCustomer::GetId() const    {
    return id;
}

const std::string& BasicCustomer::GetName()    {
    return name;
}

const std::vector<float>& BasicCustomer::GetPosition() const   {
    return position;
}

const std::vector<float>& BasicCustomer::GetDirection() const  {
    return direction;
}

Vector3D BasicCustomer::GetVectorPosition() {
    return *vectorPosition;
}

Vector3D BasicCustomer::GetVectorDirection() {
    return *vectorDirection;
}

float BasicCustomer::GetRadius() const    {
    return 1.0;
}

bool BasicCustomer::GetHavePackage()   {
    // TODO: replace
    return false;
}

int BasicCustomer::GetVersion() const  {
    return 0.0;
}

bool BasicCustomer::IsDynamic() const  {
    return true;
}

void BasicCustomer::RecievePackage()   {
    //
}

}//namespace csci3081