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
   * @brief Constructor: sets up Robot by instantiating all of its values.
   */
  Robot(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, 
        int id, DeliveryManager* manager, Pathfinder* strategy);
  
  /**
   * @brief Destructor: deletes all allocated values.
   */
  ~Robot();

  /**
  * @brief Gets the id of the Robot.
  *
  * @return Id value.
  */
  int GetId() const;

  /**
  * @brief Gets the name of the Robot object.
  *
  * @return Name value.
  */
  const std::string& GetName();

  /**
  * @brief Gets the position of the Robot.
  *
  * @return Position vector.
  */
  const std::vector<float>& GetPosition() const;
  
  /**
  * @brief Gets the direction of the Robot.
  *
  * @return Direction vector.
  */
  const std::vector<float>& GetDirection() const;

  /**
  * @brief Gets the position of the robot as a Vector2D object pointer.
  *
  * @return Position Vector3D.
  */
  Vector3D GetVectorPosition();

  /**
  * @brief Gets the direction of the robot as a Vector2D object pointer.
  *
  * @return Direction Vector3D.
  */
  Vector3D GetVectorDirection();

  /**
  * @brief Gets the radius of the robot.
  *
  * @return Radius value.
  */
  float GetRadius() const;

  /**
  * @brief Gets the version of the robot.
  *
  * @return Version number.
  */
  int GetVersion() const;

  /**
  * @brief Checks if the robot is dynamic or not.
  *
  * @return True or false.
  */
  bool IsDynamic() const;

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
  void Update(float dt);

  /**
   * @brief Checks if the Robot can pickup the package by calling PickUp()
   * on the DeliveryObject delivery.
   */
  void PickUp();

  /**
   * @brief Checks if the robot can dropoff the package by calling DropOff()
   * on the DeliveryObject delivery.
   */
  void DropOff();

  /**
   * @brief Gets the charge of the robots battery by calling 
   * GetCurCharge() on the battery.
   * 
   * @return Charge amount.
   */
  int GetCharge();

  /**
   * @brief Sets the DeliveryObject* delivery to the given pointer.
   * 
   * @param delivery DeliveryObject*.
   */
  void SetDeliveryObject(DeliveryObject* delivery);

  /**
   * @brief Checks if the robot has been scheduled for a delivery
   * or not.
   * 
   * @return True or false.
   */
  bool IsScheduled();

  /**
   * @brief Checks if the robot has a package in its possession
   * or not.
   * 
   * @return True or false.
   */

  bool DoesHavePackage();

  private:
    std::vector<float> position;
    std::vector<float> direction;
    std::vector<float> destination;
    Vector3D* vectorPosition;
    Vector3D* vectorDirection;
    DeliveryObject* delivery;
    Battery battery;
    std::string name;
    float speed;
    int id;
    bool hasPackage;
    bool scheduled;
    DeliveryManager* manager;
    std::vector< std::vector<float> > packagePath;
    std::vector< std::vector<float> > customerPath;
    Pathfinder* strategy;
 
};


}//namespace csci3081

#endif    // ROBOT_H_