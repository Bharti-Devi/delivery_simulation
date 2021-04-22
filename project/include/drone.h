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
   * @brief Constructor: sets up Drone by instantiating all of its values.
   */
  Drone(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj, int id, DeliveryManager* manager, Pathfinder* strategy);
  /**
   * @brief Destructor: deletes all allocated values.
   */
  ~Drone();
  /**
  * @brief Gets the id of the drone.
  *
  * @return Id value.
  */
  int GetId() const;
  /**
  * @brief Gets the name of the drone.
  *
  * @return Name value.
  */
  const std::string& GetName();
  /**
  * @brief Gets the position of the drone.
  *
  * @return Position vector.
  */
  const std::vector<float>& GetPosition() const;
  /**
  * @brief Gets the direction of the drone.
  *
  * @return Direction vector.
  */
  const std::vector<float>& GetDirection() const;
  /**
  * @brief Gets the position of the drone as a Vector3D object pointer.
  *
  * @return Vector3D for position.
  */

  Vector3D GetVectorPosition();
  /**
  * @brief Returns the direction of the drone as a Vector3D object pointer.
  *
  * @return Vector3D for direction.
  */
  Vector3D GetVectorDirection();
  /**
  * @brief Gets the radius of the drone.
  *
  * @return Radius value.
  */
  float GetRadius() const;
  /**
  * @brief Gets the version of the drone.
  *
  * @return Version value.
  */
  int GetVersion() const;
  /**
  * @brief Checks if the drone is dynamic or not.
  *
  * @return True or false.
  */
  bool IsDynamic() const;
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
  void Update(float dt);
  /**
   * @brief Checks if the drone can pickup the package by calling PickUp()
   * on the DeliveryObject delivery.
   */
  void PickUp();
  /**
   * @brief Checks if the drone can dropoff the package by calling DropOff()
   * on the DeliveryObject delivery.
   */
  void DropOff();
  /**
   * @brief Gets the charge of the drones battery by calling 
   * GetCurCharge() on the battery.
   *
   * @return Battery charge value.
   */
  int GetCharge();
  /**
   * @brief Sets the DeliveryObject* delivery to the given pointer.
   * 
   * @param delivery DeliveryObject*.
   */
  void SetDeliveryObject(DeliveryObject* delivery);
  /**
   * @brief Checks if the drone has been scheduled for a delivery
   * or not.
   * 
   * @return True or false.
   */
  bool IsScheduled();
  /**
   * @brief Checks if the drone has a package in its possession
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

}  // namespace csci3081

#endif    // DRONE_H_