#include "environment.h"
#include <cstdlib>
#include <ctime>
#include <random>
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
    static std::default_random_engine engine{static_cast<unsigned int>(time(0))};
    /* TODO: Figure out how to extract first and last states
    std::vector<Action>::iterator start{states.begin()};
    std::vector<Action>::iterator end{states.end()};
    int idx1{std::distance( states.begin(), start )};
    int idx2{std::distance( states.end(), end )};
    */
    std::uniform_int_distribution<unsigned int> randomStates{0, 4};
    std::uniform_real_distribution<double> genericRand{-5 , 5};
                                                            
   
    SimulationSignal result;
    previous_state = active_state;
    active_state = static_cast<State>(randomStates(engine));
    current_reward = static_cast<Reward>(genericRand(engine)) 
            + static_cast<int>(active_state) == static_cast<int>(action) ? 
                            1.0 : -0.1 ; 
                     
    result.next_state = active_state;
    result.reward = current_reward;
    
    return result;
}

// TODO : Add Random Number Generator here to be a static method 