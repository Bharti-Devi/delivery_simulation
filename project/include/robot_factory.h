/**
 *@file robot_factory.h
 */
#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include "pathfinder_factory.h"
#include "entity_base.h"
#include "delivery_manager.h"

namespace csci3081 {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 * @brief A class that creates Robots, created to assist other classes in the creation of Robots.
 */
class RobotFactory : public IEntityFactory{
    public:
        /**
         * @brief Constructor: sets up RobotFactory by instantiating all of its values.
         */
        RobotFactory(DeliveryManager* manager, PathfinderFactory* pathfactory);

        /**
         * @brief Creates a Robot entity and returns it as an IEntity* object.
         * 
         * Creates a Robot object by reading the information given from obj.
         * It then returns the Robot object as an IEntity*.
         * 
         * @param obj JSON object.
         * 
         * @return IEntity* object.
         *
         */
        IEntity* CreateEntity(const picojson::object& obj);
        
    private:
        int entityCount;
        DeliveryManager* manager;
        PathfinderFactory* pathfactory;
};
    
}//namespace csci3081

#endif    // ROBOT_FACTORY_H_