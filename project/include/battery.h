/**
 *@file battery.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for Batteries. Storing and reporting their information.
 *
 * Stores information on a specific Battery object.
 */
class Battery{
    public:
        /**
        * @brief Constructor: sets up Battery by instantiating all of its values.
        *
        */
        Battery(double maxCharge = 10000.0);
        /**
         * @brief Sets the charge of battery to the given value
         * 
         * @param newCharge The new level of charge
         * 
         * @return No return value
         */
        void SetCurCharge(double newCharge);
        /**
         * @brief Returns the charge of battery
         * 
         * @return Current charge
         */
        double GetCurCharge();
        /**
         * @brief indicates whether the battery is empty
         * 
         * @return Truth value of "The battery is empty"
         */
        bool GetIsEmpty();
        /**
         * @brief Depletes the charge by the given amount.
         * 
         * @param amountDepleted Amount by which the charge is depleted
         */
        void DepleteCharge(double amountDepleted);
        /**
         * @brief Increases the charge by the given amount.
         * 
         * @param amountDepleted Amount by which the charge is depleted
         */
        void Charge(double amountCharged);
    private:
        double maxCharge;
        double curCharge;
        bool isEmpty;
};

}//namespace csci3081

#endif    // BATTERY_H_