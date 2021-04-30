#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/customer.h"
#include "../include/basic_package.h"
#include "../include/delivery_vehicle.h"
#include "../include/delivery_object.h"
#include "../include/simple_delivery_manager.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

#include <iostream>
#include <vector>


namespace csci3081 {

using entity_project::IEntity;

class SimpleDeliveryManagerTest : public ::testing::Test {
  protected:
        virtual void SetUp() {
            std::vector<float> zeroVect = {0,0,0};
            picojson::object details = JsonHelper::CreateJsonObject();
            p1 = new BasicPackage(zeroVect, zeroVect, details, 0);
            p2 = new BasicPackage(zeroVect, zeroVect, details, 0);
            p3 = new BasicPackage(zeroVect, zeroVect, details, 0);
            c1 = new Customer(zeroVect, zeroVect, details, 0);
            c2 = new Customer(zeroVect, zeroVect, details, 0);
            c3 = new Customer(zeroVect, zeroVect, details, 0);
            deliveryVehicle = nullptr;
        }

        virtual void TearDown() {
            delete p1;
            delete p2;
            delete p3;
            delete c1;
            delete c2;
            delete c3;
        }

        SimpleDeliveryManager deliveryManager;
        DeliveryVehicle* deliveryVehicle;
        BasicPackage* p1;
        BasicPackage* p2;
        BasicPackage* p3;
        Customer* c1;
        Customer* c2;
        Customer* c3;
};

TEST_F(SimpleDeliveryManagerTest, BasicAssignDeliveriesTest) {
    // Empty deliveryManager should not have any work to dole out
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);

    // Schedule a delivery, try to get work twice
    deliveryManager.ScheduleDelivery(p1, c1);
    ASSERT_NE(deliveryManager.GetWork(deliveryVehicle), nullptr);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);

    // Schedule two deliveries, try to get work three times
    deliveryManager.ScheduleDelivery(p2, c2);
    deliveryManager.ScheduleDelivery(p3, c3);
    ASSERT_NE(deliveryManager.GetWork(deliveryVehicle), nullptr);
    ASSERT_NE(deliveryManager.GetWork(deliveryVehicle), nullptr);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);
}

TEST_F(SimpleDeliveryManagerTest, BasicReassignDeliveriesTest) {
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);
    deliveryManager.ScheduleDelivery(p1, c1);
    deliveryManager.ScheduleDelivery(p2, c2);
    deliveryManager.ScheduleDelivery(p3, c3);
    DeliveryObject* o1 = deliveryManager.GetWork(deliveryVehicle);
    DeliveryObject* o2 = deliveryManager.GetWork(deliveryVehicle);
    DeliveryObject* o3 = deliveryManager.GetWork(deliveryVehicle);
    ASSERT_NE(o1, nullptr);
    ASSERT_NE(o2, nullptr);
    ASSERT_NE(o3, nullptr);

    // Check that a delivery is added back into the queue after a package is dropped
    deliveryManager.AcceptDroppedPackageReport(o1);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o1);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);

    // Confirm order of package reassignment
    deliveryManager.AcceptDroppedPackageReport(o1);
    deliveryManager.AcceptDroppedPackageReport(o2);
    deliveryManager.AcceptDroppedPackageReport(o3);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o3);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o2);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o1);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);

    deliveryManager.AcceptDeliveryReport(o1);
    deliveryManager.AcceptDeliveryReport(o2);
    deliveryManager.AcceptDeliveryReport(o3);
}

TEST_F(SimpleDeliveryManagerTest, FullAssignDeliveriesTest) {
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);
    deliveryManager.ScheduleDelivery(p1, c1);
    deliveryManager.ScheduleDelivery(p2, c2);
    deliveryManager.ScheduleDelivery(p3, c3);
    DeliveryObject* o1 = deliveryManager.GetWork(deliveryVehicle);
    DeliveryObject* o2 = deliveryManager.GetWork(deliveryVehicle);
    DeliveryObject* o3 = deliveryManager.GetWork(deliveryVehicle);
    deliveryManager.AcceptDroppedPackageReport(o3);
    deliveryManager.AcceptDroppedPackageReport(o2);
    deliveryManager.AcceptDroppedPackageReport(o1);
    // At this point, the queue looks like [out <- o1 o2 o3]

    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o1);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o2);
    deliveryManager.AcceptDroppedPackageReport(o1);
    deliveryManager.AcceptDroppedPackageReport(o2);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o2);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o1);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), o3);
    ASSERT_EQ(deliveryManager.GetWork(deliveryVehicle), nullptr);
}

}  // namespace csci3081