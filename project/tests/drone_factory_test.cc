#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/drone_factory.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "simple_delivery_manager.h"
#include "../include/parabolic_pathfinder_factory.h"


#include <iostream>

namespace csci3081 {

class DroneFactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    manager = new SimpleDeliveryManager();
    system = new DroneFactory(manager, new ParabolicPathfinderFactory());
  }
  virtual void TearDown() {
    delete system;
    delete manager;
  }

   IEntityFactory* system;
   SimpleDeliveryManager* manager;
};

TEST_F(DroneFactoryTest, DroneCreated){
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "name", "drone");
  JsonHelper::AddStringToJsonObject(obj, "type", "drone");
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

  delete entity;
}

}//namespace csci3081
