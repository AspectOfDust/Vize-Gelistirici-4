#pragma once
#ifndef PERF_STATE_H
#define PERF_STATE_H

#include "IState.h"

class HighPerfState : public IState {
public:
    std::string GetName() const { return "High Performance"; }

    void Enter(MSHStateManager* context)
    {
        std::cout << "[High_State] Sisteme girildi.\n";
    }
};

#endif