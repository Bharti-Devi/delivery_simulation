#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/basic_customer.h"
#include "../include/customer_color_decorator.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081 {

class CustomerColorDecoratorTest: public ::testing::Test {
  protected:
    virtual void SetUp(){
      picojson::object obj1 = JsonHelper::CreateJsonObject();
      //Object 1
      JsonHelper::AddStringToJsonObject(obj1, "name", "customer");
      JsonHelper::AddStringToJsonObject(obj1, "type", "customer");
      position_to_add1.push_back(498.292);
      position_to_add1.push_back(253.883);
      position_to_add1.push_back(-228.623);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
      direction_to_add1.push_back(1);
      direction_to_add1.push_back(0);
      direction_to_add1.push_back(0);
      JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
      entity1 = new BasicCustomer(position_to_add1, direction_to_add1, obj1, 0);
      
      decoratedCustomer = new CustomerColorDecorator(entity1);
    }

    virtual void TearDown(){
      delete decoratedCustomer;
    }

    std::vector<float> position_to_add1;
    std::vector<float> direction_to_add1;
    Customer* entity1;
    Customer* decoratedCustomer;
};

TEST_F(CustomerColorDecoratorTest, ConstructorTest){
  //GetID
  EXPECT_EQ(entity1->GetId(),0);
  //GetPosition
  EXPECT_EQ(entity1->GetPosition()[0], decoratedCustomer->GetPosition()[0]);
  EXPECT_EQ(entity1->GetPosition()[1], decoratedCustomer->GetPosition()[1]);
  EXPECT_EQ(entity1->GetPosition()[2], decoratedCustomer->GetPosition()[2]);
  //GetDirection
  EXPECT_EQ(entity1->GetDirection()[0], decoratedCustomer->GetDirection()[0]);
  EXPECT_EQ(entity1->GetDirection()[1], decoratedCustomer->GetDirection()[1]);
  EXPECT_EQ(entity1->GetDirection()[2], decoratedCustomer->GetDirection()[2]);
  //GetVectorPosition
  EXPECT_EQ(entity1->GetVectorPosition().GetX(), decoratedCustomer->GetVectorPosition().GetX());
  EXPECT_EQ(entity1->GetVectorPosition().GetY(), decoratedCustomer->GetVectorPosition().GetY());
  EXPECT_EQ(entity1->GetVectorPosition().GetZ(), decoratedCustomer->GetVectorPosition().GetZ());
  //GetVectorDirection
  EXPECT_EQ(entity1->GetVectorDirection().GetX(), decoratedCustomer->GetVectorDirection().GetX());
  EXPECT_EQ(entity1->GetVectorDirection().GetY(), decoratedCustomer->GetVectorDirection().GetY());
  EXPECT_EQ(entity1->GetVectorDirection().GetZ(), decoratedCustomer->GetVectorDirection().GetZ());
  //GetRadius
  EXPECT_EQ(entity1->GetRadius(), decoratedCustomer->GetRadius());
  //GetName
  EXPECT_EQ(entity1->GetName(), decoratedCustomer->GetName());
  //IsDynamic
  EXPECT_EQ(entity1->IsDynamic(), decoratedCustomer->IsDynamic());
  //GetVersion
  EXPECT_EQ(entity1->GetVersion(), decoratedCustomer->GetVersion());
}

TEST_F(CustomerColorDecoratorTest, RecievePackageTest){
  //test entity
  EXPECT_EQ(entity1->GetHavePackage(), decoratedCustomer->GetHavePackage());
  entity1->RecievePackage();
  EXPECT_EQ(entity1->GetHavePackage(), decoratedCustomer->GetHavePackage());
 
}


}//namespace csci3081