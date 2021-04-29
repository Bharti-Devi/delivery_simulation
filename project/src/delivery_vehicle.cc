#include "delivery_vehicle.h"
#include "json_helper.h"

namespace csci3081  {

void DeliveryVehicle::NotifyPackage(std::string event, IEntity* package)  {
  if (event == "scheduled"  || event == "en route" || event == "delivered") {
    //call OnEvent for package and send package notifications
    picojson::object notification_builder = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder, "value", event);
    picojson::value notification_to_send = JsonHelper::ConvertPicojsonObjectToValue(notification_builder);
    
    for (int i = 0; i < EntityBase::observers.size(); i++)  {
      EntityBase::observers[i]->OnEvent(notification_to_send, *package);
	  }
    return;
  }
}

void DeliveryVehicle::NotifyIdleVehicle(std::string event, IEntity* vehicle)  {
    picojson::object notification_builder = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder, "value", event);
    picojson::value notification_to_send = JsonHelper::ConvertPicojsonObjectToValue(notification_builder);

    for (int i = 0; i < EntityBase::observers.size(); i++)  {
      EntityBase::observers[i]->OnEvent(notification_to_send, *vehicle);
    }
    return;
}

void DeliveryVehicle::NotifyMovingVehicle(std::string event, IEntity* vehicle, std::vector<std::vector<float>> path)  {
    printf("IN MOVING NOTIFICATION\n");
    picojson::object notification_builder = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder, "value", event);
    JsonHelper::AddStdVectorVectorFloatToJsonObject(notification_builder, "path", path);
    picojson::value notification_to_send = JsonHelper::ConvertPicojsonObjectToValue(notification_builder);

    for (int i = 0; i < EntityBase::observers.size(); i++)  {
      EntityBase::observers[i]->OnEvent(notification_to_send, *vehicle);
    }
    return;
}

void DeliveryVehicle::NotifyDroneColor(std::string event, IEntity* drone, picojson::object& details)  {
  if (event == "updateDetails") {
    //call OnEvent for package and send package notifications
    picojson::object notification_builder = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notification_builder, "value", event);
    JsonHelper::AddObjectToJsonObject(notification_builder, "details", details);
    picojson::value notification_to_send = JsonHelper::ConvertPicojsonObjectToValue(notification_builder);
    
    for (int i = 0; i < EntityBase::observers.size(); i++)  {
      EntityBase::observers[i]->OnEvent(notification_to_send, *drone);
	  }
    return;
  }
}

}