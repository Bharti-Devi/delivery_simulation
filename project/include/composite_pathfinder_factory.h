/**
 *@file composite_pathfinder_factory.h
 */
#ifndef COMPOSITE_PATHFINDER_FACTORY_H_
#define COMPOSITE_PATHFINDER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pathfinder_factory.h"

namespace csci3081	{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for creating PathfinderFactory objects.
 */
class CompositePathfinderFactory : public PathfinderFactory{
    public:
    	/**
        * @brief Constructor: sets up CompositePathfinderFactory.
        */
        CompositePathfinderFactory();
       	/**
        * @brief Destructor: deletes all manually allocated data.
        * 
        * Calls delete on all of the factories added to it.
        */
        ~CompositePathfinderFactory();
        /**
        * @brief Adds a factory to the PathfinderFactories for later use in the object.
        * 
        * @param factory PathfinderFactory* to add.
        */
        void AddFactory(PathfinderFactory* factory);
        /**
        * @brief Creates a Pathfinder object using it's type.
        * 
        * @param type Type of path.
        *
        * @return Pathfinder* object.
        */
        Pathfinder* CreatePathfinder(std::string type);
        /**
         * @brief Sets the graph of a PathfinderFactory object in the factories vector.
         * 
         * @param graph Input graph to modify the object's graph object.
         */
        void SetGraph(const IGraph* graph);

    private:
        const IGraph* graph;
        std::vector<PathfinderFactory*> factories;
};

}//namespace csci3081

#endif    // COMPOSITE_PATHFINDER_FACTORY.H

