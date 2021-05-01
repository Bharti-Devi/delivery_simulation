#include "robot_factory.h"
#include "json_helper.h"
#include "basic_robot.h"
#include "robot_battery_decorator.h"

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
    
    return new RobotBatteryDecorator(new BasicRobot(position, direction, obj, entityCount-1, manager, pathfactory->CreatePathfinder("smart")));
}

}//namespace csci3081