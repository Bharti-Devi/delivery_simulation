#include "composite_pathfinder_factory.h"

namespace csci3081{

CompositePathfinderFactory::CompositePathfinderFactory()    {}

CompositePathfinderFactory::~CompositePathfinderFactory()   {
    for (int i = 0; i < factories.size(); i++)   {
        delete factories[i];
    }
}

void CompositePathfinderFactory::AddFactory(PathfinderFactory* factory) {
    factories.push_back(factory);
}

Pathfinder* CompositePathfinderFactory::CreatePathfinder(std::string type)  {
    Pathfinder* returnValue;
    Pathfinder* tempval;

    // Iterates over every factory to ensure Id's are updated correctly
    // rather then returning the first correct value.
    for (int i = 0; i < factories.size(); i++)  {
        tempval = factories[i]->CreatePathfinder(type);

        if (tempval->GetType() == type) {
            returnValue = factories[i]->CreatePathfinder(type);
            // Deletes the tempval so that there are no memory leaks.
            delete tempval;
        }
        else    {
            // Deletes the tempval so that there are no memory leaks.
            delete tempval;
        }
    }

    return returnValue;
}

void CompositePathfinderFactory::SetGraph(const IGraph* graph)  {
    for (int i = 0; i < factories.size(); i++)  {
        factories[i]->SetGraph(graph);
    }
    
    this->graph = graph;
}

}//namespace csci3081