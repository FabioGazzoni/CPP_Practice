#include "LED.h"
#include <iostream>
#include "DevicesException.h"

using namespace std;

LED::LED(uint16_t pin)
{
    if (pin < 0 ||
        pin != LED_PIN_1 &&
        pin != LED_PIN_2 &&
        pin != LED_PIN_5 &&
        pin != LED_PIN_9){
            throw DevicesException("Pin de led inapropiado");
        }
        led_status = D_OFF;
}

void LED::turnOn()
{
    led_status = D_ON;
}

void LED::turnOff()
{
    led_status = D_OFF;
}

void LED::toggle()
{
    led_status = (led_status == D_ON) ? D_OFF : D_ON;
}

void LED::status()
{
    cout << "El estado del led es " << ((led_status == D_OFF) ? "apagado" : "encendido") << endl;
}