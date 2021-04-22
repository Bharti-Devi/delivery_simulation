#include "robot_factory.h"
#include "json_helper.h"
#include "robot.h"

namespace csci3081 {

RobotFactory::RobotFactory(DeliveryManager* manager, PathfinderFactory* pathfactory)    {
    entityCount = 0;
    this->manager = manager;
    this->pathfactory = pathfactory;
}

IEntity* RobotFactory::CreateEntity(const picojson::object& obj)    {
    entityCount++;

    if (JsonHelper::GetString(obj,"type")!= "robot")    {
        return NULL;
    }

    std::vector<float> position = JsonHelper::GetStdFloatVector(obj, "position");
    std::vector<float> direction = JsonHelper::GetStdFloatVector(obj, "direction");
    
    return new Robot(position, direction, obj, entityCount-1, manager, pathfactory->CreatePathfinder("smart"));
}

}//namespace csci3081