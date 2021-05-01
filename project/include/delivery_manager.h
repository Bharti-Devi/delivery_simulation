/**
 *@file delivery_manager.h
 */
#ifndef DELIVERY_MANAGER_H_
#define DELIVERY_MANAGER_H_

namespace entity_project {
    class IEntity;
    class IGraph;
}

using entity_project::IEntity;
using entity_project::IGraph;

namespace csci3081 {

class DeliveryVehicle;
class DeliveryObject;
class Package;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Provides an interface for assigning work to DeliveryVehicles.
 * 
 * Derived classes should provide a guarantee that, battery life considerations aside,
 * if this DeliveryManager has DeliveryVehicles requesting work from it, every scheduled
 * package will be assigned to a DeliveryVehicle within finite time.
 */
class DeliveryManager {
    public:
        /**
         * @brief Schedule \p package for delivery to \p dest
         * 
         * @param package Package to be delivered. dynamic_cast<Package*>(package) must not be nullptr.
         * 
         * @param dest Destination of package. dynamic_cast<Customer*>(dest) must not be nullptr.
         */
        virtual void ScheduleDelivery(IEntity* package, IEntity* dest) = 0;
        /**
         * @brief Find work for \p deliveryVehicle
         * 
         * Lifetime of the returned DeliveryObject is managed by the DeliveryManager.
         * Should be called by a DeliveryVehicle with passed parameter \p this.
         * \p deliveryVehicle must accept the assigned work.
         * 
         * @return Pointer to a DeliveryObject describing work for \p deliveryVehicle to do.
         */
        virtual DeliveryObject* GetWork(DeliveryVehicle* deliveryVehicle) = 0;
        /**
         * @brief Called by DeliveryVehicles to notify DeliveryManager of a completed delivery.
         * 
         * Parameter \p delivery may be deallocated and shall not be dereferenced by any other class after this call.
         */
        virtual void AcceptDeliveryReport(DeliveryObject* delivery) = 0;
        /**
         * @brief Called by DeliveryVehicles to notify DeliveryManager of a dropped package.
         */
        virtual void AcceptDroppedPackageReport(DeliveryObject* delivery) = 0;
        /**
         * @brief Sets the graph of a DeliveryVehicle object.
         *
         * @param graph Graph to be used.
         */
        void SetGraph(const IGraph* graph) { this->graph = graph; }
        /**
         * @brief Gets the graph of a DeliveryVehicle object.
         */
        const IGraph* GetGraph() { return graph; }
        /**
         * @brief Destructor.
         */
        virtual ~DeliveryManager() {}

    protected:
        const IGraph* graph;
};

}  // namespace csci3081

#endif    // DELIVERY_MANAGER_H_
