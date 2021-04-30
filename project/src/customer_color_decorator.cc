#include "customer_color_decorator.h"
#include "json_helper.h"
#include "package.h"

namespace csci3081	{

CustomerColorDecorator::CustomerColorDecorator(Customer *customer)	{
	this->customer = customer;

	// Initialize customer color to red because package is far
	SetDetailsKey("color", picojson::value("0xff0000"));
	NotifyDetailsUpdate(); 
}
        
CustomerColorDecorator::~CustomerColorDecorator()	{
	delete customer;
}
        
void CustomerColorDecorator::Update(float dt)	{
	customer->Update(dt);

	// Find current distance to package
    Vector3D customerPosition = GetVectorPosition();
    Vector3D packagePosition = GetPackage()->GetVectorPosition();
    Vector3D difference = packagePosition - customerPosition;
    double distance = difference.Magnitude();

    // Calculate proportion of max distance, determine if color change is necessary, and notify observers if so
    maxDistance = (distance > maxDistance) ? distance : maxDistance;
    double proportionOfMaxDistance = distance / maxDistance;

    // Turn green if less than 25% away
    if (proportionOfMaxDistance < 0.25)	{
		SetDetailsKey("color", picojson::value("0x00ff00"));
		NotifyDetailsUpdate();
	}

	// Turn blue if less than 50% away
	else if (proportionOfMaxDistance < 0.5)	{
		SetDetailsKey("color", picojson::value("0x0000ff"));
		NotifyDetailsUpdate();
	}
}

const picojson::object& CustomerColorDecorator::GetDetails() {
    return customer->GetDetails();
}

int CustomerColorDecorator::GetId() const	{
	return customer->GetId();
}

const std::string& CustomerColorDecorator::GetName()	{
	return customer->GetName();
}

const std::vector<float>& CustomerColorDecorator::GetPosition() const	{
	return customer->GetPosition();
}

const std::vector<float>& CustomerColorDecorator::GetDirection() const	{
	return customer->GetDirection();
}

Vector3D CustomerColorDecorator::GetVectorPosition()	{
	return customer->GetVectorPosition();
}

Vector3D CustomerColorDecorator::GetVectorDirection()	{
	return customer->GetVectorDirection();
}
        
float CustomerColorDecorator::GetRadius() const	{
	return customer->GetRadius();
}
        
bool CustomerColorDecorator::GetHavePackage()	{
	return customer->GetHavePackage();
}

int CustomerColorDecorator::GetVersion() const	{
	return customer->GetVersion();
}

void CustomerColorDecorator::SetDetailsKey(const std::string& key, const picojson::value& value) {
    customer->SetDetailsKey(key, value);
}

bool CustomerColorDecorator::IsDynamic() const	{
	return customer->IsDynamic();
}

void CustomerColorDecorator::RecievePackage()	{
	customer->RecievePackage();
}

Package* CustomerColorDecorator::GetPackage()	{
	return customer->GetPackage();
}

void CustomerColorDecorator::SetPackage(Package* package)	{
	customer->SetPackage(package);
}

}