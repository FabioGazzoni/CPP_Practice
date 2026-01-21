#ifndef SENSOR_H
#define SENSOR_H
#include <stdint.h>

#define MAX_TEMPERATURE 150.0f
#define MIN_TEMPERATURE -50.5f

class Sensor{
    private:
        uint8_t id;
        float temperature;

    public:
        Sensor(uint8_t id);
        void printValue();
        void readValue();

};

#endif // SENSOR_H