#include "camera.h"

cv::VideoCapture Camera::cam(0);

Camera::Camera(bool with_windows)
{
    // cam = cv::VideoCapture(0);
    if (!cam.isOpened())
    {
        throw std::runtime_error("Error: Could not open camera!");
    }

    this->with_windows = with_windows;
    if (this->with_windows)
        cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
}

cv::Mat Camera::get_new_image()
{
    cv::Mat frame;
    cam >> frame;
    if (frame.empty())
    {
        throw std::runtime_error("Error: Could not read frame!");
    }
    return frame;
}

cv::Mat Camera::convert_gray_scale(cv::Mat &image)
{
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    return gray_image;
}

cv::Mat Camera::set_kernel_to_image(cv::Mat &in_image, float &kernel, int rows, int cols)
{
    cv::Mat out_image;
    cv::Mat k = (cv::Mat_<float>(3, 3) << 0, -1, 0,
                 -1, 5, -1,
                 0, -1, 0);
    cv::filter2D(in_image, out_image, -1, k);
    return out_image;
}

cv::Mat Camera::get_canny_border(cv::Mat image, int max_v_grad, int min_v_grad)
{
    cv::Mat canny;
    cv::Canny(image, canny, max_v_grad, min_v_grad);
    return canny;
}
