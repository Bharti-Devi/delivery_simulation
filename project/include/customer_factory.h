/**
 *@file customer_factory.h
 */
#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

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
* @brief A class that creates Customers, created to assist other classes in the 
* creation of Customers.
*/
class CustomerFactory : public IEntityFactory{
    public:
        /**
        * @brief Constructor: sets up CustomerFactory by instantiating all of its values.
        */
        CustomerFactory();
        /**
        * @brief Creates a Customer entity and returns it as an IEntity*
        * 
        * Creates a Customer object by reading the information given from obj.
        * It then returns the Customer object as an IEntity*.
        * 
        * @param obj Input object with information about the Entity.
        * 
        * @return IEntity* object.
        */
        IEntity* CreateEntity(const picojson::object& obj);
    private:
        int entityCount;
};
    
}//namespace csci3081

#endif    // CUSTOMER_FACTORY_H_