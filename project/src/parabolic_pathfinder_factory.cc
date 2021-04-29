#include "parabolic_pathfinder_factory.h"
#include "parabolic_pathfinder.h"

namespace csci3081	{

ParabolicPathfinderFactory::ParabolicPathfinderFactory()	{}

Pathfinder* ParabolicPathfinderFactory::CreatePathfinder(std::string type)	{
    return new ParabolicPathfinder();
}

void ParabolicPathfinderFactory::SetGraph(const IGraph* graph)	{
    this->graph = graph;
}

}//namespace csci3081