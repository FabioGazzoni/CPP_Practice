#include "buffer.h"

Buffer::Buffer(std::string name, int max_values) : buffer(new cv::Mat[max_values])
{
    if (max_values > 0)
    {
        max_size = max_values;
        this->name = name;
    }
    else
        throw std::runtime_error("Error: Negative value provided!");
}

Buffer::~Buffer()
{
    delete[] buffer;
}

void Buffer::add_image(cv::Mat new_image)
{
    if (p_current == max_size - 1 && cant != max_size)
    {
        buffer[0] = new_image;
        p_current = 0;
        cant++;
    }
    else if (cant != max_size)
    {
        buffer[p_current] = new_image;
        p_current++;
        cant++;
    }
    else
        throw std::runtime_error("Error: Add buffer" + name + " is full!");
}

cv::Mat Buffer::pop_image()
{
    if (cant > 0)
    {
        cant--;
        if (p_current == 0 && cant != 0)
        {
            p_current = max_size - 1;
            return buffer[0];
        }
        else if (p_current == 0 && cant == 0)
        {
            p_current = 0;
            return buffer[0];
        }
        else
        {
            p_current--;
            return buffer[p_current];
        }
    }
    throw std::runtime_error("Error: Pop buffer" + name + " is empty!");
}
