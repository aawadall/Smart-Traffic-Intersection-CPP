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

bool Agent::Learn(State initial_state, 
               State resulting_state, 
               Action applied_action, 
               Reward reward) {return true;}
               
Action Agent::GetNextMove(State state)  {
        
        // Naive Agent
        srand(time(0)); // initialize random number seed
        return static_cast<Action>(rand() % actions.size());
    }