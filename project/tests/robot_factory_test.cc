#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/robot_factory.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "simple_delivery_manager.h"
#include "smart_pathfinder_factory.h"

#include <iostream>

namespace csci3081 {

class RobotFactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    manager = new SimpleDeliveryManager();
    system = new RobotFactory(manager, new SmartPathfinderFactory());
  }
  virtual void TearDown() {
    delete system;
    delete manager;
  }

   IEntityFactory* system;
   SimpleDeliveryManager* manager;
};

TEST_F(RobotFactoryTest, RobotCreated){
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "name", "robot");
  JsonHelper::AddStringToJsonObject(obj, "type", "robot");
  JsonHelper::AddStringToJsonObject(obj, "path", "parabolic");
  std::vector<float> position_to_add;
  position_to_add.push_back(498.292);
  position_to_add.push_back(253.883);
  position_to_add.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
  std::vector<float> direction_to_add;
  direction_to_add.push_back(1);
  direction_to_add.push_back(0);
  direction_to_add.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
  IEntity* entity = system->CreateEntity(obj);

  //Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(entity->GetDetails()).serialize(), picojson::value(obj).serialize());
  delete entity;
}

}//namespace csci3081
