#include "delivery_simulation.h"
#include "entity_base.h"
#include "json_helper.h"
#include "drone_factory.h"
#include "package_factory.h"
#include "customer_factory.h"
#include "simple_delivery_manager.h"
#include "robot_factory.h"
#include "beeline_pathfinder_factory.h"
#include "parabolic_pathfinder_factory.h"
#include "smart_pathfinder_factory.h"

namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	//creates a factory and fills it with the factories
	//that it needs.
	this->manager = new SimpleDeliveryManager();
	this->factory = new CompositeFactory();
	this->pathfactory = new CompositePathfinderFactory();
	this->pathfactory->AddFactory(new BeelinePathfinderFactory());
	this->pathfactory->AddFactory(new ParabolicPathfinderFactory());
	this->pathfactory->AddFactory(new SmartPathfinderFactory());
	this->factory->AddFactory(new DroneFactory(manager, pathfactory));
	this->factory->AddFactory(new RobotFactory(manager, pathfactory));
	this->factory->AddFactory(new PackageFactory());
	this->factory->AddFactory(new CustomerFactory());
}

DeliverySimulation::~DeliverySimulation() {
	delete factory;
}

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
  return factory->CreateEntity(val);
}

void DeliverySimulation::AddFactory(IEntityFactory* factory) {
	this->factory->AddFactory(factory);
}

void DeliverySimulation::AddEntity(IEntity* entity) {
  entities_.push_back(entity);
  idCount++;
}

void DeliverySimulation::SetGraph(const IGraph* graph) {
	this->graph = graph;
	manager->SetGraph(graph);
	pathfactory->SetGraph(graph);
}

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
	manager->ScheduleDelivery(package, dest);
	//vehicle->NotifyPackage("scheduled", package);
}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
	observers_.push_back(observer);
	vehicle->Attach(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	for(int i = 0; i < observers_.size(); i++) {
    	if(observers_[i] == observer) {
      		observers_.erase(observers_.begin() + i);
      		return;
    	}
  	}
	vehicle->Detach(observer);
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }

void DeliverySimulation::Update(float dt) {
	//calls update on every drone.
	for(int i = 0; i< entities_.size(); i++){
		DeliveryVehicle* temp = dynamic_cast<DeliveryVehicle*>(entities_[i]);
		if (temp != nullptr){
			vehicle = temp;
			vehicle->Update(dt);
		}
	}
}


// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}

