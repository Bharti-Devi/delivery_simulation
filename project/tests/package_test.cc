#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/package.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class PackageTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
      picojson::object obj = JsonHelper::CreateJsonObject();
      picojson::object obj2 = JsonHelper::CreateJsonObject();
      picojson::object obj3 = JsonHelper::CreateJsonObject();
      //Object
      JsonHelper::AddStringToJsonObject(obj, "type", "package");
      position_to_add.push_back(498.292);
      position_to_add.push_back(253.883);
      position_to_add.push_back(-228.623);
      JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
      direction_to_add.push_back(1);
      direction_to_add.push_back(0);
      direction_to_add.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
      entity = new Package(position_to_add, direction_to_add, obj, 0);
      //Object 2
      JsonHelper::AddStringToJsonObject(obj2, "type", "package");
      position_to_add2.push_back(200.1);
      position_to_add2.push_back(77.0);
      position_to_add2.push_back(123);
      JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
      direction_to_add2.push_back(0);
      direction_to_add2.push_back(1);
      direction_to_add2.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
      entity2 = new Package(position_to_add2, direction_to_add2, obj2, 1);
      //Object 3
      JsonHelper::AddStringToJsonObject(obj2, "type", "package");
      position_to_add3.push_back(0);
      position_to_add3.push_back(0);
      position_to_add3.push_back(1);
      JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
      direction_to_add3.push_back(30);
      direction_to_add3.push_back(263.32);
      direction_to_add3.push_back(12.01);
      JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
      entity3 = new Package(position_to_add3, direction_to_add3, obj3, 2);
    }
    virtual void TearDown() {
      delete entity;
      delete entity2;
      delete entity3;
    }
    std::vector<float> position_to_add;
    std::vector<float> direction_to_add;
    std::vector<float> position_to_add2;
    std::vector<float> direction_to_add2;
    std::vector<float> position_to_add3;
    std::vector<float> direction_to_add3;
    Package* entity;
    Package* entity2;
    Package* entity3;

  
};

TEST_F(PackageTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity->GetId(),0);
  EXPECT_EQ(entity2->GetId(),1);
  EXPECT_EQ(entity3->GetId(),2);
  //GetDeliveryStatus
  EXPECT_EQ(entity->GetDeliveryStatus(),false);
  EXPECT_EQ(entity2->GetDeliveryStatus(),false);
  EXPECT_EQ(entity3->GetDeliveryStatus(), false);
  //GetTravelStatus
  EXPECT_EQ(entity->GetTravelStatus(),false);
  EXPECT_EQ(entity2->GetTravelStatus(),false);
  EXPECT_EQ(entity3->GetTravelStatus(), false);
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
  EXPECT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  EXPECT_EQ(entity2->GetDirection()[1], direction_to_add2[1]);
  EXPECT_EQ(entity3->GetDirection()[1], direction_to_add3[1]);
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
  EXPECT_EQ(entity->GetVectorDirection().GetY(), direction_to_add[1]);
  EXPECT_EQ(entity2->GetVectorDirection().GetY(), direction_to_add2[1]);
  EXPECT_EQ(entity3->GetVectorDirection().GetY(), direction_to_add3[1]);
  EXPECT_EQ(entity->GetVectorDirection().GetZ(), direction_to_add[2]);
  EXPECT_EQ(entity2->GetVectorDirection().GetZ(), direction_to_add2[2]);
  EXPECT_EQ(entity3->GetVectorDirection().GetZ(), direction_to_add3[2]);
  //GetName
  EXPECT_EQ(entity->GetName(), "package");
  EXPECT_EQ(entity2->GetName(), "package");
  EXPECT_EQ(entity3->GetName(), "package");
}

