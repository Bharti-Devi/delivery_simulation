/**
 * @file delivery_simulation.h
 */
#ifndef DELIVERY_SIMULATION_H_
#define DELIVERY_SIMULATION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include "composite_pathfinder_factory.h"
#include "composite_factory.h"
#include "drone.h"
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the facade for the delivery system
 *
 * This class will delegate operations for the whole drone delivery system.
 * See the documentation for IDeliverySystem for more information.
 */

// DO NOT MODIFY (unless you really know what you are doing)
class DeliverySimulation : public IDeliverySystem {
 public:
  /**
   * @brief Constructor: this can do any setup your system necessitates.
   */
  DeliverySimulation();

  /// Desconstructor: This should free any memory that your program uses.
  ~DeliverySimulation();
  /**
  * @brief creates an entity and returns it.
  *
  * Using the CompositeFactory it creates the specified entity based on the given
  * picojson object. 
  * 
  * @param picojson::object& val
  *
  * @return IEntity*.
  */
  IEntity* CreateEntity(const picojson::object& val);
  /**
  * @brief Adds a factory to the composite factories factory list
  *
  * Calls CompositeFactory::AddFactory() to add a factory to the 
  * composite factories list
  * 
  * @param picojson::object& val
  *
  * @return IEntity*.
  */
  void AddFactory(IEntityFactory* factory);
  /**
  * @brief Adds a IEntity to the entities_ list
  *
  * 
  * @param picojson::object& val
  *
  * @return IEntity*.
  */
  void AddEntity(IEntity* entity);

  /**
  This function should simply store a reference to the IGraph* somewhere.
  The IGraph contains useful functions such as the GetPath function which can 
  be used to get a path from one position to another.
  */
  void SetGraph(const IGraph* graph);
  /**
  * @brief Creates a delivery object and stores it in an
  * available Drone
  *
  * 
  * @param IEntity* package, IEntity* dest.
  *
  * @return No return value.
  */
  void ScheduleDelivery(IEntity* package, IEntity* dest);

  /** Observer functions will not be used in iteration1 */
  void AddObserver(IEntityObserver* observer);

  /** Observer functions will not be used in iteration1 */
  void RemoveObserver(IEntityObserver* observer);

  /**
  GetEntities should return all entities that have been ADDED to the system
  */
  const std::vector<IEntity*>& GetEntities() const;

  /**
  * @brief Calls Update() on ever drone object in the
  * entities list
  * 
  * @param float dt
  *
  * @return No return value.
  */
  void Update(float dt);

  /**
   * @brief You do not need to worry about this function
   * 
   * This function takes care of turning json into function calls of your system.
   * YOU DO NOT NEED TO IMPLEMENT THIS
   *it is already implemented in the delivery_simulation.cc we have provided.
   */
  void RunScript(const picojson::array& script, IEntitySystem* system) const;

 private:
  int idCount = 0;
  CompositeFactory* factory;
  std::vector<IEntity*> entities_;
  DeliveryManager* manager;
  const IGraph* graph;
  std::vector<IEntityObserver*> observers_;
  CompositePathfinderFactory* pathfactory;
};

}  // namespace csci3081


#endif  // DELIVERY_SIMULATION_H_
