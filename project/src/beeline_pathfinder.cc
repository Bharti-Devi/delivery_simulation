#include "beeline_pathfinder.h"

namespace csci3081  {

BeelinePathfinder::BeelinePathfinder()  {}

const std::vector< std::vector<float> > BeelinePathfinder::GetPath(std::vector<float> end, std::vector<float> start)    {
    std::vector< std::vector<float> > returnVector;
    returnVector.push_back(end);
    end[1] = end[1] + height;
    returnVector.push_back(end);
    std::vector<float> temp = start;
    temp[1] = temp[1] + height;
    returnVector.push_back(temp);
    returnVector.push_back(start);
    return returnVector;
}

std::string BeelinePathfinder::GetType()    {
    return type;
}

}//namespace csci3081