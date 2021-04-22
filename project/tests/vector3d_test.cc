#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/vector3d.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <vector>


#include <iostream>

namespace csci3081 {

class Vector3DTest : public ::testing::Test {
    protected:
        virtual void SetUp(){
            v1.push_back(20.0);
            v1.push_back(50.0);
            v1.push_back(70.0);
            v2.push_back(-10.0);
            v2.push_back(20.0);
            v2.push_back(40.0);
            v3.push_back(-25.0);
            v3.push_back(50.0);
            v3.push_back(20.0);
            float x2 = -10.0;
            float y2 = 20.0;
            float z2 = 40.0;
            float x3 = -25.0;
            float y3 = 50.0;
            float z3 = 20.0;
            vector1 = new Vector3D(v1);
            vector2 = new Vector3D(x2, y2, z2);
            vector3 = new Vector3D(x3, y3, z3);
        }

        virtual void TearDown(){
            delete vector1;
            delete vector2;
            delete vector3;
        }

        std::vector<float> v1;
        std::vector<float> v2;
        std::vector<float> v3;
        Vector3D* vector1;
        Vector3D* vector2;
        Vector3D* vector3;


};

TEST_F(Vector3DTest, ConstructorTest){
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
    EXPECT_EQ(vector1->GetY(), v1[1]);
    EXPECT_EQ(vector2->GetY(), v2[1]);
    EXPECT_EQ(vector3->GetY(), v3[1]);
    //GetZ
    EXPECT_EQ(vector1->GetZ(), v1[2]);
    EXPECT_EQ(vector2->GetZ(), v2[2]);
    EXPECT_EQ(vector3->GetZ(), v3[2]);
}

TEST_F(Vector3DTest, SetterTest){
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
    vector2->SetY(-75.023);
    vector3->SetZ(-235.001);

    EXPECT_TRUE((vector1->GetX() >= 100.019) && (vector1->GetX() <= 100.021));
    EXPECT_TRUE((vector2->GetY() >= -75.0231) && (vector2->GetY() <= -75.0229));
    EXPECT_TRUE((vector3->GetZ() >= -235.0011) && (vector3->GetZ() <= -235.0009));
    v2[0] = 100.02;
    v3[1] = -75.023;
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

TEST_F(Vector3DTest, MagnitudeAndNormalizeTest){
    std::vector<float> v1u;
    float magnitude = sqrt(20.0*20.0 + 50.0*50.0 + 70.0 * 70.0);
    v1u.push_back(20.0/magnitude);
    v1u.push_back(50.0/magnitude);
    v1u.push_back(70.0/magnitude);
    std::vector<float> v2u;
    magnitude = sqrt(-10.0*-10.0 + 20.0*20.0 + 40.0 * 40.0);
    v2u.push_back(-10.0/magnitude);
    v2u.push_back(20.0/magnitude);
    v2u.push_back(40.0/magnitude);
    std::vector<float> v3u;
    magnitude = sqrt(-25.0*-25.0 + 50.0*50.0 + 20.0 * 20.0);
    v3u.push_back(-25.0/magnitude);
    v3u.push_back(50.0/magnitude);
    v3u.push_back(20.0/magnitude);

    

    EXPECT_TRUE((vector1->Magnitude() >= 88.3175) && (vector1->Magnitude() <= 88.3177));
    EXPECT_TRUE((vector2->Magnitude() >= 45.8256) && (vector2->Magnitude() <= 45.8258));
    EXPECT_TRUE((vector3->Magnitude() >= 59.3716) && (vector3->Magnitude() <= 59.3718));

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

TEST_F(Vector3DTest, SubOperatorTest){
    Vector3D v3D1 = Vector3D(200, 100, 50);
    Vector3D v3D2 = Vector3D(100, 100, 100);
    Vector3D sum;

    sum = v3D1-v3D2;

    EXPECT_EQ(sum.GetVector()[0], 100);
    EXPECT_EQ(sum.GetVector()[1], 0);
    EXPECT_EQ(sum.GetVector()[2], -50);
    EXPECT_EQ(sum.GetX(), 100);
    EXPECT_EQ(sum.GetY(), 0);
    EXPECT_EQ(sum.GetZ(), -50);

    sum = (*vector1) - (*vector2);

    EXPECT_FLOAT_EQ(sum.GetVector()[0], 30);
    EXPECT_FLOAT_EQ(sum.GetVector()[1], 30);
    EXPECT_FLOAT_EQ(sum.GetVector()[2], 30);
    EXPECT_FLOAT_EQ(sum.GetX(), 30);
    EXPECT_FLOAT_EQ(sum.GetY(), 30);
    EXPECT_FLOAT_EQ(sum.GetZ(), 30);

}

TEST_F(Vector3DTest, SumOperatorTest){
    Vector3D v3D1 = Vector3D(200, 100, 50);
    Vector3D v3D2 = Vector3D(100, 100, -100);
    Vector3D sum;

    sum = v3D1+v3D2;

    EXPECT_EQ(sum.GetVector()[0], 300);
    EXPECT_EQ(sum.GetVector()[1], 200);
    EXPECT_EQ(sum.GetVector()[2], -50);
    EXPECT_EQ(sum.GetX(), 300);
    EXPECT_EQ(sum.GetY(), 200);
    EXPECT_EQ(sum.GetZ(), -50);

    sum = (*vector1) + (*vector2);

    EXPECT_FLOAT_EQ(sum.GetVector()[0], 10);
    EXPECT_FLOAT_EQ(sum.GetVector()[1], 70);
    EXPECT_FLOAT_EQ(sum.GetVector()[2], 110);
    EXPECT_FLOAT_EQ(sum.GetX(), 10);
    EXPECT_FLOAT_EQ(sum.GetY(), 70);
    EXPECT_FLOAT_EQ(sum.GetZ(), 110);
}

TEST_F(Vector3DTest, ProdOperatorTest){
    Vector3D v3D1 = Vector3D(200, 100, 50);
    Vector3D prod = v3D1 * 2.5;

    EXPECT_FLOAT_EQ(prod.GetVector()[0], 500);
    EXPECT_FLOAT_EQ(prod.GetVector()[1], 250);
    EXPECT_FLOAT_EQ(prod.GetVector()[2], 125);
    EXPECT_FLOAT_EQ(prod.GetX(), 500);
    EXPECT_FLOAT_EQ(prod.GetY(), 250);
    EXPECT_FLOAT_EQ(prod.GetZ(), 125);
}

}//namespace csci3081

