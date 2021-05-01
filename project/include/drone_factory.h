/**
 *@file drone_factory.h
 */
#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include "entity_base.h"
#include "delivery_manager.h"
#include "pathfinder_factory.h"

namespace csci3081 {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief A class that creates Drones, created to assist other classes in the creation of Drones.
*/
class DroneFactory : public IEntityFactory{
    public:
        /**
        * @brief Constructor: sets up DroneFactory by instantiating all of its values.
        */
        DroneFactory(DeliveryManager* manager, PathfinderFactory* pathfactory);
        /**
        * @brief Creates a Drone entity and returns it as an IEntity* object.
        * 
        * Creates a Drone object by reading the information given from obj.
        * It then returns the Drone object as an IEntity*.
        * 
        * @param obj JSON object.
        * 
        * @return IEntity* object.
        */
        IEntity* CreateEntity(const picojson::object& obj);
    private:
        int entityCount;
        DeliveryManager* manager;
        PathfinderFactory* pathfactory;
};
    
}//namespace csci3081

#endif    // DRONE_FACTORY_H_