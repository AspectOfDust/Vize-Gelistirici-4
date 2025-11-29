#pragma once
#ifndef SLEEP_STATE_H
#define SLEEP_STATE_H

#include "IState.h"

class SleepState : public IState {
public:
    std::string GetName() const { return "Sleep"; }

    void Enter(MSHStateManager* context)
        {
                std::cout << "[Sleep_State] Sisteme girildi.\n";
        }
};

#endif