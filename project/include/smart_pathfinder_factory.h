/**
 *@file smart_pathfinder_factory.h
 */
#ifndef SMART_PATHFINDER_FACTORY_H_
#define SMART_PATHFINDER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "pathfinder_factory.h"
#include "smart_pathfinder.h"

namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 *  @brief Smart Pathfinder factory.
 */
class SmartPathfinderFactory : public PathfinderFactory {
    public:
        /**
         * @brief Constructor: sets up SmartPathfinderFactory.
         */
        SmartPathfinderFactory();

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
         * @param graph Input graph to modify SmartPathfinderFactory's graph object.
         */
        void SetGraph(const IGraph* graph);
        
    private:
        const IGraph* graph;
};

}//namespace csci3081

#endif    // SMART_PATHFINDER_FACTORY_H_