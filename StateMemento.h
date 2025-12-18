#pragma once
#ifndef STATE_MEMENTO_H
#define STATE_MEMENTO_H

#include <string>

class StateMemento {
private:
    std::string stateName;

public:
    StateMemento(const std::string& name) : stateName(name) {}
    std::string GetSavedState() const { return stateName; }
};

#endif