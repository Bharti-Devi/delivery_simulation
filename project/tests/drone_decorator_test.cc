#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/basic_drone.h"
#include "../include/drone_battery_decorator.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "simple_delivery_manager.h"
#include "parabolic_pathfinder.h"

namespace csci3081 {

class DroneDecoratorTest: public ::testing::Test {
  protected:
    virtual void SetUp(){
      manager = new SimpleDeliveryManager();
      picojson::object obj1 = JsonHelper::CreateJsonObject();
      //Object 1
      JsonHelper::AddStringToJsonObject(obj1, "name", "drone");
      JsonHelper::AddStringToJsonObject(obj1, "type", "drone");
      position_to_add1.push_back(498.292);
      position_to_add1.push_back(253.883);
      position_to_add1.push_back(-228.623);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
      direction_to_add1.push_back(1);
      direction_to_add1.push_back(0);
      direction_to_add1.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
      entity1 = new BasicDrone(position_to_add1, direction_to_add1, obj1, 0, manager, new ParabolicPathfinder());
      
      decoratedDrone = new DroneBatteryDecorator(entity1);
    }

    virtual void TearDown(){
    //   delete decoratedDrone;
      delete manager;

    }

    std::vector<float> position_to_add1;
    std::vector<float> position_to_add2;
    std::vector<float> position_to_add3;
    std::vector<float> direction_to_add1;
    std::vector<float> direction_to_add2;
    std::vector<float> direction_to_add3;
    Drone* entity1;
    Drone* decoratedDrone;
    SimpleDeliveryManager* manager;
    const IGraph* graph;
};

TEST_F(DroneDecoratorTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity1->GetId(),0);
  //GetPosition
  EXPECT_EQ(entity1->GetPosition()[0], decoratedDrone->GetPosition()[0]);
  EXPECT_EQ(entity1->GetPosition()[1], decoratedDrone->GetPosition()[1]);
  EXPECT_EQ(entity1->GetPosition()[2], decoratedDrone->GetPosition()[2]);
  //GetDirection
  EXPECT_EQ(entity1->GetDirection()[0], decoratedDrone->GetDirection()[0]);
  EXPECT_EQ(entity1->GetDirection()[1], decoratedDrone->GetDirection()[1]);
  EXPECT_EQ(entity1->GetDirection()[2], decoratedDrone->GetDirection()[2]);
  //GetVectorPosition
  EXPECT_EQ(entity1->GetVectorPosition().GetX(), decoratedDrone->GetVectorPosition().GetX());
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), decoratedDrone->GetVectorPosition().GetY());
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), decoratedDrone->GetVectorPosition().GetZ());
  //GetVectorDirection
  EXPECT_EQ(entity1->GetVectorDirection().GetX(), decoratedDrone->GetVectorDirection().GetX());
  EXPECT_EQ(entity1->GetVectorDirection().GetY(), decoratedDrone->GetVectorDirection().GetY());
  EXPECT_EQ(entity1->GetVectorDirection().GetZ(), decoratedDrone->GetVectorDirection().GetZ());
  //GetRadius
  EXPECT_EQ(entity1->GetRadius(), decoratedDrone->GetRadius());
  //GetCharge
  EXPECT_EQ(entity1->GetCharge(), decoratedDrone->GetCharge());
  //GetName
  EXPECT_EQ(entity1->GetName(), decoratedDrone->GetName());
  //IsDynamic
  EXPECT_EQ(entity1->IsDynamic(), decoratedDrone->IsDynamic());
  //GetVersion
  EXPECT_EQ(entity1->GetVersion(), decoratedDrone->GetVersion());
  //IsScheduled
  EXPECT_EQ(entity1->IsScheduled(), decoratedDrone->IsScheduled());
  //DoesHavePackage
  EXPECT_EQ(entity1->DoesHavePackage(), decoratedDrone->DoesHavePackage());
}

//Update And SetDeliveryObject are both dependent on IGraph so tests for these two functions are not included.

}//namespace csci3081