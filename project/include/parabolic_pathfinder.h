/**
 *@file parabolic_pathfinder.h
 */
#ifndef PARABOLIC_PATHFINDER_H_
#define PARABOLIC_PATHFINDER_H_

#include "pathfinder.h"
namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief strategy for the parabolic path for the DeliveryObject implementations.
 */
class ParabolicPathfinder : public Pathfinder {
    public:
        /**
         * @brief Constructor: sets up ParabolicPathfinder by instantiating its values.
         */
        ParabolicPathfinder();

        /**
         * @brief Gets a vector of the points the delivery object must travel to get from the start
         * to the end using the parabolic path strategy.
         * 
         * @param start Starting point.
         * @param end Ending point.
         * 
         * @return Path vector.
         */
        const std::vector< std::vector<float> > GetPath(std::vector<float> start, std::vector<float> end);

        /**
         * @brief Gets the path type.
         *
         * @return Parabolic type.
         */
        std::string GetType();

    private:
        float height = 200;
        std::string type = "parabolic";
};

}//namespace csci3081

#endif    // SMART_PATHFINDER_H_