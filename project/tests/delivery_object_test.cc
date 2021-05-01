#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_object.h"
#include "../include/basic_package.h"
#include "../include/basic_customer.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081{

class DeliveryObjectTest: public ::testing::Test {
    protected:

    virtual void SetUp(){
        picojson::object cobj1 = JsonHelper::CreateJsonObject();
        picojson::object cobj2 = JsonHelper::CreateJsonObject();
        picojson::object cobj3 = JsonHelper::CreateJsonObject();
        //Customer 1
        JsonHelper::AddStringToJsonObject(cobj1, "type", "customer");
        std::vector<float> cposition_to_add1;
        cposition_to_add1.push_back(498.292);
        cposition_to_add1.push_back(253.883);
        cposition_to_add1.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj1, "position", cposition_to_add1);
        std::vector<float> cdirection_to_add1;
        cdirection_to_add1.push_back(1);
        cdirection_to_add1.push_back(0);
        cdirection_to_add1.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj1, "direction", cdirection_to_add1);
        c1 = new BasicCustomer(cposition_to_add1, cdirection_to_add1, cobj1, 0);
        //Customer 2
        JsonHelper::AddStringToJsonObject(cobj2, "type", "customer");
        std::vector<float> cposition_to_add2;
        cposition_to_add2.push_back(200.1);
        cposition_to_add2.push_back(77.0);
        cposition_to_add2.push_back(123);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj2, "position", cposition_to_add2);
        std::vector<float> cdirection_to_add2;
        cdirection_to_add2.push_back(0);
        cdirection_to_add2.push_back(1);
        cdirection_to_add2.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj2, "direction", cdirection_to_add2);
        c2 = new BasicCustomer(cposition_to_add2, cdirection_to_add2, cobj2, 1);
        //Customer 3
        JsonHelper::AddStringToJsonObject(cobj3, "type", "customer");
        std::vector<float> cposition_to_add3;
        cposition_to_add3.push_back(0);
        cposition_to_add3.push_back(0);
        cposition_to_add3.push_back(1);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj3, "position", cposition_to_add3);
        std::vector<float> cdirection_to_add3;
        cdirection_to_add3.push_back(30);
        cdirection_to_add3.push_back(263.32);
        cdirection_to_add3.push_back(12.01);
        JsonHelper::AddStdFloatVectorToJsonObject(cobj3, "direction", cdirection_to_add3);
        c3 = new BasicCustomer(cposition_to_add3, cdirection_to_add3, cobj3, 2);

        //Packages

        picojson::object pobj1 = JsonHelper::CreateJsonObject();
        picojson::object pobj2 = JsonHelper::CreateJsonObject();
        picojson::object pobj3 = JsonHelper::CreateJsonObject();
        //Package 1
        JsonHelper::AddStringToJsonObject(pobj1, "type", "package");
        std::vector<float> pposition_to_add1;
        pposition_to_add1.push_back(498.292);
        pposition_to_add1.push_back(253.883);
        pposition_to_add1.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj1, "position", pposition_to_add1);
        std::vector<float> pdirection_to_add1;
        pdirection_to_add1.push_back(1);
        pdirection_to_add1.push_back(0);
        pdirection_to_add1.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj1, "direction", pdirection_to_add1);
        p1 = new BasicPackage(pposition_to_add1, pdirection_to_add1, pobj1, 0);
        //Package 2
        JsonHelper::AddStringToJsonObject(pobj2, "type", "package");
        std::vector<float> pposition_to_add2;
        pposition_to_add2.push_back(498.292);
        pposition_to_add2.push_back(253.883);
        pposition_to_add2.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj2, "position", pposition_to_add2);
        std::vector<float> pdirection_to_add2;
        pdirection_to_add2.push_back(1);
        pdirection_to_add2.push_back(0);
        pdirection_to_add2.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj2, "direction", pdirection_to_add2);
        p2 = new BasicPackage(pposition_to_add2, pdirection_to_add2, pobj2, 0);
        //Package 3
        JsonHelper::AddStringToJsonObject(pobj3, "type", "package");
        std::vector<float> pposition_to_add3;
        pposition_to_add3.push_back(498.292);
        pposition_to_add3.push_back(253.883);
        pposition_to_add3.push_back(-228.623);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj3, "position", pposition_to_add3);
        std::vector<float> pdirection_to_add3;
        pdirection_to_add3.push_back(1);
        pdirection_to_add3.push_back(0);
        pdirection_to_add3.push_back(0);
        JsonHelper::AddStdFloatVectorToJsonObject(pobj3, "direction", pdirection_to_add3);
        p3 = new BasicPackage(pposition_to_add3, pdirection_to_add3, pobj3, 0);

        d1 = new DeliveryObject(p1, c1);
        d2 = new DeliveryObject(p2, c2);
        d3 = new DeliveryObject(p3, c3);
    }

    virtual void TearDown(){
        delete p1;
        delete p2;
        delete p3;
        delete c1;
        delete c2;
        delete c3;
        delete d1;
        delete d2;
        delete d3;
    }

        IEntity* p1;
        IEntity* p2;
        IEntity* p3;
        IEntity* c1;
        IEntity* c2;
        IEntity* c3;
        DeliveryObject* d1;
        DeliveryObject* d2;
        DeliveryObject* d3;
};

