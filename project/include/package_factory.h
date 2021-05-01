/**
 *@file package_factory.h
 */
#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

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
* @brief A class that creates Packages, created to assist other classes in the creation of Packages.
* 
*/
class PackageFactory : public IEntityFactory{
    public:
        /**
        * @brief Constructor: sets up PackageFactory by instantiating all of its values.
        */
        PackageFactory();

        /**
        * @brief Creates a package entity and returns it as an IEntity* object.
        * 
        * Creates a Package object by reading the information given from obj.
        * It then returns the Package object as an IEntity*.
        * 
        * @param obj JSON object.
        * 
        * @return IEntity* object.
        */
        IEntity* CreateEntity(const picojson::object& obj);
        
    private:
        int entityCount;
};
    
}//namespace csci3081

#endif    // PACKAGE_FACTORY_H_