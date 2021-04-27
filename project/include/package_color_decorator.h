/**
 *@file package_color_decorator.h
 */
#ifndef PACKAGE_COLOR_DECORATOR_H_
#define PACKAGE_COLOR_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "package.h"
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
class PackageColorDecorator : public Package {
    public:
        /**
        * @brief Constructor: sets up Package by instantiating all of its values.
        */
        PackageColorDecorator(Package *package);
        
        /**
        * @brief Destructor: deletes all allocated memory in Package by deleting these values.
        */
        ~PackageColorDecorator();
        
        /**
         * @brief Update package by coloring based on distance to customer
         */
        void Update(float dt) override; 

        /**
        * @brief Gets the id of the package.
        *
        * @return Id value.
        */
        int GetId() const override;

        /**
        * @brief Gets the details of the package.
        *
        * @return Details.
        */
        const picojson::object& GetDetails() override;
        
        /**
        * @brief Gets the name of the package.
        *
        * @return Name value.
        */
        const std::string& GetName() override;
        
        /**
        * @brief Gets the position of the package.
        *
        * @return Position vector.
        */
        const std::vector<float>& GetPosition() const override;
        
        /**
        * @brief Gets the direction of the package.
        *
        * @return Direction vector.
        */
        const std::vector<float>& GetDirection() const override;
        
        /**
        * @brief Gets the position of the package in a Vector3D.
        *
        * @return Vector3D of position.
        */
        Vector3D GetVectorPosition() override;
        
        /**
        * @brief Gets the direction of the package in a Vector3D.
        *
        * @return Vector3D of direction.
        */
        Vector3D GetVectorDirection() override;
        
        /**
        * @brief Gets the radius of the package.
        *
        * @return Radius value.
        */
        float GetRadius() const override;

        /**
        * @brief Returns the version of the package.
        *
        * @return Version number.
        */
        int GetVersion() const override;

        /**
        * @brief Sets the position of the package to the input value.
        *
        * @param newPosition Vector for position input.
        */
        void SetPosition(std::vector<float> newPosition) override;
        
        /**
        * @brief Checks if package is dynamic or not.
        *
        * @return True or false.
        */
        bool IsDynamic() const override;
        
        /**
        * @brief Gets the version of the travel status of the package.
        *
        * @return True if moving with drone, or false if not with drone.
        */
        bool GetTravelStatus() override;

        /**
        * @brief Gets the version of the package.
        *
        * @return True or false.
        */
        bool GetDeliveryStatus() override;

        /**
        * @brief Sets the delivery status to the given value.
        * 
        * @param isTraveling True if traveling, False if not.
        */
        void SetTraveling(bool isTraveling) override;

        /**
        * @brief Sets values as if a package was delivered.
        *
        * Sets travelStatus to false and deliveryStatus to true.
        */
        void Delivered() override;

    private:
        Package *package;
};

}//namespace csci3081

#endif    // PACKAGE_H_