#pragma once
#ifndef SEMI_POWER_STATE_H
#define SEMI_POWER_STATE_H

#include "IState.h"

class LowPowerState : public IState {
public:
    std::string GetName() const { return "Low Power"; }

    void Enter(MSHStateManager* context)
    {
        std::cout << "[Low_State] Sisteme girildi.\n";
    }

};

#endif