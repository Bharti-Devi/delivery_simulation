#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/vector2d.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <vector>


#include <iostream>

namespace csci3081 {

class Vector2DTest : public ::testing::Test {
    protected:
        virtual void SetUp(){
            v1.push_back(20.0);
            v1.push_back(50.0);
            v1.push_back(70.0);
            v2.push_back(-10.0);
            v2.push_back(0.0);
            v2.push_back(40.0);
            v3.push_back(-25.0);
            v3.push_back(0.0);
            v3.push_back(20.0);
            float x2 = -10.0;
            float z2 = 40.0;
            float x3 = -25.0;
            float z3 = 20.0;
            vector1 = new Vector2D(v1);
            vector2 = new Vector2D(x2, z2);
            vector3 = new Vector2D(x3, z3);
            v1[1] = 0;
        }

        virtual void TearDown(){
            delete vector1;
            delete vector2;
            delete vector3;
        }

        Vector2D* vector1;
        Vector2D* vector2;
        Vector2D* vector3;
        std::vector<float> v1;
        std::vector<float> v2;
        std::vector<float> v3;


};

TEST_F(Vector2DTest, ConstructorTest){
    //GetVector
    EXPECT_EQ(vector1->GetVector()[0], v1[0]);
    EXPECT_EQ(vector2->GetVector()[0], v2[0]);
    EXPECT_EQ(vector3->GetVector()[0], v3[0]);
    EXPECT_EQ(vector1->GetVector()[1], v1[1]);
    EXPECT_EQ(vector2->GetVector()[1], v2[1]);
    EXPECT_EQ(vector3->GetVector()[1], v3[1]);
    EXPECT_EQ(vector1->GetVector()[2], v1[2]);
    EXPECT_EQ(vector2->GetVector()[2], v2[2]);
    EXPECT_EQ(vector3->GetVector()[2], v3[2]);
    //GetX
    EXPECT_EQ(vector1->GetX(), v1[0]);
    EXPECT_EQ(vector2->GetX(), v2[0]);
    EXPECT_EQ(vector3->GetX(), v3[0]);
    //GetY
    EXPECT_EQ(vector1->GetY(), 0);
    EXPECT_EQ(vector2->GetY(), 0);
    EXPECT_EQ(vector3->GetY(), 0);
    //GetZ
    EXPECT_EQ(vector1->GetZ(), v1[2]);
    EXPECT_EQ(vector2->GetZ(), v2[2]);
    EXPECT_EQ(vector3->GetZ(), v3[2]);
}

TEST_F(Vector2DTest, SetterTest){
    vector1->SetVector(v2);
    vector2->SetVector(v3);
    vector3->SetVector(v1);

    EXPECT_EQ(vector1->GetVector()[0], v2[0]);
    EXPECT_EQ(vector2->GetVector()[0], v3[0]);
    EXPECT_EQ(vector3->GetVector()[0], v1[0]);
    EXPECT_EQ(vector1->GetVector()[1], v2[1]);
    EXPECT_EQ(vector2->GetVector()[1], v3[1]);
    EXPECT_EQ(vector3->GetVector()[1], v1[1]);
    EXPECT_EQ(vector1->GetVector()[2], v2[2]);
    EXPECT_EQ(vector2->GetVector()[2], v3[2]);
    EXPECT_EQ(vector3->GetVector()[2], v1[2]);

    EXPECT_EQ(vector1->GetX(), -10.0);
    EXPECT_EQ(vector2->GetY(), v3[1]);
    EXPECT_EQ(vector3->GetZ(), v1[2]);

    vector1->SetX(100.02);
    vector3->SetZ(-235.001);

    EXPECT_TRUE((vector1->GetX() >= 100.019) && (vector1->GetX() <= 100.021));
    EXPECT_EQ(vector1->GetY(), 0);
    EXPECT_TRUE((vector3->GetZ() >= -235.0011) && (vector3->GetZ() <= -235.0009));
    v2[0] = 100.02;
    v1[2] = -235.001;
    EXPECT_EQ(vector1->GetVector()[0], v2[0]);
    EXPECT_EQ(vector2->GetVector()[0], v3[0]);
    EXPECT_EQ(vector3->GetVector()[0], v1[0]);
    EXPECT_EQ(vector1->GetVector()[1], v2[1]);
    EXPECT_EQ(vector2->GetVector()[1], v3[1]);
    EXPECT_EQ(vector3->GetVector()[1], v1[1]);
    EXPECT_EQ(vector1->GetVector()[2], v2[2]);
    EXPECT_EQ(vector2->GetVector()[2], v3[2]);
    EXPECT_EQ(vector3->GetVector()[2], v1[2]);
}

TEST_F(Vector2DTest, MagnitudeAndNormalizeTest){
    std::vector<float> v1u;
    float magnitude = sqrt(20.0*20.0 + 70.0 * 70.0);
    v1u.push_back(20.0/magnitude);
    v1u.push_back(0);
    v1u.push_back(70.0/magnitude);
    std::vector<float> v2u;
    magnitude = sqrt(-10.0*-10.0 + 40.0 * 40.0);
    v2u.push_back(-10.0/magnitude);
    v2u.push_back(0);
    v2u.push_back(40.0/magnitude);
    std::vector<float> v3u;
    magnitude = sqrt(-25.0*-25.0 + 20.0 * 20.0);
    v3u.push_back(-25.0/magnitude);
    v3u.push_back(0);
    v3u.push_back(20.0/magnitude);

    EXPECT_TRUE((vector1->Magnitude() >= 72.8009) && (vector1->Magnitude() <= 72.8012));
    EXPECT_TRUE((vector2->Magnitude() >= 41.2309) && (vector2->Magnitude() <= 41.2311));
    EXPECT_TRUE((vector3->Magnitude() >= 32.0155) && (vector3->Magnitude() <= 32.0157));

    vector1->Normalize();
    vector2->Normalize();
    vector3->Normalize();

    EXPECT_EQ(vector1->GetVector()[0], v1u[0]);
    EXPECT_EQ(vector2->GetVector()[0], v2u[0]);
    EXPECT_EQ(vector3->GetVector()[0], v3u[0]);
    EXPECT_EQ(vector1->GetVector()[1], v1u[1]);
    EXPECT_EQ(vector2->GetVector()[1], v2u[1]);
    EXPECT_EQ(vector3->GetVector()[1], v3u[1]);
    EXPECT_EQ(vector1->GetVector()[2], v1u[2]);
    EXPECT_EQ(vector2->GetVector()[2], v2u[2]);
    EXPECT_EQ(vector3->GetVector()[2], v3u[2]);
}


}//namespace csci3081
