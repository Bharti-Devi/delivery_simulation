#include "entity_base.h"

namespace csci3081 {

std::vector<IEntityObserver*> EntityBase::observers = std::vector<IEntityObserver*>();

const picojson::object& EntityBase::GetDetails() { return details_; }

void EntityBase::Attach(IEntityObserver* observer) {
  EntityBase::observers.push_back(observer);
}

void EntityBase::Detach(IEntityObserver* observer) {
  for (int i = 0; i < EntityBase::observers.size(); i++) {
    if (EntityBase::observers[i] == observer) {
      EntityBase::observers.erase(EntityBase::observers.begin() + i);
      return;
  	}
  }
}

void EntityBase::SetDetailsKey(const std::string& key, const picojson::value& value) {
  details_[key] = value;
}

void EntityBase::NotifyDetailsUpdate() {
  //call OnEvent for package and send package notifications
  picojson::object notification_builder = JsonHelper::CreateJsonNotification();
  notification_builder["value"] = picojson::value("updateDetails");
  notification_builder["details"] = picojson::value(GetDetails()); // Do NOT change GetDetails() to details_
  picojson::value notification_to_send = picojson::value(notification_builder);
    
  for (IEntityObserver *observer : observers) {
    observer->OnEvent(notification_to_send, *this);
	}
}

}