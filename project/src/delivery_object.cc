#include "delivery_object.h"

namespace csci3081 {

DeliveryObject::DeliveryObject(IEntity* package, IEntity* customer) {
    this->package = dynamic_cast<Package*>(package);
    this->customer = dynamic_cast<Customer*>(customer);
}

std::vector<float> DeliveryObject::GetDirection(Vector3D* vector)   {
    //Gets the difference and normalizes it as that is the direction vector
    //that the drone needs to face.
    Vector3D sum;

    if (package->GetTravelStatus())  {
        sum = (customer->GetVectorPosition()) - (*vector);
    }
    else{
        sum = (package->GetVectorPosition()) - (*vector);
    }

    sum.Normalize();
    return sum.GetVector();
}

std::vector<float> DeliveryObject::GetPackagePosition() {
    return package->GetPosition();
}

std::vector<float> DeliveryObject::GetCustomerPosition()    {
    return customer->GetPosition();
}

void DeliveryObject::Update(float dt, std::vector<float> pos)   {
    //Updates packages location if it is traveling.
    //float dt is there incase it is needed in later implementations.
    if (package->GetTravelStatus()) {
        pos[1] = pos[1] - package->GetRadius();
        package->SetPosition(pos);
    }
}

bool DeliveryObject::PickUp(std::vector<float> pos) {
    //Checks if it is within the radius of the package with error range of 0.1 as float arithmetic
    //can be difficult at times to get right on.
    if (((pos[0] >= package->GetPosition()[0]-package->GetRadius()-0.1)&&(pos[0] <= package->GetPosition()[0]+package->GetRadius()+0.1)) &&
        ((pos[1] >= package->GetPosition()[1]-package->GetRadius()-0.1)&&(pos[1] <= package->GetPosition()[1]+package->GetRadius()+0.1)) &&
        ((pos[2] >= package->GetPosition()[2]-package->GetRadius()-0.1)&&(pos[2] <= package->GetPosition()[2]+package->GetRadius()+0.1)))   {
            
            package->SetTraveling(true);
            pos[1] = pos[1] - package->GetRadius();
            package->SetPosition(pos);
            return true;
    }

    return false;
}

bool DeliveryObject::DropOff(std::vector<float> pos)    {
    //Checks if it is within the radius of the customer with error range of 0.1 as float arithmetic
    //can be difficult at times to get right on.
    if (((pos[0] >= customer->GetPosition()[0]-customer->GetRadius()-0.1)&&(pos[0] <= customer->GetPosition()[0]+customer->GetRadius()+0.1)) &&
        ((pos[1] >= customer->GetPosition()[1]-customer->GetRadius()-0.1)&&(pos[1] <= customer->GetPosition()[1]+customer->GetRadius()+0.1)) &&
        ((pos[2] >= customer->GetPosition()[2]-customer->GetRadius()-0.1)&&(pos[2] <= customer->GetPosition()[2]+customer->GetRadius()+0.1)))   {
        
        std::vector<float> temp = package->GetPosition();
        //If it is delivered then its position needs to be moved away so it is no longer visible in the simulation.
        //Sending it down by a lot seemed like the best way to do it.
        temp[1] = -999;
        package->SetPosition(temp);
        package->Delivered();
        // std::cout<<"dropped"<< std::endl;
        return true;
    }

    return false;
}

void DeliveryObject::Drop(std::vector<float> pos)   {
    package->SetPosition(pos);
    package->SetTraveling(false);
}

Package* DeliveryObject::GetPackage()   {
    return package;
}

}//namespace csci3081