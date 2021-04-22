#include "battery.h"

namespace csci3081 {

Battery::Battery(double maxCharge)  {
    this->maxCharge = maxCharge;
    curCharge = maxCharge;
    isEmpty = false;
}

void Battery::SetCurCharge(double newCharge)    {
    if(newCharge <= 0.0)    {
        curCharge = 0.0;
        isEmpty = true;
    }
    else if (newCharge >= maxCharge)    {
        curCharge = maxCharge;
        isEmpty = false;
    }
    else    {
        curCharge = newCharge;
        isEmpty = false;
    }
}

double Battery::GetCurCharge()  {
    return curCharge;
}

bool Battery::GetIsEmpty()  {
    return isEmpty;
}

void Battery::DepleteCharge(double amountDepleted)  {
    this->SetCurCharge(curCharge - amountDepleted);
}

void Battery::Charge(double amountCharged)  {
    this->SetCurCharge(curCharge + amountCharged);
}

}//namespace csci3081