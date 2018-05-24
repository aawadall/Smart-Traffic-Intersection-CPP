
#include "environment.h"
#include "agent.h"
#include "q-agent.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Starting Simulator!!" << endl;
    Environment env;
    
    Agent agent(env.GetActions());
    cout << "Created New Agent : " << agent.GetType() << endl;
    
    QAgent q_agent(env.GetStates(), env.GetActions());
    cout << "Created New Agent : " << q_agent.GetType() << endl;
    
    SimulationSignal result;
    
    Action current_action{0};
    State current_state{0};
    for(unsigned int idx{0}; idx < 99999; idx++) {
        /*
        current_state = env.GetCurrentState();
        current_action = agent.GetNextMove(current_state);
        
        std::cout << "Simulation: " << idx << std::endl;
        std::cout << "Current Action: " << current_action
                  << " On state : " << current_state << std::endl;
        result = env.Simulate(current_action);
        // Invoke Training           
        agent.Learn(current_state, result.next_state, current_action, result.reward);
        */
        
        
        std::cout << "New State : " << result.next_state
                  << " Reward : "   << result.reward
                  << std::endl;
        current_state = env.GetCurrentState();
        current_action = q_agent.GetNextMove(current_state);
        
        std::cout << "Simulation: " << idx << std::endl;
        std::cout << "Current Action: " << current_action
                  << " On state : " << current_state << std::endl;
        
        result = env.Simulate(current_action);
        // Invoke Training           
        q_agent.Learn(current_state, result.next_state, current_action, result.reward);
        
        std::cout << "New State : " << result.next_state
                  << " Reward : "   << result.reward
                  << std::endl;
        
        q_agent.PrintQ();
    }
    return 0;
}