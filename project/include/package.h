/**
 *@file basic_package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "customer.h"
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for Packages. Storing and reporting their information.
 *
 * Stores information on a specific Package object.
 */
class Package : public EntityBase {
    public:
        
        /**
        * @brief Destructor: deletes all allocated memory in Package by deleting these values.
        */
        virtual ~Package() {};
        
        /**
        * @brief Gets the id of the package.
        *
        * @return Id value.
        */
        virtual int GetId() const = 0;
        
        /**
        * @brief Gets the name of the package.
        *
        * @return Name value.
        */
        virtual const std::string& GetName() = 0;
        
        /**
        * @brief Gets the position of the package.
        *
        * @return Position vector.
        */
        virtual const std::vector<float>& GetPosition() const = 0;
        
        /**
        * @brief Gets the direction of the package.
        *
        * @return Direction vector.
        */
        virtual const std::vector<float>& GetDirection() const = 0;
        
        /**
        * @brief Gets the position of the package in a Vector3D.
        *
        * @return Vector3D of position.
        */
        virtual Vector3D GetVectorPosition() = 0;
        
        /**
        * @brief Gets the direction of the package in a Vector3D.
        *
        * @return Vector3D of direction.
        */
        virtual Vector3D GetVectorDirection() = 0;
        
        /**
        * @brief Gets the radius of the package.
        *
        * @return Radius value.
        */
        virtual float GetRadius() const = 0;

        /**
        * @brief Returns the version of the package.
        *
        * @return Version number.
        */
        virtual int GetVersion() const = 0;

        /**
        * @brief Sets the position of the package to the input value.
        *
        * @param newPosition Vector for position input.
        */
        virtual void SetPosition(std::vector<float> newPosition) = 0;
        
        /**
        * @brief Checks if package is dynamic or not.
        *
        * @return True or false.
        */
        virtual bool IsDynamic() const = 0;
        
        /**
        * @brief Gets the version of the travel status of the package.
        *
        * @return True if moving with drone, or false if not with drone.
        */
        virtual bool GetTravelStatus() = 0;

        /**
        * @brief Gets the version of the package.
        *
        * @return True or false.
        */
        virtual bool GetDeliveryStatus() = 0;

        /**
        * @brief Sets the delivery status to the given value.
        * 
        * @param isTraveling True if traveling, False if not.
        */
        virtual void SetTraveling(bool isTraveling) = 0;

        /**
        * @brief Sets values as if a package was delivered.
        *
        * Sets travelStatus to false and deliveryStatus to true.
        */
        virtual void Delivered() = 0;

        /**
         * @brief Returns Customer to be delivered to, if assigned; else NULL.
         */
        virtual Customer* GetCustomer() = 0;

        /**
         * @brief Sets Customer to be delivered to.
         * 
         * @param customer Customer to be delivered to.
         */
        virtual void SetCustomer(Customer *customer) = 0;
};

}//namespace csci3081

#endif    // BASIC_PACKAGE_H_