/**
 *@file package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

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
 * @brief The main class for Packages. Storing and reporting their information.
 *
 * Stores information on a specific Package object.
 */
class Package : public EntityBase {
    public:
        /**
        * @brief Constructor: sets up Package by instantiating all of its values.
        */
        Package(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id);
        
        /**
        * @brief Destructor: deletes all allocated memory in Package by deleting these values.
        */
        ~Package();
        
        /**
        * @brief Gets the id of the package.
        *
        * @return Id value.
        */
        int GetId() const;
        
        /**
        * @brief Gets the name of the package.
        *
        * @return Name value.
        */
        const std::string& GetName();
        
        /**
        * @brief Gets the position of the package.
        *
        * @return Position vector.
        */
        const std::vector<float>& GetPosition() const;
        
        /**
        * @brief Gets the direction of the package.
        *
        * @return Direction vector.
        */
        const std::vector<float>& GetDirection() const;
        
        /**
        * @brief Gets the position of the package in a Vector3D.
        *
        * @return Vector3D of position.
        */
        Vector3D GetVectorPosition();
        
        /**
        * @brief Gets the direction of the package in a Vector3D.
        *
        * @return Vector3D of direction.
        */
        Vector3D GetVectorDirection();
        
        /**
        * @brief Gets the radius of the package.
        *
        * @return Radius value.
        */
        float GetRadius() const;

        /**
        * @brief Returns the version of the package.
        *
        * @return Version number.
        */
        int GetVersion() const;

        /**
        * @brief Sets the position of the package to the input value.
        *
        * @param newPosition Vector for position input.
        */
        void SetPosition(std::vector<float> newPosition);
        
        /**
        * @brief Checks if package is dynamic or not.
        *
        * @return True or false.
        */
        bool IsDynamic() const;
        
        /**
        * @brief Gets the version of the travel status of the package.
        *
        * @return True if moving with drone, or false if not with drone.
        */
        bool GetTravelStatus();

        /**
        * @brief Gets the version of the package.
        *
        * @return True or false.
        */
        bool GetDeliveryStatus();

        /**
        * @brief Sets the delivery status to the given value.
        * 
        * @param isTraveling True if traveling, False if not.
        */
        void SetTraveling(bool isTraveling);

        /**
        * @brief Sets values as if a package was delivered.
        *
        * Sets travelStatus to false and deliveryStatus to true.
        */
        void Delivered();

    private:
        std::vector<float> position;
        std::vector<float> direction;
        Vector3D* vectorPosition;
        Vector3D* vectorDirection;
        std::string name;
        bool travelStatus;
        bool deliveryStatus;
        // float weight;
        int id;
};

}//namespace csci3081

#endif    // PACKAGE_H_