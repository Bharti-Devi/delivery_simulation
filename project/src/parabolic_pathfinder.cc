#include "parabolic_pathfinder.h"

namespace csci3081{

ParabolicPathfinder::ParabolicPathfinder(){}

const std::vector< std::vector<float> > ParabolicPathfinder::GetPath(std::vector<float> end, std::vector<float> start)  {
    std::vector< std::vector<float> > returnVector;
    returnVector.push_back(end);

    start[1] = start[1] + 50;
    end[1] = end[1] + 50;
    returnVector.push_back(end);

    for (int i = 100; i >= 0; i--)  {
        std::vector<float> temp;

        float x = start[0] + (end[0]-start[0])*(i/100.000);
        float y = (4*height - 2*start[1] - 2*end[1])*((i/100.00)*(i/100.000)) + (-4*height + 3*start[1]+end[1])*(i/100.00) + start[1];
        float z = start[2] + (end[2]-start[2])*(i/100.000);

        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        returnVector.push_back(temp);
    }

    start[1] = start[1] -50;
    returnVector.push_back(start);

    return returnVector;
}

std::string ParabolicPathfinder::GetType()  {
    return type;
}

}//namespace csci3081