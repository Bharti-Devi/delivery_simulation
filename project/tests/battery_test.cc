#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/battery.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

class BatteryTest : public ::testing::Test {
    protected:
        virtual void SetUp(){
        }

        virtual void TearDown(){
        }
};

TEST_F(BatteryTest, DefaultConstructorTest){
    Battery b1 = Battery();
    EXPECT_EQ(b1.GetCurCharge(), 10000);
    EXPECT_EQ(b1.GetIsEmpty(), false);
}

TEST_F(BatteryTest, CapacityConstructorTest){
    Battery b1 = Battery(10.0);
    EXPECT_EQ(b1.GetCurCharge(), 10.0);
    EXPECT_EQ(b1.GetIsEmpty(), false);
}

TEST_F(BatteryTest, SetChargeTests){
    Battery b1 = Battery();
    Battery b2 = Battery();
    Battery b3 = Battery();
    Battery b4 = Battery(5000.0);
    Battery b5 = Battery();

    b1.SetCurCharge(3005);
    b2.SetCurCharge(0);
    b3.SetCurCharge(-15000);
    b4.SetCurCharge(10000);
    b5.SetCurCharge(15000);
    EXPECT_EQ(b1.GetCurCharge(), 3005);
    EXPECT_EQ(b2.GetCurCharge(), 0);
    EXPECT_EQ(b3.GetCurCharge(), 0);
    EXPECT_EQ(b4.GetCurCharge(), 5000);
    EXPECT_EQ(b5.GetCurCharge(), 10000);
    EXPECT_EQ(b1.GetIsEmpty(), false);
    EXPECT_EQ(b2.GetIsEmpty(), true);
    EXPECT_EQ(b3.GetIsEmpty(), true);
    EXPECT_EQ(b4.GetIsEmpty(), false);
    EXPECT_EQ(b5.GetIsEmpty(), false);
}

TEST_F(BatteryTest, DepleteChargeTests){
    Battery b1 = Battery();
    Battery b2 = Battery();
    Battery b3 = Battery();
    Battery b4 = Battery(5000.0);
    Battery b5 = Battery();

    b1.DepleteCharge(1567);
    b2.DepleteCharge(0);
    b3.DepleteCharge(-257);
    b4.DepleteCharge(5000);
    b5.DepleteCharge(15000);
    EXPECT_EQ(b1.GetCurCharge(), 8433);
    EXPECT_EQ(b2.GetCurCharge(), 10000);
    EXPECT_EQ(b3.GetCurCharge(), 10000);
    EXPECT_EQ(b4.GetCurCharge(), 0);
    EXPECT_EQ(b5.GetCurCharge(), 0);
    EXPECT_EQ(b1.GetIsEmpty(), false);
    EXPECT_EQ(b2.GetIsEmpty(), false);
    EXPECT_EQ(b3.GetIsEmpty(), false);
    EXPECT_EQ(b4.GetIsEmpty(), true);
    EXPECT_EQ(b5.GetIsEmpty(), true);
}

TEST_F(BatteryTest, ChargeTests){
    Battery b1 = Battery();
    Battery b2 = Battery();
    Battery b3 = Battery(5000.0);
    Battery b4 = Battery();
    Battery b5 = Battery();
    b1.SetCurCharge(0);
    b2.SetCurCharge(0);
    b3.SetCurCharge(0);
    b4.SetCurCharge(0);
    b5.SetCurCharge(0);
    
    b1.Charge(3721);
    b2.Charge(-1000);
    b3.Charge(10000);
    b4.Charge(0);
    b5.Charge(15000);
    EXPECT_EQ(b1.GetCurCharge(), 3721);
    EXPECT_EQ(b2.GetCurCharge(), 0);
    EXPECT_EQ(b3.GetCurCharge(), 5000);
    EXPECT_EQ(b4.GetCurCharge(), 0);
    EXPECT_EQ(b5.GetCurCharge(), 10000);
    EXPECT_EQ(b1.GetIsEmpty(), false);
    EXPECT_EQ(b2.GetIsEmpty(), true);
    EXPECT_EQ(b3.GetIsEmpty(), false);
    EXPECT_EQ(b4.GetIsEmpty(), true);
    EXPECT_EQ(b5.GetIsEmpty(), false);
}

}//namespace csci3081