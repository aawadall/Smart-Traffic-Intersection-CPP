
#include "environment.h"
#include "agent.h"
#include "q-agent.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Starting Simulator!!" << endl;
    Environment env;
    
    QAgent q_agent(env.GetStates(), env.GetActions());
    cout << "Created New Agent : " << q_agent.GetType() << endl;
    
    cout << "Initializing ..";

    SimulationSignal result;
    cout << "Result Package.."; 
    Action current_action{0};
    cout << "Action Package..";
    State current_state{0};
    cout << "State PAckage.." << endl;

    for(unsigned int idx{0}; idx < 9999; idx++) {
        cout << "Experiment # " << idx << endl;   
        current_state = env.GetCurrentState();

        cout << "Current State: " << current_state << endl;
        cout << "Getting Next Move" << endl;
        current_action = q_agent.GetNextMove(current_state);
        cout << "It was : " << current_action << endl;

        std::cout << "Simulation: " << idx << std::endl;
        std::cout << "Current Action: " << current_action
                  << " On state : " << current_state << std::endl;
        
        result = env.Simulate(current_action);
        // Invoke Training           
        q_agent.Learn(current_state, result.next_state, current_action, result.reward);
        
        std::cout << "New State : " << result.next_state
                  << " Reward : "   << result.reward
                  << std::endl;
    }
    q_agent.PrintQ();
    return 0;
}