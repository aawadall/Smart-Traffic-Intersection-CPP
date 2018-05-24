#include "q-agent.h"

QAgent::QAgent(std::vector<State> states, std::vector<Action> actions) :
                            type{"Q-Learning"} ,
                            learning_rate{0.3},
                            discount_rate{0.9},
                            exploration_rate{0.001},
                            Agent(actions)
{
    // TODO - Construct Q-Matrix
}

QAgent::~QAgent()) {
    // TODO
} 

bool Agent::Learn(State initial_state, 
                  State resulting_state, 
                  Action applied_action, 
                  Reward reward) {
                      // TODO - Update Q-Matrix
                      return true; 
                  }
                  
Action Agent::GetNextMove(State state) {
    // TODO - return best action in state row or explore
    srand(time(0)); // initialize random number seed
    return static_cast<Action>(rand() % actions.size());
}
