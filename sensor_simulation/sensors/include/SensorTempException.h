#ifndef SENS_TEM_EXCEPTION
#define SENS_TEM_EXCEPTION

#include <exception>
#include <string>

using namespace std;

class SensorTempException : public exception{
    private:
        std::string message;
    public:
        explicit SensorTempException(const string&);
        const char* what() const noexcept override;
};

#endif // SENS_TEM_EXCEPTION