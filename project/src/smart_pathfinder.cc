#include "smart_pathfinder.h"

namespace csci3081 {

SmartPathfinder::SmartPathfinder(const IGraph* graph)	{
    this->graph = graph;
}

const std::vector< std::vector<float> > SmartPathfinder::GetPath(std::vector<float> start, std::vector<float> end){
    return graph->GetPath(start, end);
}

std::string SmartPathfinder::GetType()	{
    return type;
}

}//namespace csci3081