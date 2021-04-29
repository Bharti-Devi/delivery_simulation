#include "simple_delivery_manager.h"

#include <stdexcept>
#include "delivery_object.h"
#include "package.h"
#include "customer.h"

namespace csci3081 {

void SimpleDeliveryManager::ScheduleDelivery(IEntity* package_, IEntity* dest_) {
    Package* package = dynamic_cast<Package*>(package_);
    Customer* customer = dynamic_cast<Customer*>(dest_);
    if(package == nullptr || customer == nullptr) {
        throw std::runtime_error("Incorrect type(s) passed to ScheduleDelivery");
    }

    deliveriesToAssign.push_back(new DeliveryObject(package, customer));
}

DeliveryObject* SimpleDeliveryManager::GetWork(DeliveryVehicle* deliveryVehicle) {
    if(deliveriesToAssign.empty()) {
        return nullptr;
    }

    DeliveryObject* temp = deliveriesToAssign.front();
    deliveriesToAssign.pop_front();
    ongoingDeliveries.insert(temp);
    return temp;
}

void SimpleDeliveryManager::AcceptDeliveryReport(DeliveryObject* delivery) {
    auto delivery_it = ongoingDeliveries.find(delivery);
    if(delivery_it == ongoingDeliveries.end()) {
        return;
    }

    delete *delivery_it;
    ongoingDeliveries.erase(delivery_it);
}

void SimpleDeliveryManager::AcceptDroppedPackageReport(DeliveryObject* delivery) {
    auto delivery_it = ongoingDeliveries.find(delivery);
    if(delivery_it == ongoingDeliveries.end()) {
        return;
    }

    deliveriesToAssign.push_front(*delivery_it);
    ongoingDeliveries.erase(delivery_it);
}

SimpleDeliveryManager::~SimpleDeliveryManager() {
    for(DeliveryObject* delivery : deliveriesToAssign) {
        delete delivery;
    }

    for(DeliveryObject* delivery : ongoingDeliveries) {
        delete delivery;
    }
}

}  // namespace csci3081