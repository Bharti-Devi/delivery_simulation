/**
 *@file composite_factory.h
 */
#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include "entity_base.h"

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for EntityCreation. Storing other factories in itself to use for
 * creation of any type.
 * 
 * Useful for implementing new IEntity types as it does not need to be changed to create them as it
 * Uses the composite structure.
 */
class CompositeFactory : public IEntityFactory {
    public:
        /**
        * @brief Constructor: sets up CompositeFactory by instantiating all of its values.
        */
        CompositeFactory();
        /**
        * @brief Destructor: deletes all manually allocated data.
        * 
        * Calls delete on all of the factories added to it.
        */
        ~CompositeFactory();
        /**
        * @brief Creates an entity of the same type as the given picojson::object&
        * 
        * Loops through every factory in the CompositeFactory's factory list, ComponentFactories.
        * As it loops through it calls CreateEntity on each of them passing in obj
        * It then checks if it returned the correct kind of entity that was asked for
        * continues the loop and then returns the correct one. It is important that it loops
        * through every factory so that all of their entityCounts are the same so that each
        * object gets a unique ID.
        * 
        * @param obj Object needed to create an Entity.
        * 
        * @return IEntity* object.
        *
        */
        IEntity* CreateEntity(const picojson::object& obj);
        /**
        * @brief Adds a factory to the ComponentFactories vector for later use in the object.
        * 
        * @param factory IEntityFactory* to add.
        */
        void AddFactory(IEntityFactory* factory);
    private:
        int entityCount;
        std::vector<IEntityFactory*> ComponentFactories;
};
    
}//namespace csci3081

#endif    // COMPOSITE_FACTORY_H_