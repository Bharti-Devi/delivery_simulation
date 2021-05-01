/**
 *@file beeline_pathfinder.h
 */
#ifndef BEELINE_PATHFINDER_H_
#define BEELINE_PATHFINDER_H_

#include "pathfinder.h"
namespace csci3081  {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
*  @brief Strategy for the beeline path for the DeliveryObject implementations.
*/
class BeelinePathfinder : public Pathfinder {
    public:
        
        /**
         * @brief Constructor: sets up BeelinePathfinder by instantiating its values.
         */
        BeelinePathfinder();
        
        /**
         * @brief Returns a vector of the points the DeliveryObject must travel to get from the start
         * to the end using the beeline path strategy.
         * 
         * @param start Starting point.
         *
         * @param end End point.
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
        float height = 200;
        std::string type = "beeline";
};

}//namespace csci3081

#endif    // BEELINE_PATHFINDER_H_ 