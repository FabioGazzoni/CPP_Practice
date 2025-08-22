#ifndef D_EXCEPTION_H
#define D_EXCEPTION_H

#include <exception>

using namespace std;

class DevicesException : public exception{
    private:
        const char* mensaje;
    public:
        explicit DevicesException(const char *);
        const char* what() const noexcept override;
};

#endif // D_EXCEPTION_H