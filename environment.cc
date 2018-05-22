#include "environment.h"
#include <cstdlib>
#include <ctime>

// Mock Constructor/destructor 
Environment::Environment() : states{0, 1, 2, 3, 4},
                             actions{0, 1, 2} {
    
}
Environment::~Environment() {
    
}
State Environment::GetCurrentState() {
    return active_state;
}

SimulationSignal Environment::Simulate(Action action) {
    // Stub, to be replaced with real simulation engine 
    srand(time(0)); // initialize random number seed
    SimulationSignal result;
    previous_state = active_state;
    active_state = static_cast<State>(rand()% states.size());
    current_reward = static_cast<double>(rand() % 1000) / 1000 - 0.5; 
                                                // simulating +/- 0.5 
    result.next_state = active_state;
    result.reward = current_reward;
    
    return result;
}