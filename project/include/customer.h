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
        * @brief Constructor: sets up Customer by instantiating all of its values.
        *
        */
        Customer(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id);
        /**
        * @brief Destructor: deletes all allocated memory in Customer by deleting these values.
        *
        */
        ~Customer();
        /**
        * @brief Gets the id of the customer.
        *
        * @return Id as an int value.
        */
        int GetId() const;
        /**
        * @brief Gets the name of the customer
        *
        * @return Name string.
        */
        const std::string& GetName();
        /**
        * @brief Gets the position of the customer.
        *
        * @return Vector for position.
        */
        const std::vector<float>& GetPosition() const;
        /**
        * @brief Gets the direction of the customer.
        *
        * @return Vector for direction.
        */
        const std::vector<float>& GetDirection() const;
        /**
        * @brief Gets the position of the customer in a Vector3D.
        *
        * @return Vector3D for position.
        */
        Vector3D GetVectorPosition();
        /**
        * @brief Gets the direction of the customer in a Vector3D.
        *
        * @return Vector3D for direction.
        */
        Vector3D GetVectorDirection();
        /**
        * @brief Gets the radius of the customer
        *
        * @return Radius float value.
        */
        float GetRadius() const;
        /**
        * @brief Checks if customer has a package.
        *
        * @return True or false.
        */
        bool GetHavePackage();
        /**
        * @brief Gets the version of the customer.
        *
        * @return Version.
        */
        int GetVersion() const;
         /**
        * @brief Checks if customer is dynamic or not.
        *
        * @return True or false.
        */
        bool IsDynamic() const;
        /**
        * @brief Sets havePackage to true.
        * 
        * Done when a customer recieves a package.
        */
        void RecievePackage();
    private:
        std::vector<float> position;
        std::vector<float> direction;
        Vector3D* vectorPosition;
        Vector3D* vectorDirection;
        std::string name;
        bool havePackage;
        int id;
};

}//namespace csci3081

#endif    // CUSTOMER_H_