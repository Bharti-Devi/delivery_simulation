#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/composite_factory.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "package_factory.h"
#include "drone_factory.h"
#include "robot_factory.h"
#include "customer_factory.h"
#include "simple_delivery_manager.h"
#include "../include/parabolic_pathfinder_factory.h"
#include "../include/smart_pathfinder_factory.h"


#include <iostream>

namespace csci3081 {

class CompositeFactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = new CompositeFactory();
  }
  virtual void TearDown() {
    delete system;
  }

   CompositeFactory* system;
};

TEST_F(CompositeFactoryTest, AddAndUseFactory){
  system->AddFactory(new DroneFactory(new SimpleDeliveryManager(), new ParabolicPathfinderFactory()));
  system->AddFactory(new RobotFactory(new SimpleDeliveryManager(), new SmartPathfinderFactory()));
  system->AddFactory(new CustomerFactory());
  system->AddFactory(new PackageFactory());

  picojson::object obj1 = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj1, "type", "customer");
  std::vector<float> position_to_add1;
  position_to_add1.push_back(498.292);
  position_to_add1.push_back(253.883);
  position_to_add1.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
  std::vector<float> direction_to_add1;
  direction_to_add1.push_back(1);
  direction_to_add1.push_back(0);
  direction_to_add1.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
  IEntity* entity1 = system->CreateEntity(obj1);

  //Checks that the returned entity is not NULL
  ASSERT_NE(entity1, nullptr) << "The entity created";
  ASSERT_FLOAT_EQ(entity1->GetPosition()[0], position_to_add1[0]);
  ASSERT_FLOAT_EQ(entity1->GetPosition()[1], position_to_add1[1]);
  ASSERT_FLOAT_EQ(entity1->GetPosition()[2], position_to_add1[2]);
  ASSERT_FLOAT_EQ(entity1->GetDirection()[0], direction_to_add1[0]);
  ASSERT_FLOAT_EQ(entity1->GetDirection()[1], direction_to_add1[1]);
  ASSERT_FLOAT_EQ(entity1->GetDirection()[2], direction_to_add1[2]);

  EXPECT_EQ("customer", entity1->GetName());

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(entity1->GetDetails()).serialize(), picojson::value(obj1).serialize());

  picojson::object obj2 = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj2, "name", "drone");
  JsonHelper::AddStringToJsonObject(obj2, "type", "drone");
  JsonHelper::AddStringToJsonObject(obj2, "path", "parabolic");
  std::vector<float> position_to_add2;
  position_to_add2.push_back(498.292);
  position_to_add2.push_back(253.883);
  position_to_add2.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
  std::vector<float> direction_to_add2;
  direction_to_add2.push_back(1);
  direction_to_add2.push_back(0);
  direction_to_add2.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
  IEntity* entity2 = system->CreateEntity(obj2);

  //Checks that the returned entity is not NULL
  ASSERT_NE(entity2, nullptr) << "The entity created";
  ASSERT_FLOAT_EQ(entity2->GetPosition()[0], position_to_add2[0]);
  ASSERT_FLOAT_EQ(entity2->GetPosition()[1], position_to_add2[1]);
  ASSERT_FLOAT_EQ(entity2->GetPosition()[2], position_to_add2[2]);
  ASSERT_FLOAT_EQ(entity2->GetDirection()[0], direction_to_add2[0]);
  ASSERT_FLOAT_EQ(entity2->GetDirection()[1], direction_to_add2[1]);
  ASSERT_FLOAT_EQ(entity2->GetDirection()[2], direction_to_add2[2]);

  EXPECT_EQ("drone", entity2->GetName());

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(entity2->GetDetails()).serialize(), picojson::value(obj2).serialize());

  picojson::object obj3 = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj3, "type", "package");
  std::vector<float> position_to_add3;
  position_to_add3.push_back(498.292);
  position_to_add3.push_back(253.883);
  position_to_add3.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
  std::vector<float> direction_to_add3;
  direction_to_add3.push_back(1);
  direction_to_add3.push_back(0);
  direction_to_add3.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
  IEntity* entity3 = system->CreateEntity(obj3);

  //Checks that the returned entity is not NULL
  ASSERT_NE(entity3, nullptr) << "The entity created";
  ASSERT_FLOAT_EQ(entity3->GetPosition()[0], position_to_add3[0]);
  ASSERT_FLOAT_EQ(entity3->GetPosition()[1], position_to_add3[1]);
  ASSERT_FLOAT_EQ(entity3->GetPosition()[2], position_to_add3[2]);
  ASSERT_FLOAT_EQ(entity3->GetDirection()[0], direction_to_add3[0]);
  ASSERT_FLOAT_EQ(entity3->GetDirection()[1], direction_to_add3[1]);
  ASSERT_FLOAT_EQ(entity3->GetDirection()[2], direction_to_add3[2]);

  EXPECT_EQ("package", entity3->GetName());

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(entity3->GetDetails()).serialize(), picojson::value(obj3).serialize());

  picojson::object obj4 = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj4, "name", "robot");
  JsonHelper::AddStringToJsonObject(obj4, "type", "robot");
  JsonHelper::AddStringToJsonObject(obj4, "path", "smart");
  std::vector<float> position_to_add4;
  position_to_add4.push_back(498.292);
  position_to_add4.push_back(253.883);
  position_to_add4.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj4, "position", position_to_add4);
  std::vector<float> direction_to_add4;
  direction_to_add4.push_back(1);
  direction_to_add4.push_back(0);
  direction_to_add4.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj4, "direction", direction_to_add4);
  IEntity* entity4 = system->CreateEntity(obj4);

  //Checks that the returned entity is not NULL
  ASSERT_NE(entity4, nullptr) << "The entity created";
  ASSERT_FLOAT_EQ(entity4->GetPosition()[0], position_to_add4[0]);
  ASSERT_FLOAT_EQ(entity4->GetPosition()[1], position_to_add4[1]);
  ASSERT_FLOAT_EQ(entity4->GetPosition()[2], position_to_add4[2]);
  ASSERT_FLOAT_EQ(entity4->GetDirection()[0], direction_to_add4[0]);
  ASSERT_FLOAT_EQ(entity4->GetDirection()[1], direction_to_add4[1]);
  ASSERT_FLOAT_EQ(entity4->GetDirection()[2], direction_to_add4[2]);

  EXPECT_EQ("robot", entity4->GetName());

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(entity4->GetDetails()).serialize(), picojson::value(obj4).serialize());

  delete entity1;
  delete entity2;
  delete entity3;
  delete entity4;
}

}//namespace csci3081