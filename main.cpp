#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Projenizdeki baþlýk dosyalarýný dahil ediyoruz
// Not: Bu dosyalarýn ayný klasörde olduðu varsayýlmýþtýr.
#include "Device.h"
#include "FakeLight.h"
#include "IState.h"
#include "Normal.h"
#include "Sleepy.h"
#include "Perfect.h"
#include "Semi_Perfect.h"
#include "MSHStateManager.h"

// --- Yardýmcý Fonksiyon: Baþlýk Yazdýrýcý ---
void PrintHeader(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main() {
    try {
        PrintHeader("AKÝLLÝ CÝHAZ YONETÝM SÝSTEMÝ TESTÝ");

        // 1. Cihaz Oluþturma (Polymorphism Testi)
        // FakeLight bir Device'dýr.
        FakeLight salonLambasi(101, "Salon Lambasi");
        std::cout << "[1] Cihaz olusturuldu: " << salonLambasi.GetName() << std::endl;
        salonLambasi.PrintStatus();

        // 2. State Manager Kurulumu
        // Baþlangýç durumu olarak NormalState atýyoruz.
        PrintHeader("STATE GEÇÝÞLERÝ VE MEMENTO TESTÝ");

        MSHStateManager manager(new NormalState());
        std::cout << "Mevcut Durum: " << manager.GetCurrentStateName() << std::endl;

        // 3. Farklý Durumlara Geçiþ
        std::cout << "\n--- Durum Degistiriliyor: High Performance ---" << std::endl;
        manager.ChangeState(new HighPerfState());

        std::cout << "\n--- Durum Degistiriliyor: Sleep ---" << std::endl;
        manager.ChangeState(new SleepState());

        std::cout << "\n--- Durum Degistiriliyor: Low Power ---" << std::endl;
        manager.ChangeState(new LowPowerState());

        std::cout << "\nMevcut Son Durum: " << manager.GetCurrentStateName() << std::endl;

        // 4. Undo (Geri Al) Mekanizmasý Testi
        PrintHeader("GERI ALMA (HISTORY) TESTI");

        std::cout << "[Geri Al 1] Bir önceki duruma donuluyor..." << std::endl;
        manager.RestorePreviousState();
        std::cout << "Yeni Durum: " << manager.GetCurrentStateName() << std::endl;

        std::cout << "\n[Geri Al 2] Bir onceki duruma donuluyor..." << std::endl;
        manager.RestorePreviousState();
        std::cout << "Yeni Durum: " << manager.GetCurrentStateName() << std::endl;

        // 5. Cihaz Güç ve Aktiflik Testi
        PrintHeader("CIHAZ KONTROL TESTI");

        std::cout << "Lamba açiliyor ve pasif hale getiriliyor..." << std::endl;
        salonLambasi.TurnOn();
        salonLambasi.SetInactive();
        salonLambasi.PrintStatus();

        std::cout << "Lamba kapatiliyor..." << std::endl;
        salonLambasi.TurnOff();
        salonLambasi.PrintStatus();

        PrintHeader("TEST TAMAMLANDI");

    }
    catch (const std::exception& e) {
        std::cerr << "HATA OLUÞTU: " << e.what() << std::endl;
    }

    return 0;
}