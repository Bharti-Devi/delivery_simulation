/**
 *@file parabolic_pathfinder_factory.h
 */
#ifndef PARABOLIC_PATHFINDER_FACTORY_H_
#define PARABOLIC_PATHFINDER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "pathfinder_factory.h"

namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Parabolic Pathfinder factory that creates ParabolicPathfinder objects.
 */
class ParabolicPathfinderFactory : public PathfinderFactory {
    public:
    	/**
    	 * @brief Constructor: sets up ParabolicPathfinderFactory.
    	 */
        ParabolicPathfinderFactory();

        /**
         * @brief Creates a Pathfinder object.
         * 
         * Inherits from PathfinderFactory.
         *
         * @param type Path type.
         *
         * @return Pathfinder* object.
         */
        Pathfinder* CreatePathfinder(std::string type);

        /**
         * @brief Sets the graph of a Pathfinder object.
         * 
         * @param graph Input graph to modify BeelinePathfinderFactory's graph object.
         */
        void SetGraph(const IGraph* graph);

    private:
        const IGraph* graph;
};

}//namespace csci3081

#endif    // PARABOLIC_PATHFINDER_FACTORY_H_