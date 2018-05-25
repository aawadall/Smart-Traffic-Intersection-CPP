#ifndef SIMULATOR
#define SIMULATOR

#include "environment.h"
// external plugin used to simulate environments 
class Simulator {
    public:
        Simulator();
        ~Simulator();
        SimulationSignal Simulate(State state, Action action);
};
#endif // SIMULATOR