/**
 *@file pathfinder.h
 */
#ifndef PATHFINDER_H_
#define PATHFINDER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include <EntityProject/facade/common.h>

namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
*  @brief Abstract class for the path finding strategy.
*/
class Pathfinder {
    public:

        /**
         * @brief Returns a vector of the points the object must travel to get from the start
         * to the end using a path strategy.
         * 
         * @param start Starting point.
         *
         * @param end End point.
         * 
         * @return Vector of points for travel.
         */
        virtual const std::vector< std::vector<float> > GetPath(std::vector<float> start, std::vector<float> end) = 0;

        /**
         * @brief Gets path type.
         *
         * @return String describing the type.
         */
        virtual std::string GetType() = 0;
};

}//namespace csci3081

#endif    // PATHFINDER_H_