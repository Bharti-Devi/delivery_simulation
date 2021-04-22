#include "beeline_pathfinder_factory.h"
#include "beeline_pathfinder.h"

namespace csci3081	{

BeelinePathfinderFactory::BeelinePathfinderFactory()	{}

Pathfinder* BeelinePathfinderFactory::CreatePathfinder(std::string type)	{
    return new BeelinePathfinder();
}

void BeelinePathfinderFactory::SetGraph(const IGraph* graph)	{
    this->graph = graph;
}

}//namespace csci3081