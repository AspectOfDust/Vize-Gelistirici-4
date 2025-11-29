#include <iostream>
#include "Device.h"
#include "FakeLight.h"   // Eðer ayrý dosya açtýysan bunu ekle

using namespace std;

int main()
{
    cout << "=== DEVICE SOYUT SINIFI TESTI BASLIYOR ===" << endl;

    FakeLight light(1, "Oda Lambasi");

    cout << "\n--- Baslangic Durumu ---" << endl;
    light.PrintStatus();

    cout << "\n--- TurnOn() test ---" << endl;
    light.TurnOn();
    light.PrintStatus();

    cout << "\n--- TurnOff() test ---" << endl;
    light.TurnOff();
    light.PrintStatus();

    cout << "\n--- Ariza (SetInactive) test ---" << endl;
    light.SetInactive();
    light.PrintStatus();

    cout << "\n--- Ariza düzeltme (SetActive) test ---" << endl;
    light.SetActive();
    light.PrintStatus();

    cout << "\n=== TEST BITTI ===" << endl;
    return 0;
}