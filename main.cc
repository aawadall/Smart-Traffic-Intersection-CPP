
#include "environment.h"

#include <iostream>
#include <iomanip>

int main() {
    Environment env;
    SimulationSignal result;
    result = env.Simulate(1);
    
    std::cout << "New State : " << result.next_state
              << " Reward : "   << result.reward
              << std::endl;
    return 0;
}