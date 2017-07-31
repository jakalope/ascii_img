#include "ascii_img.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  const cv::Mat1b img(cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE));
  constexpr int cols = 80;
  const auto str = asciiImg(img, cols);
  std::cout << str.get() << std::endl;
  return 0;
}