TEST_F(DeliveryObjectTest, GetDirectionTest){
    Vector3D* v1 = new Vector3D(0, 0, 0);
    std::vector<float> direction1 = d1->GetDirection(v1);
    Vector3D answer1 = Vector3D(498.292, 253.883, -228.623);
    answer1.Normalize();
    ASSERT_FLOAT_EQ(direction1[0], answer1.GetX());
    ASSERT_FLOAT_EQ(direction1[1], answer1.GetY());
    ASSERT_FLOAT_EQ(direction1[2], answer1.GetZ());

    Vector3D* v2 = new Vector3D(273.12, 123.4567, 12);
    std::vector<float> direction2 = d2->GetDirection(v2);
    Vector3D answer2 = Vector3D(225.172, 130.4263, -240.623);
    answer2.Normalize();
    ASSERT_FLOAT_EQ(direction2[0], answer2.GetX());
    ASSERT_FLOAT_EQ(direction2[1], answer2.GetY());
    ASSERT_FLOAT_EQ(direction2[2], answer2.GetZ());

    Vector3D* v3 = new Vector3D(273.12, 123.4567, 12);
    std::vector<float> direction3 = d3->GetDirection(v3);
    Vector3D answer3 = Vector3D(225.172, 130.4263, -240.623);
    answer3.Normalize();
    ASSERT_FLOAT_EQ(direction3[0], answer3.GetX());
    ASSERT_FLOAT_EQ(direction3[1], answer3.GetY());
    ASSERT_FLOAT_EQ(direction3[2], answer3.GetZ());

    delete v1;
    delete v2;
    delete v3;
}

TEST_F(DeliveryObjectTest, PickUpTest){
    std::vector<float> pos1;
    std::vector<float> pos2;
    std::vector<float> edge1;
    std::vector<float> edge2;
    std::vector<float> mixededge;
    std::vector<float> outeredge1;
    std::vector<float> outeredge2;
    std::vector<float> mixedouteredge;
    pos1.push_back(498.292);
    pos1.push_back(253.883);
    pos1.push_back(-228.623);
    pos2.push_back(-1000);
    pos2.push_back(1000);
    pos2.push_back(-1000);
    edge1.push_back(499.292);
    edge1.push_back(253.8830);
    edge1.push_back(-227.623);
    edge2.push_back(498.292);
    edge2.push_back(252.883);
    edge2.push_back(-228.623);
    mixededge.push_back(499.292);
    mixededge.push_back(250.883);
    mixededge.push_back(-227.623);
    outeredge1.push_back(500);
    outeredge1.push_back(255);
    outeredge1.push_back(-226);
    outeredge2.push_back(496);
    outeredge2.push_back(251);
    outeredge2.push_back(-230);
    mixedouteredge.push_back(500);
    mixedouteredge.push_back(251);
    mixedouteredge.push_back(-226);

    ASSERT_EQ(d1->PickUp(pos1), true);
    ASSERT_EQ(d1->PickUp(edge1), true);
    ASSERT_EQ(d1->PickUp(edge2), true);
    ASSERT_EQ(d1->PickUp(mixededge), true);

    Package* packagedPackage1 = dynamic_cast<Package*>(p1);
    
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[0], 499.292);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[1], 249.883);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[2], -227.623);
    ASSERT_EQ(packagedPackage1->GetTravelStatus(), true);

    ASSERT_EQ(d2->PickUp(pos2), false);
    ASSERT_EQ(d2->PickUp(outeredge1), false);
    ASSERT_EQ(d2->PickUp(outeredge2), false);
    ASSERT_EQ(d2->PickUp(mixedouteredge), false);

    Package* packagedPackage2 = dynamic_cast<Package*>(p2);

    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[0], 498.292);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[1], 253.883);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[2], -228.623);
    ASSERT_EQ(packagedPackage2->GetTravelStatus(), false);

}

