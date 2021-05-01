/**
 *@file simple_delivery_manager.h
 */
#ifndef SIMPLE_DELIVERY_MANAGER_H_
#define SIMPLE_DELIVERY_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <unordered_set>
#include "delivery_manager.h"

namespace entity_project {
    class IEntity;
}
using entity_project::IEntity;

namespace csci3081 {

class DeliveryVehicle;
class DeliveryObject;
class Package;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple implementation of DeliveryManager
 * 
 * Assigns deliveries to DeliveryVehicles in the order they are scheduled.
 * Dropped packages are moved to the front of the queue.
 */
class SimpleDeliveryManager : public DeliveryManager {
    public:
        /**
         * @brief Schedule \p package for delivery to \p dest
         * 
         * @param package Package to be delivered. dynamic_cast<Package*>(package) must not be nullptr.
         * 
         * @param dest Destination of package. dynamic_cast<Customer*>(dest) must not be nullptr.
         */
        void ScheduleDelivery(IEntity* package, IEntity* dest) override;

        /**
         * @brief Find work for \p deliveryVehicle
         * 
         * Lifetime of the returned DeliveryObject is managed by the DeliveryManager.
         * Should be called by a DeliveryVehicle with passed parameter \p this.
         * \p deliveryVehicle must accept the assigned work.
         * 
         * @return Pointer to a DeliveryObject describing work for \p deliveryVehicle to do.
         */
        DeliveryObject* GetWork(DeliveryVehicle* deliveryVehicle) override;

        /**
         * @brief Called by DeliveryVehicles to notify DeliveryManager of a completed delivery.
         * 
         * Parameter \p delivery is deallocated and shall not be dereferenced by after this method executes.
         */
        void AcceptDeliveryReport(DeliveryObject* delivery) override;

        /**
         * @brief Called by DeliveryVehicles to notify DeliveryManager of a dropped package.
         */
        void AcceptDroppedPackageReport(DeliveryObject* delivery) override;

        /**
         * @brief Destructor.
         * 
         * Calls delete on all of the deliveries added to it.
         */
        ~SimpleDeliveryManager();

    private:
        std::list<DeliveryObject*> deliveriesToAssign;
        std::unordered_set<DeliveryObject*> ongoingDeliveries;
};

}  // namespace csci3081

#endif    // SIMPLE_DELIVERY_MANAGER_H_
