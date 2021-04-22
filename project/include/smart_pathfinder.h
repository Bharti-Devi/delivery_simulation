/**
 *@file smart_pathfinder.h
 */
#ifndef SMART_PATHFINDER_H_
#define SMART_PATHFINDER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pathfinder.h"

namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Strategy for the smart path for the DeliveryObject implementations.
 */
class SmartPathfinder : public Pathfinder {
    public:
        /**
         * @brief Constructor: sets up SmartPathfinder by instantiating its values.
         */
        SmartPathfinder(const IGraph* graph);

        /**
         * @brief Returns a vector of the points the delivery object must travel to get from the start
         * to the end using the smart path strategy.
         * 
         * @param start Starting point.
         * @param end Ending point.
         * 
         * @return Vector of points for travel.
         */
        const std::vector< std::vector<float> > GetPath(std::vector<float> start, std::vector<float> end);

        /**
         * @brief Gets path type.
         *
         * @return String describing the type.
         */
        std::string GetType();
    private:
        const IGraph* graph;
        std::string type = "smart";
};

}//namespace csci3081

#endif    // SMART_PATHFINDER_H_