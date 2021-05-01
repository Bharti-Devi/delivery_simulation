#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/basic_robot.h"
#include "../include/robot_battery_decorator.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "simple_delivery_manager.h"
#include "smart_pathfinder.h"

namespace csci3081 {

class RobotDecoratorTest: public ::testing::Test {
  protected:
    virtual void SetUp(){
      manager = new SimpleDeliveryManager();
      picojson::object obj1 = JsonHelper::CreateJsonObject();
      //Object 1
      JsonHelper::AddStringToJsonObject(obj1, "name", "robot");
      JsonHelper::AddStringToJsonObject(obj1, "type", "robot");
      position_to_add1.push_back(498.292);
      position_to_add1.push_back(253.883);
      position_to_add1.push_back(-228.623);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
      direction_to_add1.push_back(1);
      direction_to_add1.push_back(0);
      direction_to_add1.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
      entity1 = new BasicRobot(position_to_add1, direction_to_add1, obj1, 0, manager, new SmartPathfinder(graph));
      
      decoratedRobot = new RobotBatteryDecorator(entity1);
    }

    virtual void TearDown(){
      delete decoratedRobot;
      delete manager;
      delete graph;
    }

    std::vector<float> position_to_add1;
    std::vector<float> position_to_add2;
    std::vector<float> position_to_add3;
    std::vector<float> direction_to_add1;
    std::vector<float> direction_to_add2;
    std::vector<float> direction_to_add3;
    Robot* entity1;
    Robot* decoratedRobot;
    SimpleDeliveryManager* manager;
    const IGraph* graph;
};

TEST_F(RobotDecoratorTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity1->GetId(),0);
  //GetPosition
  EXPECT_EQ(entity1->GetPosition()[0], decoratedRobot->GetPosition()[0]);
  EXPECT_EQ(entity1->GetPosition()[1], decoratedRobot->GetPosition()[1]);
  EXPECT_EQ(entity1->GetPosition()[2], decoratedRobot->GetPosition()[2]);
  //GetDirection
  EXPECT_EQ(entity1->GetDirection()[0], decoratedRobot->GetDirection()[0]);
  EXPECT_EQ(entity1->GetDirection()[1], decoratedRobot->GetDirection()[1]);
  EXPECT_EQ(entity1->GetDirection()[2], decoratedRobot->GetDirection()[2]);
  //GetVectorPosition
  EXPECT_EQ(entity1->GetVectorPosition().GetX(), decoratedRobot->GetVectorPosition().GetX());
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), decoratedRobot->GetVectorPosition().GetY());
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), decoratedRobot->GetVectorPosition().GetZ());
  //GetVectorDirection
  EXPECT_EQ(entity1->GetVectorDirection().GetX(), decoratedRobot->GetVectorDirection().GetX());
  EXPECT_EQ(entity1->GetVectorDirection().GetY(), decoratedRobot->GetVectorDirection().GetY());
  EXPECT_EQ(entity1->GetVectorDirection().GetZ(), decoratedRobot->GetVectorDirection().GetZ());
  //GetRadius
  EXPECT_EQ(entity1->GetRadius(), decoratedRobot->GetRadius());
  //GetCharge
  EXPECT_EQ(entity1->GetCharge(), decoratedRobot->GetCharge());
  //GetName
  EXPECT_EQ(entity1->GetName(), decoratedRobot->GetName());
  //IsDynamic
  EXPECT_EQ(entity1->IsDynamic(), decoratedRobot->IsDynamic());
  //GetVersion
  EXPECT_EQ(entity1->GetVersion(), decoratedRobot->GetVersion());
  //IsScheduled
  EXPECT_EQ(entity1->IsScheduled(), decoratedRobot->IsScheduled());
  //DoesHavePackage
  EXPECT_EQ(entity1->DoesHavePackage(), decoratedRobot->DoesHavePackage());
}

//Update And SetDeliveryObject are both dependent on IGraph so tests for these two functions are not included.

}//namespace csci3081