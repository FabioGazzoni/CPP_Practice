#ifndef LED_H
#define LED_H

#include "Device.h"
#include <cstdint>

#define LED_PIN_1 1
#define LED_PIN_2 2
#define LED_PIN_5 5
#define LED_PIN_9 9

class LED : public Device
{
private:
    device_status led_status;
    uint16_t pin;
public:
    LED(uint16_t);
    void turnOn();
    void turnOff();
    void toggle();
    void status();
};

#endif // LED_H
