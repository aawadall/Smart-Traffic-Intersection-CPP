/* Environment class, should interact with Agent(s) */
#pragma once 
#ifndef ENVIRONMENT
#define ENVIRONMENT

#include <vector> 

// Important concepts 
typedef unsigned int State; // Basic state type, might be promoted later on to its own class 
typedef unsigned int Action; // Basic action type, might be promoted later on to its own class 
typedef double Reward; // Basic reward type, might be promoted later on to its own class 

struct SimulationSignal {
    State next_state;
    Reward reward;
};

class Environment {
    public:
        Environment();
        ~Environment();
        State GetCurrentState();
        SimulationSignal Simulate(Action);
        
    private:
        std::vector<State> states; // possible states
        std::vector<Action> actions; // possible actions
        State active_state; 
        State previous_state;
        Reward current_reward;
};

#endif // ENVIRONMENT