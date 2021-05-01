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
 * @brief The main class for BasicCustomers. Storing and reporting their information.
 *
 * Stores information on a specific Customer object.
 *
 * Overrides Customer.
 */
class BasicCustomer : public Customer {

public:
  /**
   * @brief Constructor: Sets up BasicCustomer by instantiating all of its values.
   */
  BasicCustomer(std::vector<float> position, std::vector<float> direction, const picojson::object& obj, int id);

  /**
   * @brief Destructor: Deletes vectors from class.
   */
  ~BasicCustomer();

  /**
   * @brief Gets customer Id.
   *
   * @return Id.
   */
  int GetId() const override;

  /**
   * @brief Gets customer name.
   *
   * @return Name.
   */
  const std::string& GetName() override;

  /**
   * @brief Gets customer position.
   *
   * @return Position.
   */
  const std::vector<float>& GetPosition() const override;

  /**
   * @brief Gets customer direction.
   *
   * @return Direction.
   */
  const std::vector<float>& GetDirection() const override;

  /**
   * @brief Gets 3D vector position.
   *
   * @return 3D vector position.
   */
  Vector3D GetVectorPosition() override;

  /**
   * @brief Gets 3D vector direction.
   *
   * @return 3D vector direction.
   */
  Vector3D GetVectorDirection() override;

  /**
   * @brief Gets customer radius.
   *
   * @return Radius.
   */
  float GetRadius() const override;

  /**
   * @brief Checks if customer has package.
   *
   * @return True or false.
   */
  bool GetHavePackage() override;

  /**
   * @brief Gets customer version.
   *
   * @return Version.
   */
  int GetVersion() const override;

  /**
   * @brief Checks if customer is moving.
   *
   * @return True or false.
   */
  bool IsDynamic() const override;

  /**
   * @brief Indicates that customer received package.
   */
  void RecievePackage() override;

private:
    std::vector<float> position;
    std::vector<float> direction;
    Vector3D* vectorPosition;
    Vector3D* vectorDirection;
    std::string name;
    bool havePackage;
    int id;
    
};

}  // namespace csci3081

#endif    // CUSTOMER_H_