#include "package_color_decorator.h"
#include "json_helper.h"

namespace csci3081 {

PackageColorDecorator::PackageColorDecorator(Package *package) {
    this->package = package;
}

PackageColorDecorator::~PackageColorDecorator() {
    delete package;
}

void PackageColorDecorator::Update(float dt) {
    package->Update(dt);
    
}

int PackageColorDecorator::GetId() const {
    return package->GetId();
}

const picojson::object& PackageColorDecorator::GetDetails() {
    return package->GetDetails();
}

const std::string& PackageColorDecorator::GetName() {
    return package->GetName();
}

const std::vector<float>& PackageColorDecorator::GetPosition() const {
    return package->GetPosition();
}

const std::vector<float>& PackageColorDecorator::GetDirection() const {
    return package->GetDirection();
}

Vector3D PackageColorDecorator::GetVectorPosition() {
    return package->GetVectorPosition();
}

Vector3D PackageColorDecorator::GetVectorDirection() {
    return package->GetVectorDirection();
}

float PackageColorDecorator::GetRadius() const {
    return package->GetRadius();
}

int PackageColorDecorator::GetVersion() const {
    return package->GetVersion();
}

void PackageColorDecorator::SetPosition(std::vector<float> position)  {
    package->SetPosition(position);
}

bool PackageColorDecorator::IsDynamic() const {
    return package->IsDynamic();
}

bool PackageColorDecorator::GetTravelStatus() {
    return package->GetTravelStatus();
}

bool PackageColorDecorator::GetDeliveryStatus()   {
    return package->GetDeliveryStatus();
}

void PackageColorDecorator::SetTraveling(bool isTraveling)    {
    package->SetTraveling(isTraveling);
}

void PackageColorDecorator::Delivered()   {
    package->Delivered();
}

} //namespace csci3081