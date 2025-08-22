#include "DevicesException.h"

using namespace std;

DevicesException::DevicesException(const char *msg) : mensaje(msg) {}

const char *DevicesException::what() const noexcept
{
    return mensaje;
}
