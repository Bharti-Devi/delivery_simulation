/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include "vector3d.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information.
 */
class EntityBase : public IEntity {
 public:
 	/**
 	 * @brief Destructor.
 	 */
 	virtual ~EntityBase() {}

 	/**
 	 * @brief Gets details of a JSON object.
 	 *
 	 * @return Details.
 	 */
	virtual const picojson::object& GetDetails();

	/**
     * @brief Adds observers in delivery vehicles.
     * 
     * @param observer The observer object to be added.
     */
    static void Attach(IEntityObserver* observer);

    /**
     * @brief Removes observers from delivery vehicles.
     * 
     * @param observer The observer object to be removed.
     */
    static void Detach(IEntityObserver* observer);

	/**
	 * @brief Update entity with timestep dt
	 */
	virtual void Update(float dt) {}

 protected:
 	static std::vector<IEntityObserver*> observers;
 	picojson::object details_;
};

}  // namespace csci3081


#endif  // ENTITY_BASE_H_
