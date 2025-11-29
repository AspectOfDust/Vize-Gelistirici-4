#pragma once
#ifndef ISTATE_H
#define ISTATE_H
#include <iostream>
#include <string>

class MSHStateManager;

class IState { //yani ne anlatam
public:
    virtual ~IState() {}
    virtual std::string GetName() const = 0;
    virtual void Enter(MSHStateManager* context) = 0;
};

#endif