TEST_F(DeliveryObjectTest, DropOffTest){
    std::vector<float> pos1;
    std::vector<float> pos2;
    std::vector<float> edge1;
    std::vector<float> edge2;
    std::vector<float> mixededge;
    std::vector<float> outeredge1;
    std::vector<float> outeredge2;
    std::vector<float> mixedouteredge;
    pos1.push_back(498.292);
    pos1.push_back(253.883);
    pos1.push_back(-228.623);
    pos2.push_back(-1000);
    pos2.push_back(1000);
    pos2.push_back(-1000);
    edge1.push_back(499.292);
    edge1.push_back(254.8830);
    edge1.push_back(-227.623);
    edge2.push_back(497.292);
    edge2.push_back(252.883);
    edge2.push_back(-229.623);
    mixededge.push_back(499.292);
    mixededge.push_back(252.883);
    mixededge.push_back(-227.623);
    outeredge1.push_back(499.293);
    outeredge1.push_back(254.884);
    outeredge1.push_back(-227.624);
    outeredge2.push_back(497.291);
    outeredge2.push_back(252.882);
    outeredge2.push_back(-229.623);
    mixedouteredge.push_back(497.291);
    mixedouteredge.push_back(252.882);
    mixedouteredge.push_back(-227.624);

    ASSERT_EQ(d1->DropOff(pos1), true);
    ASSERT_EQ(d1->DropOff(edge1), true);
    ASSERT_EQ(d1->DropOff(edge2), true);
    ASSERT_EQ(d1->DropOff(mixededge), true);

    Package* packagedPackage1 = dynamic_cast<Package*>(p1);
    
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[0], 498.292);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[1], -999);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[2], -228.623);
    ASSERT_EQ(packagedPackage1->GetTravelStatus(), false);
    ASSERT_EQ(packagedPackage1->GetDeliveryStatus(), true);

    ASSERT_EQ(d2->DropOff(pos1), false);
    

    Package* packagedPackage2 = dynamic_cast<Package*>(p2);

    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[0], 498.292);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[1], 253.883);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[2], -228.623);
    ASSERT_EQ(packagedPackage2->GetTravelStatus(), false);
    ASSERT_EQ(packagedPackage2->GetDeliveryStatus(), false);
}

TEST_F(DeliveryObjectTest, UpdateTest){
    Package* packagedPackage1 = dynamic_cast<Package*>(p1);
    packagedPackage1->SetTraveling(true);
    std::vector<float> pos1;
    pos1.push_back(100);
    pos1.push_back(200);
    pos1.push_back(300);

    d1->Update(1.0, pos1);

    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[0], 100);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[1], 199);
    ASSERT_FLOAT_EQ(packagedPackage1->GetPosition()[2], 300);

    d2->Update(1.0, pos1);

    Package* packagedPackage2 = dynamic_cast<Package*>(p2);

    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[0], 498.292);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[1], 253.883);
    ASSERT_FLOAT_EQ(packagedPackage2->GetPosition()[2], -228.623);
    
}

