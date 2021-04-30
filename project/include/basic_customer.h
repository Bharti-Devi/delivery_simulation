/**
 *@file basic_customer.h
 */
#ifndef BASIC_CUSTOMER_H_
#define BASIC_CUSTOMER_H_

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
 * @brief The main class for Customers. Storing and reporting their information.
 *
 * Stores information on a specific Customer object.
 */
class BasicCustomer : public Customer {

public:
  /**
   * @brief Constructor: sets up Customer by instantiating all of its values.
   */
  BasicCustomer(std::vector<float> position, std::vector<float> direction, const picojson::object& obj, int id);

  /**
   * @brief Destructor
   */
  ~BasicCustomer();

  int GetId() const override;

  const std::string& GetName() override;

  const std::vector<float>& GetPosition() const override;

  const std::vector<float>& GetDirection() const override;

  Vector3D GetVectorPosition() override;

  Vector3D GetVectorDirection() override;

  float GetRadius() const override;

  bool GetHavePackage() override;

  int GetVersion() const override;

  bool IsDynamic() const override;

  void RecievePackage() override;

  /**
   * @brief Returns Drone to track.
   */
  Package* GetPackage() override;

  /**
   * @brief Sets Drone to track.
   * 
   * @param drone Drone.
   */
  void SetPackage(Package* package) override;

private:
    std::vector<float> position;
    std::vector<float> direction;
    Vector3D* vectorPosition;
    Vector3D* vectorDirection;
    std::string name;
    bool havePackage;
    Package* package;
    int id;
    
};

}  // namespace csci3081

#endif    // CUSTOMER_H_