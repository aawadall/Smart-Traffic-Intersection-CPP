/* Basic; Naive Agent */

#pragma once 

#ifndef AGENT
#define AGENT

#include "environment.h"
#include <vector>
#include <string>

class Agent {
  public:
    Agent(std::vector<Action>);
    ~Agent();
    virtual bool Learn(State initial_state, 
               State resulting_state, 
               Action applied_action, 
               Reward reward);
               
    virtual Action GetNextMove(State state);
    
    std::string GetType();
    protected:
      std::vector<Action> actions; // possible actions
      std::string type; // Stores Agent Type
      void SetType(std::string);
};

#endif // AGENT