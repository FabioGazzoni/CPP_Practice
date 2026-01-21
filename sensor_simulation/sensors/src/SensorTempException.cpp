#include "SensorTempException.h"

SensorTempException::SensorTempException(const string &msg) : message(msg){};

const char* SensorTempException::what() const noexcept{
    return message.c_str();
};