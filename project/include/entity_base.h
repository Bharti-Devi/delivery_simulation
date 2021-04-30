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
#include "json_helper.h"

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
	 * @brief Set some key in the details of the entity
	 * 
	 * @param key Key to set
	 * 
	 * @param value Value to set key to
	 */
	virtual void SetDetailsKey(const std::string& key, const picojson::value& value);

	/**
	 * @brief Notify all observers that the details of this entity have changed
	 */
	virtual void NotifyDetailsUpdate();

	/**
	 * @brief Update entity with timestep dt
	 */
	virtual void Update(float dt) {}

	// Details of object. Moved to public because base classes don't trust derived classes to access their protected members,
	// and this got in the way of decorator pattern implementation ;(
	// picojson::object details_;

 protected:
 	static std::vector<IEntityObserver*> observers;
	picojson::object details_;
};

}  // namespace csci3081


#endif  // ENTITY_BASE_H_
