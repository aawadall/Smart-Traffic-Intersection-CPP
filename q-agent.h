// Q-Learning Agent

#pragma once

#ifndef Q_AGENT
#define Q_AGENT

#include "agent.h"

class QAgent : public Agent 
{
    public:
        QAgent(std::vector<State> states, std::vector<Action> actions);
        ~QAgent();
        bool Learn(State initial_state, 
                  State resulting_state, 
                  Action applied_action, 
                  Reward reward);
        Action GetNextMove(State state);
    private:
        std::vector<std::vector<double>> Q; //Q-Matrix; State/Action value pair
        double learning_rate;
        double discount_rate;
        double exploration_rate;

};

#endif //Q_AGENT