#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/composite_pathfinder_factory.h"
#include "../include/beeline_pathfinder_factory.h"
#include "../include/parabolic_pathfinder_factory.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class CompositePathfinderFactoryTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            factory = new CompositePathfinderFactory();
            factory->AddFactory(new BeelinePathfinderFactory());
            factory->AddFactory(new ParabolicPathfinderFactory());
            beeline = factory->CreatePathfinder("beeline");
            parabolic = factory->CreatePathfinder("parabolic");
            
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

            path1 = beeline->GetPath(start1, end1);
            path2 = beeline->GetPath(start2, end2);
            path3 = beeline->GetPath(start3, end3);

            path1p = parabolic->GetPath(start1, end1);
            path2p = parabolic->GetPath(start2, end2);
            path3p = parabolic->GetPath(start3, end3);

        }

        virtual void TearDown() {
            delete beeline;
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
        std::vector< std::vector<float> > path1p;
        std::vector< std::vector<float> > path2p;
        std::vector< std::vector<float> > path3p;
        CompositePathfinderFactory* factory;
        Pathfinder* beeline;
        Pathfinder* parabolic;
};

TEST_F(CompositePathfinderFactoryTest, GetPath){
    //Does it properly make beeline
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

    //Does it properly make Parabolic
    EXPECT_FLOAT_EQ(0, path1p[0][0]);
    EXPECT_FLOAT_EQ(0, path1p[0][1]);
    EXPECT_FLOAT_EQ(0, path1p[0][2]);

    EXPECT_FLOAT_EQ(0, path2p[0][0]);
    EXPECT_FLOAT_EQ(0, path2p[0][1]);
    EXPECT_FLOAT_EQ(100, path2p[0][2]);

    EXPECT_FLOAT_EQ(323.123, path3p[0][0]);
    EXPECT_FLOAT_EQ(102.764, path3p[0][1]);
    EXPECT_FLOAT_EQ(0.1234, path3p[0][2]);

    //Test last position
    EXPECT_FLOAT_EQ(99, path1p[101][0]);
    EXPECT_FLOAT_EQ(44.06, path1p[101][1]);
    EXPECT_FLOAT_EQ(0, path1p[101][2]);

    EXPECT_FLOAT_EQ(0, path2p[101][0]);
    EXPECT_FLOAT_EQ(44.06, path2p[101][1]);
    EXPECT_FLOAT_EQ(1, path2p[101][2]);

    EXPECT_FLOAT_EQ(-127.76656, path3p[101][0]);
    EXPECT_FLOAT_EQ(45.067089, path3p[101][1]);
    EXPECT_FLOAT_EQ(297.00122, path3p[101][2]);

    //Test Second to last position.
    EXPECT_FLOAT_EQ(98, path1p[100][0]);
    EXPECT_FLOAT_EQ(38.24, path1p[100][1]);
    EXPECT_FLOAT_EQ(0, path1p[100][2]);

    EXPECT_FLOAT_EQ(0, path2p[100][0]);
    EXPECT_FLOAT_EQ(38.24, path2p[100][1]);
    EXPECT_FLOAT_EQ(2, path2p[100][2]);

    EXPECT_FLOAT_EQ(-123.21212, path3p[100][0]);
    EXPECT_FLOAT_EQ(40.21307, path3p[100][1]);
    EXPECT_FLOAT_EQ(294.00247, path3p[100][2]);

    //Test middle position
    EXPECT_FLOAT_EQ(48, path1p[50][0]);
    EXPECT_FLOAT_EQ(-99.76, path1p[50][1]);
    EXPECT_FLOAT_EQ(0, path1p[50][2]);

    EXPECT_FLOAT_EQ(0, path2p[50][0]);
    EXPECT_FLOAT_EQ(-99.76, path2p[50][1]);
    EXPECT_FLOAT_EQ(52, path2p[50][2]);

    EXPECT_FLOAT_EQ(104.50986, path3p[50][0]);
    EXPECT_FLOAT_EQ(-101.89749, path3p[50][1]);
    EXPECT_FLOAT_EQ(144.06418, path3p[50][2]);
} 

}//namespace csci3081