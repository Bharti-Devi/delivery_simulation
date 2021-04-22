/**
 *@file delivery_object.h
 */
#ifndef DELIVERY_OBJECT_H_
#define DELIVERY_OBJECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "package.h"
#include "customer.h"
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief A class that stores a package and customer to allow the relaying and changing
* of information in order to conduct a delivery. 
*/
class DeliveryObject {
    public:
        /**
        * @brief Constructor: Initializes values for DeliveryObject.
        * 
        * Casts the package IEntity to a Package type dynamically.
        * 
        * Casts the customer IEntity to a Customer type dynamically.
        */
        DeliveryObject(IEntity* package, IEntity* customer);
        /**
         * @brief Gets the direction the object must go from the given Vector3D
         * to complete the part of the delivery it is on.
         * 
         * Takes the given Vector 3D and subtracts it from either the position of the Package or
         * the Customer depending on the stage of the delivery. It then finds the Unit Vector of that answer
         * and returns the std::vector<float> that the Unit Vector returns with GetVector().
         * 
         * @param droneVector Vector3D object for a drone.
         * 
         * @return Float vector for direction.
         */
        std::vector<float> GetDirection(Vector3D* droneVector);
         /**
         * @brief Returns the Package's position.
         *
         * @return Float vector for Package position.
         */
        std::vector<float> GetPackagePosition();
        /**
         * @brief Returns the Customer's position
         *
         * @return Float vector for Customer position. 
         */
        std::vector<float> GetCustomerPosition();
        /**
         * @brief Updates the package in order to change its position.
         * 
         * Takes the given position and if the package is traveling then it updates its location
         * to be the given positione except that y = y-1. For the drones this makes it look like it is 
         * carrying the package under it as it would.
         * 
         * Currently does not use dt however it may eventually need it in later iterations
         * so it is going to stay.
         * 
         * @param dt Derivative.
         * @param pos Position vector.
         */
        void Update(float dt, std::vector<float> pos);
         /**
         * @brief Checks if the position of the object is close enough to pickup
         * the package.
         * 
         * Checks the position against the packages position and if it is will set Package to be
         * picked up as well as changes its position to be the same as the objects except y = y-1
         * If it is picked up it also returns true to communicate that it has indeed been picked up.
         * 
         * @param pos Position.
         * 
         * @return True or false.
         */
        bool PickUp(std::vector<float> pos);
        /**
         * @brief Checks if the position of the package is close enough to dropoff the package
         * to the customer.
         * 
         * Checks the position of the package against the customers position and if it is will set Package to be
         * dropped up as well as changes its position to be the same as the given position except y = -999 so that
         * it no longer appears in the simulation. Also marks the package if delivered.
         * If it is dropped off returns true to communicate that it has been properly dropped off.
         * 
         * @param pos Position vector.
         * 
         * @return True or false.
         */
        bool DropOff(std::vector<float> pos);
        /**
         * @brief Drop package while not at customer location.
         */
        void Drop(std::vector<float> pos);
        /**
         * @brief Gets the Package that is being scheduled, picked up, and dropped off.
         *
         * @return Package object.         
         */
        Package* GetPackage();
        
    private:
        Package* package;
        Customer* customer;
};

}//namespace csci3081

#endif    // DELIVERY_OBJECT_H_