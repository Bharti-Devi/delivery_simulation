#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/beeline_pathfinder.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class BeelinePathfinderTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            pathfinder = new BeelinePathfinder();
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
        BeelinePathfinder* pathfinder;
};

TEST_F(BeelinePathfinderTest, GetPath){
    //Test 0th position
    EXPECT_FLOAT_EQ(0, path1[0][0]);
    EXPECT_FLOAT_EQ(0, path1[0][1]);
    EXPECT_FLOAT_EQ(0, path1[0][2]);

    EXPECT_FLOAT_EQ(0, path2[0][0]);
    EXPECT_FLOAT_EQ(0, path2[0][1]);
    EXPECT_FLOAT_EQ(100, path2[0][2]);

    EXPECT_FLOAT_EQ(323.123, path3[0][0]);
    EXPECT_FLOAT_EQ(102.764, path3[0][1]);
    EXPECT_FLOAT_EQ(0.1234, path3[0][2]);

    //Test 1st position
    EXPECT_FLOAT_EQ(0, path1[1][0]);
    EXPECT_FLOAT_EQ(200, path1[1][1]);
    EXPECT_FLOAT_EQ(0, path1[1][2]);

    EXPECT_FLOAT_EQ(0, path2[1][0]);
    EXPECT_FLOAT_EQ(200, path2[1][1]);
    EXPECT_FLOAT_EQ(100, path2[1][2]);

    EXPECT_FLOAT_EQ(323.123, path3[1][0]);
    EXPECT_FLOAT_EQ(302.764, path3[1][1]);
    EXPECT_FLOAT_EQ(0.1234, path3[1][2]);

    //Test last position.
    EXPECT_FLOAT_EQ(100, path1[2][0]);
    EXPECT_FLOAT_EQ(200, path1[2][1]);
    EXPECT_FLOAT_EQ(0, path1[2][2]);

    EXPECT_FLOAT_EQ(0, path2[2][0]);
    EXPECT_FLOAT_EQ(200, path2[2][1]);
    EXPECT_FLOAT_EQ(0, path2[2][2]);

    EXPECT_FLOAT_EQ(-132.321, path3[2][0]);
    EXPECT_FLOAT_EQ(200, path3[2][1]);
    EXPECT_FLOAT_EQ(300, path3[2][2]);   
} 

}//namespace csci3081