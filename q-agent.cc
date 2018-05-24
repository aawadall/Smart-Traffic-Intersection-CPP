#include "q-agent.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

QAgent::QAgent(std::vector<State> states, std::vector<Action> actions) :
                            learning_rate{0.3},
                            discount_rate{0.9},
                            exploration_rate{0.001},
                            Agent(actions)
{
    SetType("Q-Learning");
    // TODO - Construct Q-Matrix
    double default_value{0.0f};
    Q.resize(states.size()); // Set height 
    for(unsigned int idx{0}; idx < states.size(); idx++) // Set Width
        Q[idx].resize(actions.size(), default_value);
    
}

QAgent::~QAgent() {
    // TODO
} 

bool QAgent::Learn(State initial_state, 
                  State resulting_state, 
                  Action applied_action, 
                  Reward reward) {
  
  // Find Maximum value for the new state 
  std::vector<double>::iterator q_max{std::max_element(Q[resulting_state].begin(),
                                                       Q[resulting_state].end())};
  double max_value{std::distance(Q[resulting_state].begin(), q_max)};
  
  Q[initial_state][applied_action] = 
        (1-learning_rate) * Q[initial_state][applied_action] +
        learning_rate * ( reward + discount_rate * max_value);
  
  return true; 
}
                  
Action QAgent::GetNextMove(State state) {
    // TODO - return best action in state row or explore
    srand(time(0)); // initialize random number seed
    return static_cast<Action>(rand() % actions.size());
}

void QAgent::PrintQ() {
    unsigned int state_space{Q.size()},
                 action_space{Q[0].size()};
        
    std::cout << "Printing Q Matrix Values " << std::endl;
    for (unsigned int idx{0}; idx < state_space; idx++) {
        std::cout << std::endl;
        for(unsigned int jdx{0}; jdx < action_space; jdx++) {
            std::cout << std::setw(6) 
                      << std::setprecision(3) 
                      << Q[idx][jdx];
        }
    }
    std::cout << std::endl;
}