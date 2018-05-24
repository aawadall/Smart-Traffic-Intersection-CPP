#include "agent.h"
#include <cstdlib>
#include <ctime>
Agent::Agent(std::vector<Action> actions_allowed) :
                    actions{actions_allowed},
                    type{"Naive Agent"}
{
    // TODO
}

Agent::~Agent() {
    // TODO
}


std::string Agent::GetType() {
    return type; // Agent Type
}

void Agent::SetType(std::string newType) {
    type = newType;
}