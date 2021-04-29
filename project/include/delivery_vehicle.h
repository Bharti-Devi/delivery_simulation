/**
 *@file delivery_vehicle.h
 */
#ifndef DELIVERY_VEHICLE_H_
#define DELIVERY_VEHICLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"

namespace entity_project {
    class IEntityObserver;
}
using entity_project::IEntityObserver;

namespace csci3081 {

class DeliveryManager;
class DeliveryObject;

/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
*  @brief Provides the public interface for all DeliveryVehicles, including Robots and Drones
*
*  Ideally, outside of creation logic there should be no code in the project depending on the
*  derived classes. If a developer finds that a certain behavior needs to be added only to some
*  derived class, it should be added here, and implemented in non-using classes with the null
*  object pattern.
*/
class DeliveryVehicle : public EntityBase {
    public:

        /**
         * @brief Return remaining battery charge.
         * 
         * @return Remaining battery charge.
         */
        virtual int GetCharge() = 0;

        /**
         * @brief Make vehicle responsible for \p delivery.
         * 
         * @param delivery The DeliveryObject that vehicle has been assigned to handle.
         */
        virtual void SetDeliveryObject(DeliveryObject *delivery) = 0;

        /**
         * @brief Returns true iff vehicle has delivery work assigned to it.
         * 
         * @return True if vehicle has delivery work assigned to it, else false.
         */
        virtual bool IsScheduled() = 0;

        /**
         * @brief Returns true iff vehicle is currently carrying a package.
         * 
         * @return True if vehicle is currently carrying a package, else false.
         */
        virtual bool DoesHavePackage() = 0;

        /**
         * @brief Destructor.
         */
        virtual ~DeliveryVehicle() {}

        /**
         * @brief Notifies observers that the package has been scheduled, picked up,
         * or dropped off.
         * 
         * @param event Event as a string that indicates which notification to send.
         * @param package Package Entity .
         */
        static void NotifyPackage(std::string event, IEntity* package);

        /**
         * @brief Tells observers that the delivery vehicle stopped moving.
         * 
         * @param event Event that indicates need for a notification.
         * @param vehicle Entity type, either drone or robot.
         */
        static void NotifyIdleVehicle(std::string event, IEntity* vehicle);

        /**
         * @brief Tells observers that the delivery vehicle started moving.
         * 
         * @param event Event that indicates need for a notification.
         * @param vehicle Entity type, either drone or robot.
         * @param path Vector for vehicle's path
         */
        static void NotifyMovingVehicle(std::string event, IEntity* vehicle, std::vector<std::vector<float>> path);

        /**
         * @brief Notifies observers that the details_ object in drone has been updated
         * 
         * @param event Event as a string that indicates which notification to send.
         * @param package Vehicle Entity.
         * @param details
         */
        static void NotifyDroneColor(std::string event, IEntity* drone, picojson::object& details);
};

}  // namespace csci3081

#endif    // DELIVERY_VEHICLE_H_