#ifndef BUFFER_H
#define BUFFER_H

#include <opencv2/opencv.hpp>
#include <stdexcept>
#include <string>

class Buffer
{
private:
    cv::Mat *buffer;
    std::string name;
    int max_size;
    int p_current = 0;
    int cant = 0;
public:
    enum status_err
    {
        EX_ERROR,
        EX_OK
    };

    Buffer(std::string name, int max_size = 10);
    ~Buffer();
    void add_image(cv::Mat new_image);
    cv::Mat pop_image();
};

#endif // BUFFER_H
