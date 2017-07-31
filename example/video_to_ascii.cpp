#include "ascii_img.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::VideoCapture cap(0);
  if (!cap.isOpened()) {
    return -1;
  }

  constexpr int cols = 80;
  cv::Mat3b bgr;
  cv::Mat1b grey;
  for (;;) {
    cap >> bgr;
    cv::cvtColor(bgr, grey, cv::COLOR_BGR2GRAY);
    std::cout << asciiImg(grey, cols).get() << std::endl;
  }
  return 0;
}
