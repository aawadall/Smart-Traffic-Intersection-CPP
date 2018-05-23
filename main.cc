
#include "environment.h"
#include "agent.h"

#include <iostream>
#include <iomanip>


int main() {
    Environment env;
    std::vector<Action> actions{0, 1, 2};
    Agent agent(actions);
    
    SimulationSignal result;
    
    Action current_action{0};
    State current_state{0};
    for(unsigned int idx{0}; idx < 5; idx++) {
        current_state = env.GetCurrentState();
        current_action = agent.GetNextMove(current_state);
        
        std::cout << "Simulation: " << idx << std::endl;
        std::cout << "Current Action: " << current_action
                  << " On state : " << current_state << std::endl;
        
        result = env.Simulate(current_action);
        
        std::cout << "New State : " << result.next_state
                  << " Reward : "   << result.reward
                  << std::endl;
    }
    return 0;
}