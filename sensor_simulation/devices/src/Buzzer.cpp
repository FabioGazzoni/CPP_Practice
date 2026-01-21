#include "Buzzer.h"
#include <iostream>
#include "DevicesException.cpp"

using namespace std;

Buzzer::Buzzer(uint16_t pin)
{
    if (pin <= 0 ||
        pin != BUZZ_PIN_1 &&
        pin != BUZZ_PIN_2 &&
        pin != BUZZ_PIN_3 &&
        pin != BUZZ_PIN_4)
    {
        throw DevicesException("Pin de buzzer invalido");
    }
    else
    {
        this->pin = pin;
        buzzer_status = D_OFF;
    }
}

void Buzzer::turnOn()
{
    buzzer_status = D_ON;
}

void Buzzer::turnOff()
{
    buzzer_status = D_OFF;
}

void Buzzer::status()
{
    cout << "El estado del buzzer es " << ((buzzer_status == D_OFF) ? "apagado" : "encendido") << endl;
}