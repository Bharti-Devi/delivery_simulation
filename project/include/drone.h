/**
 *@file drone.h
 */
#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_vehicle.h"
#include "delivery_object.h"
#include "delivery_manager.h"
#include "battery.h"
#include "pathfinder.h"
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for Drones. Storing and reporting their information.
 *
 * Stores information on a specific Drone object.
 */

class Drone : public DeliveryVehicle {
public:
  /**
   * @brief Destructor: deletes all allocated values.
   */
  virtual ~Drone() {};

  /**
  * @brief Gets the id of the drone.
  *
  * @return Id value.
  */
  virtual int GetId() const = 0;

  /**
  * @brief Gets the name of the drone.
  *
  * @return Name value.
  */
  virtual const std::string& GetName() = 0;

  /**
  * @brief Gets the position of the drone.
  *
  * @return Position vector.
  */
  virtual const std::vector<float>& GetPosition() const = 0;

  /**
  * @brief Gets the direction of the drone.
  *
  * @return Direction vector.
  */
  virtual const std::vector<float>& GetDirection() const = 0;

  /**
  * @brief Gets the position of the drone as a Vector3D object pointer.
  *
  * @return Vector3D for position.
  */

  virtual Vector3D GetVectorPosition() = 0;

  /**
  * @brief Returns the direction of the drone as a Vector3D object pointer.
  *
  * @return Vector3D for direction.
  */
  virtual Vector3D GetVectorDirection() = 0;

  /**
  * @brief Gets the radius of the drone.
  *
  * @return Radius value.
  */
  virtual float GetRadius() const = 0;

  /**
  * @brief Gets the version of the drone.
  *
  * @return Version value.
  */
  virtual int GetVersion() const = 0;

  /**
  * @brief Checks if the drone is dynamic or not.
  *
  * @return True or false.
  */
  virtual bool IsDynamic() const = 0;

  /**
  * @brief updates the robots location based on dt, its speed, and
  * its current direction.
  *
  * Before doing anything it first checks if it has been scheduled for a delivery.
  * If no, it does nothing.
  * Otherwise it will start by checking if it currently has a package.
  * If it has a package it will use the customerPath to figure out where
  * it needs to go, if it does not it will use the packagePath.
  *
  * It then moves itself incrementally the distance it needs to go.
  * and if the distance goes past the point it is currently on, will pass
  * the leftover distance to see how far it goes to the next point.
  * Everytime it reaches a point it calls PickUp on the deliveryobject 
  * if it does not have a package and DropOff if it does. This way 
  * If it can pick up or drop off it will.
  *
  * @param dt Derivative.
  */
  virtual void Update(float dt) = 0;

  /**
   * @brief Checks if the drone can pickup the package by calling PickUp()
   * on the DeliveryObject delivery.
   */
  virtual void PickUp() = 0;

  /**
   * @brief Checks if the drone can dropoff the package by calling DropOff()
   * on the DeliveryObject delivery.
   */
  virtual void DropOff() = 0;

  /**
   * @brief Gets the charge of the drones battery by calling 
   * GetCurCharge() on the battery.
   *
   * @return Battery charge value.
   */
  virtual int GetCharge() = 0;

  /**
   * @brief Sets the DeliveryObject* delivery to the given pointer.
   * 
   * @param delivery DeliveryObject*.
   */
  virtual void SetDeliveryObject(DeliveryObject* delivery) = 0;

  /**
   * @brief Checks if the drone has been scheduled for a delivery
   * or not.
   * 
   * @return True or false.
   */
  virtual bool IsScheduled() = 0;

  /**
   * @brief Checks if the drone has a package in its possession
   * or not.
   * 
   * @return True or false.
   */

  virtual bool DoesHavePackage() = 0;
    
};

}  // namespace csci3081

#endif    // DRONE_H_