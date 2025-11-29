#pragma once
#ifndef DEVICE_H
#define DEVICE_H

#include <string>

enum PowerState {
    POWER_OFF,
    POWER_ON
};

enum ActiveState {
    ACTIVE,
    INACTIVE
};

class Device {
protected:
    int id;
    std::string name;
    PowerState powerState;
    ActiveState activeState;

public:
    Device(int id, const std::string& name)
        : id(id), name(name), powerState(POWER_OFF), activeState(ACTIVE) {
    }

    virtual ~Device() {}

    int GetId() const { return id; }
    std::string GetName() const { return name; }

    virtual void TurnOn() {
        powerState = POWER_ON;
    }

    virtual void TurnOff() {
        powerState = POWER_OFF;
    }

    PowerState GetPowerState() const { return powerState; }
    ActiveState GetActiveState() const { return activeState; }

    void SetInactive() { activeState = INACTIVE; }
    void SetActive() { activeState = ACTIVE; }

    // Her somut cihaz kendi durum bilgisini yazdýracak
    virtual void PrintStatus() const = 0;

    // Sensör cihazlarýnda kullanýlacak (kamera, duman, gaz)
    virtual void Detect() {}
};

#endif // DEVICE_H