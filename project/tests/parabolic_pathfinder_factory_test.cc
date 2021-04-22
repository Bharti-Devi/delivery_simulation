#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/parabolic_pathfinder_factory.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class ParabolicPathfinderFactoryTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            factory = new ParabolicPathfinderFactory();
            pathfinder = factory->CreatePathfinder("parabolic");
            start1.push_back(0);
            start1.push_back(0);
            start1.push_back(0);

            end1.push_back(100);
            end1.push_back(0);
            end1.push_back(0);

            start2.push_back(0);
            start2.push_back(0);
            start2.push_back(100);

            end2.push_back(0);
            end2.push_back(0);
            end2.push_back(0);

            start3.push_back(323.123);
            start3.push_back(102.764);
            start3.push_back(0.1234);

            end3.push_back(-132.321);
            end3.push_back(0);
            end3.push_back(300);

            path1 = pathfinder->GetPath(start1, end1);
            path2 = pathfinder->GetPath(start2, end2);
            path3 = pathfinder->GetPath(start3, end3);

        }

        virtual void TearDown() {
            delete pathfinder;
            delete factory;
        }
        std::vector<float> start1;
        std::vector<float> start2;
        std::vector<float> start3;
        std::vector<float> end1;
        std::vector<float> end2;
        std::vector<float> end3;
        std::vector< std::vector<float> > path1;
        std::vector< std::vector<float> > path2;
        std::vector< std::vector<float> > path3;
        ParabolicPathfinderFactory* factory;
        Pathfinder* pathfinder;
};

TEST_F(ParabolicPathfinderFactoryTest, GetPath){
    //Test first position
    EXPECT_FLOAT_EQ(0, path1[0][0]);
    EXPECT_FLOAT_EQ(0, path1[0][1]);
    EXPECT_FLOAT_EQ(0, path1[0][2]);

    EXPECT_FLOAT_EQ(0, path2[0][0]);
    EXPECT_FLOAT_EQ(0, path2[0][1]);
    EXPECT_FLOAT_EQ(100, path2[0][2]);

    EXPECT_FLOAT_EQ(323.123, path3[0][0]);
    EXPECT_FLOAT_EQ(102.764, path3[0][1]);
    EXPECT_FLOAT_EQ(0.1234, path3[0][2]);

    //Test last position
    EXPECT_FLOAT_EQ(99, path1[101][0]);
    EXPECT_FLOAT_EQ(44.06, path1[101][1]);
    EXPECT_FLOAT_EQ(0, path1[101][2]);

    EXPECT_FLOAT_EQ(0, path2[101][0]);
    EXPECT_FLOAT_EQ(44.06, path2[101][1]);
    EXPECT_FLOAT_EQ(1, path2[101][2]);

    EXPECT_FLOAT_EQ(-127.76656, path3[101][0]);
    EXPECT_FLOAT_EQ(45.067089, path3[101][1]);
    EXPECT_FLOAT_EQ(297.00122, path3[101][2]);

    //Test Second to last position.
    EXPECT_FLOAT_EQ(98, path1[100][0]);
    EXPECT_FLOAT_EQ(38.240002, path1[100][1]);
    EXPECT_FLOAT_EQ(0, path1[100][2]);

    EXPECT_FLOAT_EQ(0, path2[100][0]);
    EXPECT_FLOAT_EQ(38.240002, path2[100][1]);
    EXPECT_FLOAT_EQ(2, path2[100][2]);

    EXPECT_FLOAT_EQ(-123.21212, path3[100][0]);
    EXPECT_FLOAT_EQ(40.21307, path3[100][1]);
    EXPECT_FLOAT_EQ(294.00247, path3[100][2]);

    //Test middle position
    EXPECT_FLOAT_EQ(48, path1[50][0]);
    EXPECT_FLOAT_EQ(-99.760002, path1[50][1]);
    EXPECT_FLOAT_EQ(0, path1[50][2]);

    EXPECT_FLOAT_EQ(0, path2[50][0]);
    EXPECT_FLOAT_EQ(-99.760002, path2[50][1]);
    EXPECT_FLOAT_EQ(52, path2[50][2]);

    EXPECT_FLOAT_EQ(104.50986, path3[50][0]);
    EXPECT_FLOAT_EQ(-101.89749, path3[50][1]);
    EXPECT_FLOAT_EQ(144.06418, path3[50][2]);
}

}//namespace csci3081