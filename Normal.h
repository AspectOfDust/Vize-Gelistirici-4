#pragma once
#ifndef NORMAL_STATE_H
#define NORMAL_STATE_H

#include "IState.h"

class NormalState : public IState {
public:
    std::string GetName() const { return "Normal"; }

    void Enter(MSHStateManager* context)
    {
        std::cout << "[NormalState] Sisteme girildi.\n";
    }
};

#endif