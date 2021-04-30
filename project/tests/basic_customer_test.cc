#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/basic_customer.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class BasicCustomerTest: public ::testing::Test {
  protected:
      virtual void SetUp(){
        picojson::object obj = JsonHelper::CreateJsonObject();
        picojson::object obj2 = JsonHelper::CreateJsonObject();
        picojson::object obj3 = JsonHelper::CreateJsonObject();
        //Object 1
        JsonHelper::AddStringToJsonObject(obj, "type", "customer");
        position_to_add.push_back(498.292);
        position_to_add.push_back(253.883);
        position_to_add.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
        direction_to_add.push_back(1);
        direction_to_add.push_back(0);
        direction_to_add.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
        entity = new BasicCustomer(position_to_add, direction_to_add, obj, 0);
        //Object 2
        JsonHelper::AddStringToJsonObject(obj2, "type", "customer");
        position_to_add2.push_back(200.1);
        position_to_add2.push_back(77.0);
        position_to_add2.push_back(123);
        JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
        direction_to_add2.push_back(0);
        direction_to_add2.push_back(1);
        direction_to_add2.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
        entity2 = new BasicCustomer(position_to_add2, direction_to_add2, obj2, 1);
        //Object 3
        JsonHelper::AddStringToJsonObject(obj3, "type", "customer");
        position_to_add3.push_back(0);
        position_to_add3.push_back(0);
        position_to_add3.push_back(1);
        JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
        direction_to_add3.push_back(30);
        direction_to_add3.push_back(263.32);
        direction_to_add3.push_back(12.01);
        JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
        entity3 = new BasicCustomer(position_to_add3, direction_to_add3, obj3, 2);
      }

      virtual void TearDown(){
        delete entity;
        delete entity2;
        delete entity3;
      }

      std::vector<float> position_to_add;
      std::vector<float> position_to_add2;
      std::vector<float> position_to_add3;
      std::vector<float> direction_to_add;
      std::vector<float> direction_to_add2;
      std::vector<float> direction_to_add3;
      Customer* entity;
      Customer* entity2;
      Customer* entity3;
};

TEST_F(BasicCustomerTest, ConstructorTest){
  //GetId
  EXPECT_EQ(entity->GetId(),0);
  EXPECT_EQ(entity2->GetId(),1);
  EXPECT_EQ(entity3->GetId(),2);
  //GetName
  EXPECT_EQ(entity->GetName(), "customer");
  EXPECT_EQ(entity2->GetName(), "customer");
  EXPECT_EQ(entity3->GetName(), "customer");
  //GetHavePackage
  EXPECT_EQ(entity->GetHavePackage(),false);
  EXPECT_EQ(entity2->GetHavePackage(), false);
  EXPECT_EQ(entity3->GetHavePackage(), false);
  //GetPosition
  EXPECT_EQ(entity->GetPosition()[0], position_to_add[0]);
  EXPECT_EQ(entity2->GetPosition()[0], position_to_add2[0]);
  EXPECT_EQ(entity3->GetPosition()[0], position_to_add3[0]);
  EXPECT_EQ(entity->GetPosition()[1], position_to_add[1]);
  EXPECT_EQ(entity2->GetPosition()[1], position_to_add2[1]);
  EXPECT_EQ(entity3->GetPosition()[1], position_to_add3[1]);
  EXPECT_EQ(entity->GetPosition()[2], position_to_add[2]);
  EXPECT_EQ(entity2->GetPosition()[2], position_to_add2[2]);
  EXPECT_EQ(entity3->GetPosition()[2], position_to_add3[2]);
  //GetDirection
  EXPECT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  EXPECT_EQ(entity2->GetDirection()[0], direction_to_add2[0]);
  EXPECT_EQ(entity3->GetDirection()[0], direction_to_add3[0]);
  EXPECT_EQ(entity->GetDirection()[2], direction_to_add[2]);
  EXPECT_EQ(entity2->GetDirection()[2], direction_to_add2[2]);
  EXPECT_EQ(entity3->GetDirection()[2], direction_to_add3[2]);
  EXPECT_EQ(entity->GetDirection()[2], direction_to_add[2]);
  EXPECT_EQ(entity2->GetDirection()[2], direction_to_add2[2]);
  EXPECT_EQ(entity3->GetDirection()[2], direction_to_add3[2]);
  //GetVectorPosition
  EXPECT_EQ(entity->GetVectorPosition().GetX(), position_to_add[0]);
  EXPECT_EQ(entity2->GetVectorPosition().GetX(), position_to_add2[0]);
  EXPECT_EQ(entity3->GetVectorPosition().GetX(), position_to_add3[0]);
  EXPECT_EQ(entity->GetVectorPosition().GetY(), position_to_add[1]);
  EXPECT_EQ(entity2->GetVectorPosition().GetY(), position_to_add2[1]);
  EXPECT_EQ(entity3->GetVectorPosition().GetY(), position_to_add3[1]);
  EXPECT_EQ(entity->GetVectorPosition().GetZ(), position_to_add[2]);
  EXPECT_EQ(entity2->GetVectorPosition().GetZ(), position_to_add2[2]);
  EXPECT_EQ(entity3->GetVectorPosition().GetZ(), position_to_add3[2]);
  //GetVectorDirection
  EXPECT_EQ(entity->GetVectorDirection().GetX(), direction_to_add[0]);
  EXPECT_EQ(entity2->GetVectorDirection().GetX(), direction_to_add2[0]);
  EXPECT_EQ(entity3->GetVectorDirection().GetX(), direction_to_add3[0]);
  EXPECT_EQ(entity->GetVectorDirection().GetX(), direction_to_add[0]);
  EXPECT_EQ(entity2->GetVectorDirection().GetY(), direction_to_add2[1]);
  EXPECT_EQ(entity3->GetVectorDirection().GetY(), direction_to_add3[1]);
  EXPECT_EQ(entity->GetVectorDirection().GetZ(), direction_to_add[2]);
  EXPECT_EQ(entity2->GetVectorDirection().GetZ(), direction_to_add2[2]);
  EXPECT_EQ(entity3->GetVectorDirection().GetZ(), direction_to_add3[2]);
  //GetRadius
  EXPECT_FLOAT_EQ(entity->GetRadius(), 1.0);
  EXPECT_FLOAT_EQ(entity2->GetRadius(), 1.0);
  EXPECT_FLOAT_EQ(entity3->GetRadius(), 1.0);
  //GetVersion
  EXPECT_FLOAT_EQ(entity->GetVersion(), 0.0);
  EXPECT_FLOAT_EQ(entity2->GetVersion(), 0.0);
  EXPECT_FLOAT_EQ(entity3->GetVersion(), 0.0);
  //IsDynamic
  EXPECT_EQ(entity->IsDynamic(), true);
  EXPECT_EQ(entity2->IsDynamic(), true);
  EXPECT_EQ(entity3->IsDynamic(), true);

}

TEST_F(BasicCustomerTest, RecievePackageTest){
  //test entity
  EXPECT_EQ(entity->GetHavePackage(), false);
  entity->RecievePackage();
  EXPECT_EQ(entity->GetHavePackage(), true);
  //test entity2
  EXPECT_EQ(entity2->GetHavePackage(), false);
  entity2->RecievePackage();
  EXPECT_EQ(entity2->GetHavePackage(), true);
  //test entity3
  EXPECT_EQ(entity3->GetHavePackage(), false);
  entity3->RecievePackage();
  EXPECT_EQ(entity3->GetHavePackage(), true);
}

}//namespace csci3081