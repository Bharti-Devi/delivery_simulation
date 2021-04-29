/**
 *@file beeline_pathfinder_factory.h
 */
#ifndef BEELINE_PATHFINDER_FACTORY_H_
#define BEELIN_PATHFINDER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "pathfinder_factory.h"

namespace csci3081	{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Beeline Pathfinder factory that creates BeelinePathfinder objects.
 */
class BeelinePathfinderFactory : public PathfinderFactory {
    public:
        
        /**
         * @brief Constructor: sets up BeelinePathfinderFactory.
         */
        BeelinePathfinderFactory();
        
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

#endif    // BEELINE_PATHFINDER_FACTORY_H_