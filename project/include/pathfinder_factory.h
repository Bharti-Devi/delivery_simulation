/**
 *@file pathfinder_factory.h
 */
#ifndef PATHFINDER_FACTORY_H_
#define PATHFINDER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "pathfinder.h"

namespace csci3081	{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Abstract class for the pathfinder factory.
 */
class PathfinderFactory {
    public:

    	/**
         * @brief Creates a Pathfinder object.
         * 
         * Inherits from PathfinderFactory.
         *
         * @param type Path type.
         *
         * @return Pathfinder* object.
         */
        virtual Pathfinder* CreatePathfinder(std::string type) = 0;

        /**
         * @brief Sets the graph of a Pathfinder object.
         * 
         * @param graph Input graph to modify BeelinePathfinderFactory's graph object.
         */
        virtual void SetGraph(const IGraph* graph) = 0;

    private:
        const IGraph* graph;
};

}//namespace csci3081

#endif    // PATHFINDER_FACTORY_H_