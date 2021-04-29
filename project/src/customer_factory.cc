#include "customer_factory.h"
#include "json_helper.h"
#include "customer.h"

namespace csci3081 {

CustomerFactory::CustomerFactory()	{
    entityCount = 0;
}

IEntity* CustomerFactory::CreateEntity(const picojson::object& obj)	{
    entityCount++;

    if (JsonHelper::GetString(obj,"type")!= "customer")	{
        return NULL;
    }
    
    std::vector<float> position = JsonHelper::GetStdFloatVector(obj, "position");
    std::vector<float> direction = JsonHelper::GetStdFloatVector(obj, "direction");
    
    return new Customer(position, direction, obj, entityCount-1);
}

}//namespace csci3081
