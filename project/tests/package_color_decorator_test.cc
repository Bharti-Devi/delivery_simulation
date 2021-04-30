#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/basic_package.h"
#include "../include/package_color_decorator.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081 {

class PackageColorDecoratorTest: public ::testing::Test {
  protected:
    virtual void SetUp(){
      picojson::object obj1 = JsonHelper::CreateJsonObject();
      //Object 1
      JsonHelper::AddStringToJsonObject(obj1, "name", "package");
      JsonHelper::AddStringToJsonObject(obj1, "type", "package");
      position_to_add1.push_back(498.292);
      position_to_add1.push_back(253.883);
      position_to_add1.push_back(-228.623);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
      direction_to_add1.push_back(1);
      direction_to_add1.push_back(0);
      direction_to_add1.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
      entity1 = new BasicPackage(position_to_add1, direction_to_add1, obj1, 0);
      
      decoratedPackage = new PackageColorDecorator(entity1);
    }

    virtual void TearDown(){
      delete decoratedPackage;
    }

    std::vector<float> position_to_add1;
    std::vector<float> direction_to_add1;
    Package* entity1;
    Package* decoratedPackage;
};

TEST_F(PackageColorDecoratorTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity1->GetId(),0);
  //GetPosition
  EXPECT_EQ(entity1->GetPosition()[0], decoratedPackage->GetPosition()[0]);
  EXPECT_EQ(entity1->GetPosition()[1], decoratedPackage->GetPosition()[1]);
  EXPECT_EQ(entity1->GetPosition()[2], decoratedPackage->GetPosition()[2]);
  //GetDirection
  EXPECT_EQ(entity1->GetDirection()[0], decoratedPackage->GetDirection()[0]);
  EXPECT_EQ(entity1->GetDirection()[1], decoratedPackage->GetDirection()[1]);
  EXPECT_EQ(entity1->GetDirection()[2], decoratedPackage->GetDirection()[2]);
  //GetVectorPosition
  EXPECT_EQ(entity1->GetVectorPosition().GetX(), decoratedPackage->GetVectorPosition().GetX());
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), decoratedPackage->GetVectorPosition().GetY());
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), decoratedPackage->GetVectorPosition().GetZ());
  //GetVectorDirection
  EXPECT_EQ(entity1->GetVectorDirection().GetX(), decoratedPackage->GetVectorDirection().GetX());
  EXPECT_EQ(entity1->GetVectorDirection().GetY(), decoratedPackage->GetVectorDirection().GetY());
  EXPECT_EQ(entity1->GetVectorDirection().GetZ(), decoratedPackage->GetVectorDirection().GetZ());
  //GetRadius
  EXPECT_EQ(entity1->GetRadius(), decoratedPackage->GetRadius());
  //GetName
  EXPECT_EQ(entity1->GetName(), decoratedPackage->GetName());
  //IsDynamic
  EXPECT_EQ(entity1->IsDynamic(), decoratedPackage->IsDynamic());
  //GetVersion
  EXPECT_EQ(entity1->GetVersion(), decoratedPackage->GetVersion());
}

TEST_F(PackageColorDecoratorTest, SettersTest){
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


  decoratedPackage->SetPosition(position_to_change1);

  EXPECT_EQ(entity1->GetPosition()[0], decoratedPackage->GetPosition()[0]);
  EXPECT_EQ(entity1->GetPosition()[1], decoratedPackage->GetPosition()[1]);
  EXPECT_EQ(entity1->GetPosition()[2], decoratedPackage->GetPosition()[2]);

  EXPECT_EQ(entity1->GetVectorPosition().GetX(), decoratedPackage->GetVectorPosition().GetX());
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), decoratedPackage->GetVectorPosition().GetY());
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), decoratedPackage->GetVectorPosition().GetZ());

}

TEST_F(PackageColorDecoratorTest, TravelAndDeliveredTest){

  decoratedPackage->SetTraveling(true);
  EXPECT_EQ(entity1->GetTravelStatus(), decoratedPackage->GetTravelStatus());
  EXPECT_EQ(entity1->GetDeliveryStatus(), decoratedPackage->GetDeliveryStatus());
  decoratedPackage->SetTraveling(false);
  EXPECT_EQ(entity1->GetTravelStatus(), decoratedPackage->GetTravelStatus());
  EXPECT_EQ(entity1->GetDeliveryStatus(), decoratedPackage->GetDeliveryStatus());
  decoratedPackage->SetTraveling(true);
  decoratedPackage->Delivered();
  EXPECT_EQ(entity1->GetTravelStatus(), decoratedPackage->GetTravelStatus());
  EXPECT_EQ(entity1->GetDeliveryStatus(), decoratedPackage->GetDeliveryStatus());
}

}//namespace csci3081