#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class FactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
  }
  virtual void TearDown() {
    delete system;
  }

  IDeliverySystem* system;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryTest, DroneCreated) {
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

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

  delete entity;
}

TEST_F(FactoryTest, RobotCreated) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "name", "robot");
  JsonHelper::AddStringToJsonObject(obj, "type", "robot");
  JsonHelper::AddStringToJsonObject(obj, "path", "smart");
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

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

  delete entity;
}

TEST_F(FactoryTest, CustomerCreated){
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "customer");
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

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

  delete entity;
}

TEST_F(FactoryTest, PackageCreated){
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "package");
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

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

  delete entity;
}

// TEST_F(FactoryTest, ScheduleDeliveryAndUpdate){
//   picojson::object obj1 = JsonHelper::CreateJsonObject();
//   JsonHelper::AddStringToJsonObject(obj1, "type", "customer");
//   std::vector<float> position_to_add1;
//   position_to_add1.push_back(100);
//   position_to_add1.push_back(100);
//   position_to_add1.push_back(100);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
//   std::vector<float> direction_to_add1;
//   direction_to_add1.push_back(1);
//   direction_to_add1.push_back(0);
//   direction_to_add1.push_back(0);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
//   IEntity* entity1 = system->CreateEntity(obj1);
//   system->AddEntity(entity1);

//   picojson::object obj2 = JsonHelper::CreateJsonObject();
//   JsonHelper::AddStringToJsonObject(obj2, "name", "drone");
//   JsonHelper::AddStringToJsonObject(obj2, "type", "drone");
//   std::vector<float> position_to_add2;
//   position_to_add2.push_back(498.292);
//   position_to_add2.push_back(253.883);
//   position_to_add2.push_back(-228.623);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
//   std::vector<float> direction_to_add2;
//   direction_to_add2.push_back(1);
//   direction_to_add2.push_back(0);
//   direction_to_add2.push_back(0);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
//   IEntity* entity2 = system->CreateEntity(obj2);
//   system->AddEntity(entity2);
            
//   picojson::object obj3 = JsonHelper::CreateJsonObject();
//   JsonHelper::AddStringToJsonObject(obj3, "type", "package");
//   std::vector<float> position_to_add3;
//   position_to_add3.push_back(0);
//   position_to_add3.push_back(0);
//   position_to_add3.push_back(0);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
//   std::vector<float> direction_to_add3;
//   direction_to_add3.push_back(1);
//   direction_to_add3.push_back(0);
//   direction_to_add3.push_back(0);
//   JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
//   IEntity* entity3 = system->CreateEntity(obj3);
//   system->AddEntity(entity3);

//   system->ScheduleDelivery(entity3, entity1);

//   Drone* dronedDrone = dynamic_cast<Drone*>(entity2);
//   Package* packagedPackage = dynamic_cast<Package*>(entity3);
//   Customer* customeredCustomer = dynamic_cast<Customer*>(entity1);

//   ASSERT_NE(dronedDrone, nullptr);
//   ASSERT_NE(packagedPackage, nullptr);
//   ASSERT_NE(customeredCustomer, nullptr);
  
//   ASSERT_EQ(dronedDrone->IsScheduled(), false);

//   system->Update(10);

//   ASSERT_TRUE(dronedDrone->GetDirection()[0] <= -0.823 && dronedDrone->GetDirection()[0] >= -0.825 );
//   ASSERT_TRUE(dronedDrone->GetDirection()[1] <= -0.419 && dronedDrone->GetDirection()[1] >= -0.421 );
//   ASSERT_TRUE(dronedDrone->GetDirection()[2] <= 0.379 && dronedDrone->GetDirection()[2] >= 0.377 );

//   ASSERT_TRUE(dronedDrone->GetPosition()[0] <= 250.9 && dronedDrone->GetPosition()[0] >= 250.7 );
//   ASSERT_TRUE(dronedDrone->GetPosition()[1] <= 127.9 && dronedDrone->GetPosition()[1] >= 127.7 );
//   ASSERT_TRUE(dronedDrone->GetPosition()[2] <= -115.0 && dronedDrone->GetPosition()[2] >= -115.2 );

//   system->Update(10);

//   ASSERT_TRUE(dronedDrone->GetDirection()[0] <= -0.823 && dronedDrone->GetDirection()[0] >= -0.825 );
//   ASSERT_TRUE(dronedDrone->GetDirection()[1] <= -0.419 && dronedDrone->GetDirection()[1] >= -0.421 );
//   ASSERT_TRUE(dronedDrone->GetDirection()[2] <= 0.379 && dronedDrone->GetDirection()[2] >= 0.377 );

//   ASSERT_TRUE(dronedDrone->GetPosition()[0] <= 3.5 && dronedDrone->GetPosition()[0] >= 3.3 );
//   ASSERT_TRUE(dronedDrone->GetPosition()[1] <= 1.8 && dronedDrone->GetPosition()[1] >= 1.6 );
//   ASSERT_TRUE(dronedDrone->GetPosition()[2] <= -1.5 && dronedDrone->GetPosition()[2] >= -1.6 );

//   ASSERT_EQ(packagedPackage->GetPosition()[0], 0);
//   ASSERT_EQ(packagedPackage->GetPosition()[1], 0);
//   ASSERT_EQ(packagedPackage->GetPosition()[2], 0);

//   system->Update(1);

//   ASSERT_TRUE(dronedDrone->DoesHavePackage());

//   ASSERT_FLOAT_EQ(dronedDrone->GetPosition()[0], packagedPackage->GetPosition()[0]);
//   ASSERT_FLOAT_EQ(dronedDrone->GetPosition()[1]-1, packagedPackage->GetPosition()[1]);
//   ASSERT_FLOAT_EQ(dronedDrone->GetPosition()[2], packagedPackage->GetPosition()[2]);

//   system->Update(10);

//   ASSERT_FALSE(dronedDrone->DoesHavePackage());
//   ASSERT_FALSE(dronedDrone->IsScheduled());

//   delete entity1;
//   delete entity2;
//   delete entity3;
// }


}  // namespace csci3081