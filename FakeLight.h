#pragma once
#ifndef FAKELIGHT_H
#define FAKELIGHT_H

#include "Device.h"
#include <iostream>

class FakeLight : public Device {
public:
    FakeLight(int id, const std::string& name)
        : Device(id, name) {
    }

    void PrintStatus() const {
        std::cout
            << "[FakeLight] ID: " << id
            << ", Name: " << name
            << ", Power: " << (powerState == POWER_ON ? "ON" : "OFF")
            << ", Active: " << (activeState == ACTIVE ? "ACTIVE" : "INACTIVE")
            << std::endl;
    }
};

#endif