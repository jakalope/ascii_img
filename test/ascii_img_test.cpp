#include "ascii_img.h"
#include <iostream>

#define EXPECT_TRUE(x)                                                         \
  do {                                                                         \
    if (!(x)) {                                                                \
      std::cerr << __FILE__ << ":" << __LINE__ << " failure: " << #x           \
                << std::endl;                                                  \
      return false;                                                            \
    }                                                                          \
  } while (false);

#define EXPECT_LT(x, y)                                                        \
  if (x >= y) {                                                                \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " >= " #y " = " << y << std::endl;           \
    return false;                                                              \
  }

#define EXPECT_LE(x, y)                                                        \
  if (x > y) {                                                                 \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " > " #y " = " << y << std::endl;            \
    return false;                                                              \
  }

#define EXPECT_EQ(x, y)                                                        \
  if (x != y) {                                                                \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " != " #y " = " << y << std::endl;           \
    return false;                                                              \
  }

size_t nullTerminatedLength(const std::unique_ptr<char[]>& in) {
  size_t length = 0;
  if (in == nullptr) {
    return 0;
  }
  while (in[length] != '\0') {
    ++length;
  }
  return length;
}

bool testNullTermLen() {
  {
    std::unique_ptr<char[]> a(new char[5]);
    a[0] = a[1] = a[2] = a[3] = 'a';
    a[4] = '\0';
    EXPECT_TRUE(nullTerminatedLength(a) == 4);
  }
  return true;
}

bool testAsciiImgLen() {
  {
    int rows = 2;
    int cols = 5;
    auto mat = cv::Mat1b::zeros(rows, cols);
    size_t length = nullTerminatedLength(asciiImg(mat, cols, 1.0f));
    EXPECT_EQ(length, rows * (cols + 1));
  }
  return true;
}

int main(int argc, char** argv) {
  bool success = true;
  success = success && testNullTermLen();
  success = success && testAsciiImgLen();
  std::cout << (success ? "success\n" : "fail\n");
  return !success;
}
