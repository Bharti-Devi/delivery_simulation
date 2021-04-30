#include "customer_factory.h"
#include "json_helper.h"
#include "basic_customer.h"
#include "customer_color_decorator.h"

namespace csci3081 {

CustomerFactory::CustomerFactory()	{
    entityCount = 0;
}

IEntity* CustomerFactory::CreateEntity(const picojson::object& obj)	{
    entityCount++;

    if (JsonHelper::GetString(obj, "type")!= "customer")	{
        return NULL;
    }
    
    std::vector<float> position = JsonHelper::GetStdFloatVector(obj, "position");
    std::vector<float> direction = JsonHelper::GetStdFloatVector(obj, "direction");
    
    return new CustomerColorDecorator(new BasicCustomer(position, direction, obj, entityCount-1));
}

}//namespace csci3081
