#pragma once
#ifndef MSH_STATE_MANAGER_H
#define MSH_STATE_MANAGER_H

#include <string>
#include "IState.h"
#include "StateHistory.h"

class MSHStateManager {
private:
    IState* currentState;
    StateHistory history;

public:
    MSHStateManager(IState* initialState);
    ~MSHStateManager();

    void ChangeState(IState* newState);
    void RestorePreviousState();

    std::string GetCurrentStateName() const;
};

#endif
