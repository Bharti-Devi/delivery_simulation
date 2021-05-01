/**
 *@file customer.h
 */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for Customers. Storing and reporting their information.
 *
 * Stores information on a specific Customer object.
 */
class Customer : public EntityBase {
    public:
        
        /**
        * @brief Destructor: deletes all allocated memory in Customer by deleting these values.
        *
        */
        virtual ~Customer() {};

        /**
        * @brief Gets the id of the customer.
        *
        * @return Id as an int value.
        */
        virtual int GetId() const = 0;

        /**
        * @brief Gets the name of the customer.
        *
        * @return Name string.
        */
        virtual const std::string& GetName() = 0;

        /**
        * @brief Gets the position of the customer.
        *
        * @return Vector for position.
        */
        virtual const std::vector<float>& GetPosition() const = 0;

        /**
        * @brief Gets the direction of the customer.
        *
        * @return Vector for direction.
        */
        virtual const std::vector<float>& GetDirection() const = 0;
        
        /**
        * @brief Gets the position of the customer in a Vector3D.
        *
        * @return Vector3D for position.
        */
        virtual Vector3D GetVectorPosition() = 0;
        
        /**
        * @brief Gets the direction of the customer in a Vector3D.
        *
        * @return Vector3D for direction.
        */
        virtual Vector3D GetVectorDirection() = 0;
        
        /**
        * @brief Gets the radius of the customer.
        *
        * @return Radius float value.
        */
        virtual float GetRadius() const = 0;
        
        /**
        * @brief Checks if customer has a package.
        *
        * @return True or false.
        */
        virtual bool GetHavePackage() = 0;
        
        /**
        * @brief Gets the version of the customer.
        *
        * @return Version.
        */
        virtual int GetVersion() const = 0;
        
        /**
        * @brief Checks if customer is dynamic or not.
        *
        * @return True or false.
        */
        virtual bool IsDynamic() const = 0;
        
        /**
        * @brief Sets havePackage to true.
        * 
        * Done when a customer recieves a package.
        */
        virtual void RecievePackage() = 0;

};

}//namespace csci3081

#endif    // CUSTOMER_H_