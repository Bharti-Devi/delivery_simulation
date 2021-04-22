#include "drone_factory.h"
#include "json_helper.h"
#include "drone.h"


namespace csci3081 {

DroneFactory::DroneFactory(DeliveryManager* manager, PathfinderFactory* pathfactory)    {
    entityCount = 0;
    this->manager = manager;
    this->pathfactory = pathfactory;
}

IEntity* DroneFactory::CreateEntity(const picojson::object& obj)    {
    entityCount++;

    if (JsonHelper::GetString(obj,"type")!= "drone")    {
        return NULL;
    }

    std::string pathType;
    if (JsonHelper::ContainsKey(obj, "path")) {
        pathType = JsonHelper::GetString(obj, "path");
    }
    else {
        pathType = "smart";
    }

    std::vector<float> position = JsonHelper::GetStdFloatVector(obj, "position");
    std::vector<float> direction = JsonHelper::GetStdFloatVector(obj, "direction");
    
    return new Drone(position, direction, obj, entityCount-1, manager, pathfactory->CreatePathfinder(pathType));
}

}//namespace csci3081