/**
 *@file customer_color_decorator.h
 */
#ifndef CUSTOMER_COLOR_DECORATOR_H_
#define CUSTOMER_COLOR_DECORATOR_H_

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
 * @brief The main class for decorating a Customer.
 *
 * Customer changes color based on time spent waiting for package.
 *
 * Customer notifies observer that a color change has occurred.
 */
class CustomerColorDecorator : public Customer  {

    public:
        /**
        * @brief Constructor: Sets up CustomerColorDecorator.
        * 
        * @param customer Customer object.
        */
        CustomerColorDecorator(Customer *customer);
        
        /**
        * @brief Destructor: Deletes customer object.
        */
        ~CustomerColorDecorator();
        
        /**
         * @brief Update Customer by coloring based on wait time for package.
         *
         * @param dt Derivative.
         */
        void Update(float dt) override; 

        /**
         * @brief Gets the details of the customer.
         *
         * @return Details.
         */
        const picojson::object& GetDetails() override;

        /**
         * @brief Gets the id of the customer.
         *
         * @return Id as an int value.
         */
        int GetId() const override;

        /**
         * @brief Gets the name of the customer
         *
         * @return Name string.
         */
        const std::string& GetName() override;

        /**
        * @brief Gets the position of the customer.
        *
        * @return Vector for position.
        */
        const std::vector<float>& GetPosition() const override;

        /**
        * @brief Gets the direction of the customer.
        *
        * @return Vector for direction.
        */
        const std::vector<float>& GetDirection() const override;
        
        /**
        * @brief Gets the position of the customer in a Vector3D.
        *
        * @return Vector3D for position.
        */
        Vector3D GetVectorPosition() override;
        
        /**
        * @brief Gets the direction of the customer in a Vector3D.
        *
        * @return Vector3D for direction.
        */
        Vector3D GetVectorDirection() override;
        
        /**
        * @brief Gets the radius of the customer.
        *
        * @return Radius float value.
        */
        float GetRadius() const override;
        
        /**
        * @brief Checks if customer has a package.
        *
        * @return True or false.
        */
        bool GetHavePackage() override;
        
        /**
        * @brief Gets the version of the customer.
        *
        * @return Version.
        */
        int GetVersion() const override;

        /**
         * @brief Set some key in the details of the entity.
         * 
         * @param key Key to set.
         * 
         * @param value Value to set key to.
         */
        void SetDetailsKey(const std::string& key, const picojson::value& value);
        
        /**
        * @brief Checks if customer is dynamic or not.
        *
        * @return True or false.
        */
        bool IsDynamic() const override;
        
        /**
        * @brief Indicates that customer received package.
        */
        void RecievePackage() override;

    private:
        Customer *customer;
        float timer;
};

}//namespace csci3081

#endif    // CUSTOMER_H_