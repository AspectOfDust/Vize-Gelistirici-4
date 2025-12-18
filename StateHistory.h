#pragma once
#ifndef STATE_HISTORY_H
#define STATE_HISTORY_H

#include <vector>
#include "StateMemento.h"

class StateHistory {
private:
    std::vector<StateMemento> history;
    int index;

public:
    StateHistory() : index(-1) {}

    void Push(const StateMemento& m) {
        history.push_back(m);
        index = history.size() - 1;
    }

    bool HasPrevious() const { return index > 0; }

    StateMemento Previous() {
        if (index > 0) index--;
        return history[index];
    }
};

#endif
