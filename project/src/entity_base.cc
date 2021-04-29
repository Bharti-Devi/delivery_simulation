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

}