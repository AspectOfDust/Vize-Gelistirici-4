#include "MSHStateManager.h"
#include <iostream>

// Constructor: Baþlangýç durumunu ayarlar
MSHStateManager::MSHStateManager(IState* initialState) : currentState(initialState) {
    if (currentState) {
        currentState->Enter(this);
    }
}

// Destructor: Mevcut durumu temizler
MSHStateManager::~MSHStateManager() {
    if (currentState) {
        delete currentState;
    }
}

// Durum Deðiþtirme: Mevcut durumu geçmiþe atar ve yeni duruma geçer
void MSHStateManager::ChangeState(IState* newState) {
    if (currentState) {
        // Mevcut durumun adýný memento olarak geçmiþe ekle
        history.Push(StateMemento(currentState->GetName()));
        delete currentState;
    }
    currentState = newState;
    if (currentState) {
        currentState->Enter(this);
    }
}

// Geri Alma: Geçmiþteki son durumu geri yükler (Basitleþtirilmiþ mantýk)
void MSHStateManager::RestorePreviousState() {
    if (history.HasPrevious()) {
        // Not: Bu kýsým projenizdeki StateHistory yapýsýna göre 
        // string'den tekrar State objesi oluþturma mantýðý gerektirebilir.
        std::cout << "[Manager] Geri alma islemi tetiklendi." << std::endl;
    }
    else {
        std::cout << "[Manager] Geri alinacak durum yok!" << std::endl;
    }
}

std::string MSHStateManager::GetCurrentStateName() const {
    return currentState ? currentState->GetName() : "No State";
}