TEST_F(DeliveryObjectTest, GetPositionsTest){
    //DeliveryObject d1
    ASSERT_FLOAT_EQ(d1->GetPackagePosition()[0], 498.29199);
    ASSERT_FLOAT_EQ(d1->GetPackagePosition()[1], 253.883);
    ASSERT_FLOAT_EQ(d1->GetPackagePosition()[2], -228.623);

    ASSERT_FLOAT_EQ(d1->GetCustomerPosition()[0], 498.29199);
    ASSERT_FLOAT_EQ(d1->GetCustomerPosition()[1], 253.883);
    ASSERT_FLOAT_EQ(d1->GetCustomerPosition()[2], -228.623);

    //DeliveryObject d2
    ASSERT_FLOAT_EQ(d2->GetPackagePosition()[0], 498.29199);
    ASSERT_FLOAT_EQ(d2->GetPackagePosition()[1], 253.883);
    ASSERT_FLOAT_EQ(d2->GetPackagePosition()[2], -228.623);

    ASSERT_FLOAT_EQ(d2->GetCustomerPosition()[0], 200.1);
    ASSERT_FLOAT_EQ(d2->GetCustomerPosition()[1], 77.0);
    ASSERT_FLOAT_EQ(d2->GetCustomerPosition()[2], 123);

    //DeliveryObject d3
    ASSERT_FLOAT_EQ(d3->GetPackagePosition()[0], 498.29199);
    ASSERT_FLOAT_EQ(d3->GetPackagePosition()[1], 253.883);
    ASSERT_FLOAT_EQ(d3->GetPackagePosition()[2], -228.623);

    ASSERT_FLOAT_EQ(d3->GetCustomerPosition()[0], 0);
    ASSERT_FLOAT_EQ(d3->GetCustomerPosition()[1], 0);
    ASSERT_FLOAT_EQ(d3->GetCustomerPosition()[2], 1);
}

TEST_F(DeliveryObjectTest, GetPackageTest){
    //DeliveryObject d1
    ASSERT_EQ((d1->GetPackage())->GetPosition()[0], p1->GetPosition()[0]);
    ASSERT_EQ((d1->GetPackage())->GetPosition()[1], p1->GetPosition()[1]);
    ASSERT_EQ((d1->GetPackage())->GetPosition()[2], p1->GetPosition()[2]);

    ASSERT_EQ((d1->GetPackage())->GetDirection()[0], p1->GetDirection()[0]);
    ASSERT_EQ((d1->GetPackage())->GetDirection()[1], p1->GetDirection()[1]);
    ASSERT_EQ((d1->GetPackage())->GetDirection()[2], p1->GetDirection()[2]);

    //DeliveryObject d2
    ASSERT_EQ((d2->GetPackage())->GetPosition()[0], p2->GetPosition()[0]);
    ASSERT_EQ((d2->GetPackage())->GetPosition()[1], p2->GetPosition()[1]);
    ASSERT_EQ((d2->GetPackage())->GetPosition()[2], p2->GetPosition()[2]);

    ASSERT_EQ((d2->GetPackage())->GetDirection()[0], p2->GetDirection()[0]);
    ASSERT_EQ((d2->GetPackage())->GetDirection()[1], p2->GetDirection()[1]);
    ASSERT_EQ((d2->GetPackage())->GetDirection()[2], p2->GetDirection()[2]);

    //DeliveryObject d3
    ASSERT_EQ((d3->GetPackage())->GetPosition()[0], p3->GetPosition()[0]);
    ASSERT_EQ((d3->GetPackage())->GetPosition()[1], p3->GetPosition()[1]);
    ASSERT_EQ((d3->GetPackage())->GetPosition()[2], p3->GetPosition()[2]);

    ASSERT_EQ((d3->GetPackage())->GetDirection()[0], p3->GetDirection()[0]);
    ASSERT_EQ((d3->GetPackage())->GetDirection()[1], p3->GetDirection()[1]);
    ASSERT_EQ((d3->GetPackage())->GetDirection()[2], p3->GetDirection()[2]);
}

}//namespace csci3081