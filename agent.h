/* Basic; Naive Agent */

#pragma once 

#ifndef AGENT
#define AGENT

#include "environment.h"
#include <vector>

class Agent {
  public:
    Agent();
    ~Agent();
    bool Learn(State initial_state, 
               State resulting_state, 
               Action applied_action, 
               Reward reward);
               
    Action GetNextMove(State);
};

#endif // AGENT