#ifndef CAMERA_H
#define CAMERA_H

#include <thread>
#include <opencv2/opencv.hpp>
#include <stdexcept>

class Camera
{
private:
    static cv::VideoCapture cam;
    bool with_windows;
public:
    Camera(bool with_windows = 1);
    cv::Mat get_new_image();
    cv::Mat convert_gray_scale(cv::Mat &image);
    cv::Mat set_kernel_to_image(cv::Mat &in_image, float &kernel, int rows, int cols);
    cv::Mat get_canny_border(cv::Mat image, int max_v_grad, int min_v_grad);
};
#endif // CAMERA_H
