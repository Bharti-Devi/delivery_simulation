#include "package_color_decorator.h"
#include "json_helper.h"

namespace csci3081 {

PackageColorDecorator::PackageColorDecorator(Package *package) {
    this->package = package;
    maxDistance = -1.0;
    currentColor = colorMap.begin();
    package->SetDetailsKey("color", currentColor->second);
    NotifyDetailsUpdate();
}

PackageColorDecorator::~PackageColorDecorator() {
    delete package;
}

void PackageColorDecorator::Update(float dt) {
    package->Update(dt);

    if (GetCustomer() == nullptr) {
        return;
    }

    // Find current distance to customer
    Vector3D packagePosition = GetVectorPosition();
    Vector3D customerPosition = GetCustomer()->GetVectorPosition();
    Vector3D difference = packagePosition - customerPosition;
    double distance = difference.Magnitude();

    // Calculate proportion of max distance, determine if color change is necessary, and notify observers if so
    maxDistance = (distance > maxDistance) ? distance : maxDistance;
    double proportionOfMaxDistance = distance / maxDistance;
    auto newColor = colorMap.upper_bound(proportionOfMaxDistance);
    if (currentColor != newColor) {
        currentColor = newColor;
        SetDetailsKey("color", currentColor->second);
        NotifyDetailsUpdate();
    }
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

Customer* PackageColorDecorator::GetCustomer() {
    return package->GetCustomer();
}

void PackageColorDecorator::SetCustomer(Customer *customer) {
    package->SetCustomer(customer);
}

void PackageColorDecorator::SetDetailsKey(const std::string& key, const picojson::value& value) {
    package->SetDetailsKey(key, value);
}

void PackageColorDecorator::NotifyDetailsUpdate() {
    package->NotifyDetailsUpdate();
}

} //namespace csci3081