#include "smart_pathfinder_factory.h"

namespace csci3081	{

SmartPathfinderFactory::SmartPathfinderFactory()	{}

Pathfinder* SmartPathfinderFactory::CreatePathfinder(std::string type)	{
    return new SmartPathfinder(graph);
}

void SmartPathfinderFactory::SetGraph(const IGraph* graph)	{
    this->graph = graph;
}

}//namespace csci3081