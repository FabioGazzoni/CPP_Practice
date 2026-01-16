#include <iostream>
#include <opencv2/opencv.hpp>
#include "buffer.h"
#include "camera.h"

cv::Mat convert_gray_scale(cv::Mat &image);
cv::Mat set_kernel_to_image(cv::Mat &in_image, float &kernel, int rows, int cols);
cv::Mat get_canny_border(cv::Mat image, int max_v_grad, int min_v_grad);

int main(int argc, char *argv[])
{
    Camera camera = Camera();

    Buffer buffer = Buffer("camera");

    while (true)
    {
        cv::Mat frame = camera.get_new_image();
        buffer.add_image(frame);

        float kernel[] = {
            0, -1, 0,
            -1, 5, -1,
            0, -1, 0};
        
        cv::Mat gray_image = camera.convert_gray_scale(frame);
        
        cv::imshow("Original", gray_image);
        cv::imshow("Filtered", camera.set_kernel_to_image(gray_image, *kernel, 3, 3));
        cv::Mat image = buffer.pop_image();
        cv::imshow("Buffer", image);
        cv::imshow("Canny", camera.get_canny_border(frame, 100, 200));

        if (cv::waitKey(30) >= 0)
            break; // Exit on any key press
    }

    return 0;
}