TEST_F(PackageTest, SettersTest){
  //Extra Vectors for Testing.
  std::vector<float> position_to_change1;
  position_to_change1.push_back(0);
  position_to_change1.push_back(0);
  position_to_change1.push_back(0);
  std::vector<float> position_to_change2;
  position_to_change2.push_back(-24.56);
  position_to_change2.push_back(-263.32);
  position_to_change2.push_back(-12.01);
  std::vector<float> position_to_change3;
  position_to_change3.push_back(302.2034);
  position_to_change3.push_back(263.32245687);
  position_to_change3.push_back(12.01);

  EXPECT_EQ(entity->GetPosition()[0], position_to_add[0] );
  EXPECT_EQ(entity2->GetPosition()[0], position_to_add2[0] );
  EXPECT_EQ(entity->GetPosition()[1], position_to_add[1] );
  EXPECT_EQ(entity2->GetPosition()[1], position_to_add2[1] );
  EXPECT_EQ(entity->GetPosition()[2], position_to_add[2] );
  EXPECT_EQ(entity2->GetPosition()[2], position_to_add2[2] );
  
  EXPECT_EQ(entity->GetVectorPosition().GetX(), position_to_add[0] );
  EXPECT_EQ(entity2->GetVectorPosition().GetX(), position_to_add2[0] );
  EXPECT_EQ(entity->GetVectorPosition().GetY(), position_to_add[1] );
  EXPECT_EQ(entity2->GetVectorPosition().GetY(), position_to_add2[1] );
  EXPECT_EQ(entity->GetVectorPosition().GetZ(), position_to_add[2] );
  EXPECT_EQ(entity2->GetVectorPosition().GetZ(), position_to_add2[2] );

  entity2->SetPosition(position_to_change1);

  EXPECT_EQ(entity->GetPosition()[0], position_to_add[0]);
  EXPECT_EQ(entity2->GetPosition()[0], position_to_change1[0]);
  EXPECT_EQ(entity->GetPosition()[1], position_to_add[1]);
  EXPECT_EQ(entity2->GetPosition()[1], position_to_change1[1]);
  EXPECT_EQ(entity->GetPosition()[2], position_to_add[2]);
  EXPECT_EQ(entity2->GetPosition()[2], position_to_change1[2]);

  EXPECT_EQ(entity->GetVectorPosition().GetX(), position_to_add[0]);
  EXPECT_EQ(entity2->GetVectorPosition().GetX(), position_to_change1[0]);
  EXPECT_EQ(entity->GetVectorPosition().GetY(), position_to_add[1]);
  EXPECT_EQ(entity2->GetVectorPosition().GetY(), position_to_change1[1]);
  EXPECT_EQ(entity->GetVectorPosition().GetZ(), position_to_add[2]);
  EXPECT_EQ(entity2->GetVectorPosition().GetZ(), position_to_change1[2]);

  entity->SetPosition(position_to_change2);
  entity2->SetPosition(position_to_change3);

  EXPECT_EQ(entity->GetPosition()[0], position_to_change2[0]);
  EXPECT_EQ(entity2->GetPosition()[0], position_to_change3[0]);
  EXPECT_EQ(entity->GetPosition()[1], position_to_change2[1]);
  EXPECT_EQ(entity2->GetPosition()[1], position_to_change3[1]);
  EXPECT_EQ(entity->GetPosition()[2], position_to_change2[2]);
  EXPECT_EQ(entity2->GetPosition()[2], position_to_change3[2]);

  EXPECT_EQ(entity->GetVectorPosition().GetX(), position_to_change2[0]);
  EXPECT_EQ(entity2->GetVectorPosition().GetX(), position_to_change3[0]);
  EXPECT_EQ(entity->GetVectorPosition().GetY(), position_to_change2[1]);
  EXPECT_EQ(entity2->GetVectorPosition().GetY(), position_to_change3[1]);
  EXPECT_EQ(entity->GetVectorPosition().GetZ(), position_to_change2[2]);
  EXPECT_EQ(entity2->GetVectorPosition().GetZ(), position_to_change3[2]);
}

TEST_F(PackageTest, TravelAndDeliveredTest){

  entity->SetTraveling(true);
  EXPECT_EQ(entity->GetTravelStatus(), true);
  EXPECT_EQ(entity->GetDeliveryStatus(), false);
  entity->SetTraveling(false);
  EXPECT_EQ(entity->GetTravelStatus(), false);
  EXPECT_EQ(entity->GetDeliveryStatus(), false);
  entity->SetTraveling(true);
  entity->Delivered();
  EXPECT_EQ(entity->GetTravelStatus(), false);
  EXPECT_EQ(entity->GetDeliveryStatus(), true);
}

}//namespace csci3081