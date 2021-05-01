#include "customer_color_decorator.h"
#include "json_helper.h"

namespace csci3081	{

CustomerColorDecorator::CustomerColorDecorator(Customer *customer)	{
	this->customer = customer;

	timer = 0;

	// Initialize customer color to green
	SetDetailsKey("color", picojson::value("0x00ff00"));
	NotifyDetailsUpdate(); 
}
        
CustomerColorDecorator::~CustomerColorDecorator()	{
	delete customer;
}
        
void CustomerColorDecorator::Update(float dt)	{
	customer->Update(dt);

	// Increment timer by dt for each update
	timer += dt;

	// Change color to yellow if waiting for less than 25 "seconds"
	if (timer < 25.0)	{
		SetDetailsKey("color", picojson::value("0xffff00"));
		NotifyDetailsUpdate();
	}

	// Change color to orange if waiting for less than 50 "seconds"
	else if (timer < 50)	{
		SetDetailsKey("color", picojson::value("0xffa500"));
		NotifyDetailsUpdate();
	}

	// Change color to red if waiting for more than 50 "seconds"
	else	{
		SetDetailsKey("color", picojson::value("0xff0000"));
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
	// Change color back to green
	SetDetailsKey("color", picojson::value("0x00ff00"));
	NotifyDetailsUpdate();

	// Change timer back to 0
	timer = 0;
}

}