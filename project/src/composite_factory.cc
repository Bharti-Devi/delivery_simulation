#include "composite_factory.h"
#include "json_helper.h"

namespace csci3081 {

CompositeFactory::CompositeFactory()    {
    entityCount = 0;
}

CompositeFactory::~CompositeFactory()   {
    for (int i = 0; i < ComponentFactories.size(); i++) {
        delete ComponentFactories[i];
    }
}

IEntity* CompositeFactory::CreateEntity(const picojson::object& obj)    {
    IEntity* returnValue;
    IEntity* tempval;
    //Iterates over every factory to ensure Id's are updated correctly
    //rather then returning the first correct value.
    for (int i = 0; i < ComponentFactories.size(); i++) {
        tempval = ComponentFactories[i]->CreateEntity(obj);
        
        if (tempval != NULL)    {
            returnValue = tempval;
            tempval = NULL;
        }
    }

    return returnValue;
    
}

void CompositeFactory::AddFactory(IEntityFactory* factory)  {
    ComponentFactories.push_back(factory);
}

}//namespace csci3081