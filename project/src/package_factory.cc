#include "package_factory.h"
#include "json_helper.h"
#include "basic_package.h"

namespace csci3081 {

PackageFactory::PackageFactory()	{
    entityCount = 0;
}

IEntity* PackageFactory::CreateEntity(const picojson::object& obj)	{
    entityCount++;

    if (JsonHelper::GetString(obj,"type") != "package")	{
        return NULL;
    }

    std::vector<float> position = JsonHelper::GetStdFloatVector(obj, "position");
    std::vector<float> direction = JsonHelper::GetStdFloatVector(obj, "direction");
    
    return new BasicPackage(position, direction, obj, entityCount-1);
}

}//namespace csci3081