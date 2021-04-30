#include "customer_color_decorator.h"
#include "json_helper.h"

namespace csci3081	{

CustomerColorDecorator::CustomerColorDecorator(Customer *customer)	{
	this->customer = customer;
}
        
CustomerColorDecorator::~CustomerColorDecorator()	{
	delete customer;
}
        
void CustomerColorDecorator::Update(float dt)	{
	// Initialize timer
	timer_start = std::clock();

	customer->Update(dt);

    // Check wait time
    // Determine if color change is necessary, and notify observers if so
	timer_end = std::clock();

	// Customer goes red if waiting a long time
	if (( (timer_end - timer_start) / (double) CLOCKS_PER_SEC) > 15)	{
		details_["color"] = picojson::value("0xff0000");
	}
	// Customer goes blue if waiting a while
	else if (( (timer_end - timer_start) / (double) CLOCKS_PER_SEC) > 7)	{
		details_["color"] = picojson::value("0x0000ff");
	}
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

bool CustomerColorDecorator::IsDynamic() const	{
	return customer->IsDynamic();
}

void CustomerColorDecorator::RecievePackage()	{
	customer->RecievePackage();
}

}