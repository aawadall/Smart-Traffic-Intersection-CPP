#include "agent.h"
#include <cstdlib>
#include <ctime>
Agent::Agent(std::vector<Action> actions_allowed) :
                    actions = actions_allowed
{
    // TODO
}

Agent::~Agent() {
    // TODO
}

bool Agent::Learn(State initial_state, 
                  State resulting_state, 
                  Action applied_action, 
                  Reward reward) {
                      // TODO
                      return true; 
                  }
                  
Action Agent::GetNextMove(State state) {
    // TODO
    // Naive Agent
    srand(time(0)); // initialize random number seed
    return static_cast<Action>(rand() % actions.length());
}