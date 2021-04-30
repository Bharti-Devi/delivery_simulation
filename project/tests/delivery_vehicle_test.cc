#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_vehicle.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "basic_drone.h"
#include "basic_robot.h"
#include "basic_package.h"
#include "simple_delivery_manager.h"
#include "../include/parabolic_pathfinder.h"
#include "../include/smart_pathfinder.h"

namespace csci3081{

class DeliveryVehicleTest: public ::testing::Test {
    protected:
    virtual void SetUp(){
        manager = new SimpleDeliveryManager();
        picojson::object obj1 = JsonHelper::CreateJsonObject();
        picojson::object obj2 = JsonHelper::CreateJsonObject();
        picojson::object obj3 = JsonHelper::CreateJsonObject();
        //drone
        JsonHelper::AddStringToJsonObject(obj1, "name", "drone");
        JsonHelper::AddStringToJsonObject(obj1, "type", "drone");
        JsonHelper::AddStringToJsonObject(obj1, "path", "parabolic");
        position_to_add1.push_back(498.292);
        position_to_add1.push_back(253.883);
        position_to_add1.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
        direction_to_add1.push_back(1);
        direction_to_add1.push_back(0);
        direction_to_add1.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
        entity1 = new BasicDrone(position_to_add1, direction_to_add1, obj1, 0, manager, new ParabolicPathfinder());
        //package
        JsonHelper::AddStringToJsonObject(obj2, "type", "package");
        position_to_add2.push_back(200.1);
        position_to_add2.push_back(77.0);
        position_to_add2.push_back(123);
        JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
        direction_to_add2.push_back(0);
        direction_to_add2.push_back(1);
        direction_to_add2.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
        entity2 = new BasicPackage(position_to_add2, direction_to_add2, obj2, 1);
        //robot
        JsonHelper::AddStringToJsonObject(obj3, "name", "robot");
        JsonHelper::AddStringToJsonObject(obj3, "type", "robot");
        JsonHelper::AddStringToJsonObject(obj3, "path", "smart");
        position_to_add3.push_back(498.292);
        position_to_add3.push_back(253.883);
        position_to_add3.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add3);
        direction_to_add3.push_back(1);
        direction_to_add3.push_back(0);
        direction_to_add3.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add3);
        entity3 = new BasicRobot(position_to_add3, direction_to_add3, obj3, 2, manager, new SmartPathfinder(graph));
    }
    virtual void TearDown(){
        delete entity1;
        delete entity2;
        delete entity3;
        delete manager;
        delete graph;
    }
    std::vector<float> position_to_add1;
    std::vector<float> position_to_add2;
    std::vector<float> position_to_add3;
    std::vector<float> direction_to_add1;
    std::vector<float> direction_to_add2;
    std::vector<float> direction_to_add3;
    Drone* entity1;
    Package* entity2;
    Robot* entity3;
    SimpleDeliveryManager* manager;
    const IGraph* graph;
};

TEST_F(DeliveryVehicleTest, DroneNotificationTest){
    //test OnEvent Parameters
    picojson::object notification_builder1 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder1, "value", "idle");
    picojson::value notification_to_send1 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder1);
    
    picojson::object notification_builder2 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder2, "value", "moving");
    picojson::value notification_to_send2 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder2);
    
    std::string notification1 = JsonHelper::GetString(notification_builder1, "value");
    std::string notification2 = JsonHelper::GetString(notification_builder2, "value");

    //test notification sent when robot is idle and moving
    EXPECT_EQ(notification1, "idle");
    EXPECT_EQ(notification2, "moving");
    
    //test package whose notifications will be sent
    EXPECT_EQ(entity1->GetPosition()[0], position_to_add1[0]);
    EXPECT_EQ(entity1->GetPosition()[1], position_to_add1[1]);
    EXPECT_EQ(entity1->GetPosition()[2], position_to_add1[2]);

    EXPECT_EQ(entity1->GetDirection()[0], direction_to_add1[0]);
    EXPECT_EQ(entity1->GetDirection()[1], direction_to_add1[1]);
    EXPECT_EQ(entity1->GetDirection()[2], direction_to_add1[2]);
}

TEST_F(DeliveryVehicleTest, PackageNotificationTest){
    //test OnEvent Parameters
    picojson::object notification_builder1 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder1, "value", "scheduled");
    picojson::value notification_to_send1 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder1);
    
    picojson::object notification_builder2 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder2, "value", "en route");
    picojson::value notification_to_send2 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder2);
    
    picojson::object notification_builder3 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder3, "value", "delivered");
    picojson::value notification_to_send3 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder3);

    std::string notification1 = JsonHelper::GetString(notification_builder1, "value");
    std::string notification2 = JsonHelper::GetString(notification_builder2, "value");
    std::string notification3 = JsonHelper::GetString(notification_builder3, "value");

    //test notification sent when package is scheduled, moving, and delivered
    EXPECT_EQ(notification1, "scheduled");
    EXPECT_EQ(notification2, "en route");
    EXPECT_EQ(notification3, "delivered");
    
    //test package whose notifications will be sent
    EXPECT_EQ(entity2->GetPosition()[0], position_to_add2[0]);
    EXPECT_EQ(entity2->GetPosition()[1], position_to_add2[1]);
    EXPECT_EQ(entity2->GetPosition()[2], position_to_add2[2]);

    EXPECT_EQ(entity2->GetDirection()[0], direction_to_add2[0]);
    EXPECT_EQ(entity2->GetDirection()[1], direction_to_add2[1]);
    EXPECT_EQ(entity2->GetDirection()[2], direction_to_add2[2]);
}

TEST_F(DeliveryVehicleTest, RobotNotificationTest){
    //test OnEvent Parameters
    picojson::object notification_builder1 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder1, "value", "idle");
    picojson::value notification_to_send1 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder1);
    
    picojson::object notification_builder2 = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder2, "value", "moving");
    picojson::value notification_to_send2 = JsonHelper::ConvertPicojsonObjectToValue(notification_builder2);
    
    std::string notification1 = JsonHelper::GetString(notification_builder1, "value");
    std::string notification2 = JsonHelper::GetString(notification_builder2, "value");

    //test notification sent when robot is idle and moving
    EXPECT_EQ(notification1, "idle");
    EXPECT_EQ(notification2, "moving");
    
    //test package whose notifications will be sent
    EXPECT_EQ(entity3->GetPosition()[0], position_to_add3[0]);
    EXPECT_EQ(entity3->GetPosition()[1], position_to_add3[1]);
    EXPECT_EQ(entity3->GetPosition()[2], position_to_add3[2]);

    EXPECT_EQ(entity3->GetDirection()[0], direction_to_add3[0]);
    EXPECT_EQ(entity3->GetDirection()[1], direction_to_add3[1]);
    EXPECT_EQ(entity3->GetDirection()[2], direction_to_add3[2]);
}

}//namespace csci3081