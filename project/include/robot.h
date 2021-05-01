/**
 *@file robot.h
 */
#ifndef ROBOT_H_
#define ROBOT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_vehicle.h"
#include "delivery_object.h"
#include "battery.h"
#include <vector>
#include <string>
#include "delivery_manager.h"
#include "pathfinder.h"

namespace csci3081 {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Main class for Robots, sharing and storing information.
 *
 *  Stores information on a Robot object.
 */

class Robot : public DeliveryVehicle{
public:
  /**
   * @brief Destructor: deletes all allocated values.
   */
  virtual ~Robot() {};

  /**
  * @brief Gets the id of the Robot.
  *
  * @return Id value.
  */
  virtual int GetId() const = 0;

  /**
  * @brief Gets the name of the Robot object.
  *
  * @return Name value.
  */
  virtual const std::string& GetName() = 0;

  /**
  * @brief Gets the position of the Robot.
  *
  * @return Position vector.
  */
  virtual const std::vector<float>& GetPosition() const = 0;
  
  /**
  * @brief Gets the direction of the Robot.
  *
  * @return Direction vector.
  */
  virtual const std::vector<float>& GetDirection() const = 0;

  /**
  * @brief Gets the position of the robot as a Vector2D object pointer.
  *
  * @return Position Vector3D.
  */
  virtual Vector3D GetVectorPosition() = 0;

  /**
  * @brief Gets the direction of the robot as a Vector2D object pointer.
  *
  * @return Direction Vector3D.
  */
  virtual Vector3D GetVectorDirection() = 0;

  /**
  * @brief Gets the radius of the robot.
  *
  * @return Radius value.
  */
  virtual float GetRadius() const = 0;

  /**
  * @brief Gets the version of the robot.
  *
  * @return Version number.
  */
  virtual int GetVersion() const = 0;

  /**
  * @brief Checks if the robot is dynamic or not.
  *
  * @return True or false.
  */
  virtual bool IsDynamic() const = 0;

  /**
  * @brief Updates the robots location based on dt, its speed, and
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
   * @brief Checks if the Robot can pickup the package by calling PickUp()
   * on the DeliveryObject delivery.
   */
  virtual void PickUp() = 0;

  /**
   * @brief Checks if the robot can dropoff the package by calling DropOff()
   * on the DeliveryObject delivery.
   */
  virtual void DropOff() = 0;

  /**
   * @brief Gets the charge of the robots battery by calling 
   * GetCurCharge() on the battery.
   * 
   * @return Charge amount.
   */
  virtual int GetCharge() = 0;

  /**
   * @brief Sets the DeliveryObject* delivery to the given pointer.
   * 
   * @param delivery DeliveryObject*.
   */
  virtual void SetDeliveryObject(DeliveryObject* delivery) = 0;

  /**
   * @brief Checks if the robot has been scheduled for a delivery
   * or not.
   * 
   * @return True or false.
   */
  virtual bool IsScheduled() = 0;

  /**
   * @brief Checks if the robot has a package in its possession
   * or not.
   * 
   * @return True or false.
   */

  virtual bool DoesHavePackage() = 0;
 
};


}//namespace csci3081

#endif    // ROBOT_H_