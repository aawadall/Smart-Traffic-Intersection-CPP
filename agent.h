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
               Reward reward) {return true;}
               
    virtual Action GetNextMove(State state)  {
        // TODO
        // Naive Agent
        srand(time(0)); // initialize random number seed
        return static_cast<Action>(rand() % actions.size());
    }
    
    std::string GetType();
    protected:
      std::vector<Action> actions; // possible actions
      std::string type; // Stores Agent Type
      void SetType(std::string);
};

#endif // AGENT