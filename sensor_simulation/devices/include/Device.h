#ifndef DEVICE_H
#define DEVICE_H

enum device_status
{
    D_ON = 0,
    D_OFF
};

class Device {
public:
    virtual ~Device() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void status() = 0;
};

#endif // DEVICE_H
