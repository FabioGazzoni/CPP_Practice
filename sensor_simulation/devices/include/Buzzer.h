#ifndef BUZZER_H
#define BUZZER_H

#include "Device.h"
#include <cstdint>

#define BUZZ_PIN_1 1
#define BUZZ_PIN_2 2
#define BUZZ_PIN_3 3
#define BUZZ_PIN_4 4

class Buzzer: public Device{
    private:
    device_status buzzer_status;
    uint16_t pin;
    
    public:
    Buzzer(uint16_t);
    void turnOn();
    void turnOff();
    void status();
};


#endif // BUZZER_H