#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/robot.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "simple_delivery_manager.h"
#include "smart_pathfinder.h"

namespace csci3081 {

class RobotTest: public ::testing::Test {
  protected:
    virtual void SetUp(){
      manager = new SimpleDeliveryManager();
      picojson::object obj1 = JsonHelper::CreateJsonObject();
      picojson::object obj2 = JsonHelper::CreateJsonObject();
      picojson::object obj3 = JsonHelper::CreateJsonObject();
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
      entity1 = new Robot(position_to_add1, direction_to_add1, obj1, 0, manager, new SmartPathfinder(graph));
      //Object 2
      JsonHelper::AddStringToJsonObject(obj2, "name", "robot");
      JsonHelper::AddStringToJsonObject(obj2, "type", "robot");
      position_to_add2.push_back(200.1);
      position_to_add2.push_back(77.0);
      position_to_add2.push_back(123);
      JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
      direction_to_add2.push_back(0);
      direction_to_add2.push_back(1);
      direction_to_add2.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
      entity2 = new Robot(position_to_add2, direction_to_add2, obj2, 1, manager, new SmartPathfinder(graph));
      //Object 3
      JsonHelper::AddStringToJsonObject(obj3, "name", "robot");
      JsonHelper::AddStringToJsonObject(obj3, "type", "robot");
      position_to_add3.push_back(0);
      position_to_add3.push_back(0);
      position_to_add3.push_back(1);
      JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
      direction_to_add3.push_back(30);
      direction_to_add3.push_back(263.32);
      direction_to_add3.push_back(12.01);
      JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
      entity3 = new Robot(position_to_add3, direction_to_add3, obj3, 2, manager, new SmartPathfinder(graph));
    }

    virtual void TearDown(){
      delete entity1;
      delete entity2;
      delete entity3;
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
    Robot* entity2;
    Robot* entity3;
    SimpleDeliveryManager* manager;
    const IGraph* graph;
};

TEST_F(RobotTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity1->GetId(),0);
  EXPECT_EQ(entity2->GetId(),1);
  EXPECT_EQ(entity3->GetId(),2);
  //GetPosition
  EXPECT_EQ(entity1->GetPosition()[0], position_to_add1[0]);
  EXPECT_EQ(entity2->GetPosition()[0], position_to_add2[0]);
  EXPECT_EQ(entity3->GetPosition()[0], position_to_add3[0]);
  EXPECT_EQ(entity1->GetPosition()[1], position_to_add1[1]);
  EXPECT_EQ(entity2->GetPosition()[1], position_to_add2[1]);
  EXPECT_EQ(entity3->GetPosition()[1], position_to_add3[1]);
  EXPECT_EQ(entity1->GetPosition()[2], position_to_add1[2]);
  EXPECT_EQ(entity2->GetPosition()[2], position_to_add2[2]);
  EXPECT_EQ(entity3->GetPosition()[2], position_to_add3[2]);
  //GetDirection
  EXPECT_EQ(entity1->GetDirection()[0], direction_to_add1[0]);
  EXPECT_EQ(entity2->GetDirection()[0], direction_to_add2[0]);
  EXPECT_EQ(entity3->GetDirection()[0], direction_to_add3[0]);
  EXPECT_EQ(entity1->GetDirection()[1], direction_to_add1[1]);
  EXPECT_EQ(entity2->GetDirection()[1], direction_to_add2[1]);
  EXPECT_EQ(entity3->GetDirection()[1], direction_to_add3[1]);
  EXPECT_EQ(entity1->GetDirection()[2], direction_to_add1[2]);
  EXPECT_EQ(entity2->GetDirection()[2], direction_to_add2[2]);
  EXPECT_EQ(entity3->GetDirection()[2], direction_to_add3[2]);
  //GetVectorPosition
  EXPECT_EQ(entity1->GetVectorPosition().GetX(), position_to_add1[0]);
  EXPECT_EQ(entity2->GetVectorPosition().GetX(), position_to_add2[0]);
  EXPECT_EQ(entity3->GetVectorPosition().GetX(), position_to_add3[0]);
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), position_to_add1[1]);
  EXPECT_EQ(entity2->GetVectorPosition().GetY(), position_to_add2[1]);
  EXPECT_EQ(entity3->GetVectorPosition().GetY(), position_to_add3[1]);
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), position_to_add1[2]);
  EXPECT_EQ(entity2->GetVectorPosition().GetZ(), position_to_add2[2]);
  EXPECT_EQ(entity3->GetVectorPosition().GetZ(), position_to_add3[2]);
  //GetVectorDirection
  EXPECT_EQ(entity1->GetVectorDirection().GetX(), direction_to_add1[0]);
  EXPECT_EQ(entity2->GetVectorDirection().GetX(), direction_to_add2[0]);
  EXPECT_EQ(entity3->GetVectorDirection().GetX(), direction_to_add3[0]);
  EXPECT_EQ(entity1->GetVectorDirection().GetY(), direction_to_add1[1]);
  EXPECT_EQ(entity2->GetVectorDirection().GetY(), direction_to_add2[1]);
  EXPECT_EQ(entity3->GetVectorDirection().GetY(), direction_to_add3[1]);
  EXPECT_EQ(entity1->GetVectorDirection().GetZ(), direction_to_add1[2]);
  EXPECT_EQ(entity2->GetVectorDirection().GetZ(), direction_to_add2[2]);
  EXPECT_EQ(entity3->GetVectorDirection().GetZ(), direction_to_add3[2]);
  //GetRadius
  EXPECT_EQ(entity1->GetRadius(), 1.0);
  EXPECT_EQ(entity2->GetRadius(), 1.0);
  EXPECT_EQ(entity3->GetRadius(), 1.0);
  //GetCharge
  EXPECT_EQ(entity1->GetCharge(), 10000);
  EXPECT_EQ(entity2->GetCharge(), 10000);
  EXPECT_EQ(entity3->GetCharge(), 10000);
  //GetName
  EXPECT_EQ(entity1->GetName(),"robot");
  EXPECT_EQ(entity2->GetName(),"robot");
  EXPECT_EQ(entity3->GetName(),"robot");
  //IsDynamic
  EXPECT_EQ(entity1->IsDynamic(), true);
  EXPECT_EQ(entity2->IsDynamic(), true);
  EXPECT_EQ(entity3->IsDynamic(), true);
  //GetVersion
  EXPECT_EQ(entity1->GetVersion(), 0.0);
  EXPECT_EQ(entity2->GetVersion(), 0.0);
  EXPECT_EQ(entity3->GetVersion(), 0.0);
  //IsScheduled
  EXPECT_EQ(entity1->IsScheduled(), false);
  EXPECT_EQ(entity2->IsScheduled(), false);
  EXPECT_EQ(entity3->IsScheduled(), false);
  //DoesHavePackage
  EXPECT_EQ(entity1->DoesHavePackage(), false);
  EXPECT_EQ(entity2->DoesHavePackage(), false);
  EXPECT_EQ(entity3->DoesHavePackage(), false);
}

//Update And SetDeliveryObject are both dependent on IGraph so tests for these two functions are not included.

}//namespace csci3081