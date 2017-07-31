#pragma once

#include "debug.h"
#include "opencv2/opencv.hpp"
#include <memory>

struct CirclesByIntensity {
  inline char operator()(unsigned char x) const noexcept {
    static constexpr char map[] = {' ', '.', 'o', '*', 'O', '0', '@'};
    static constexpr int16_t kMapElements = sizeof(map) / sizeof(map[0]);
    const int16_t i = kMapElements * x >> 8;
    DEBUG_ASSERT_LE(0, i);
    DEBUG_ASSERT_LT(i, kMapElements);
    return map[i];
  }
};

/**
 * Converts an image to an Ascii character string.
 *
 * TransformOp   Callable type with signature char(unsigned char).
 *
 * mat                 Single-channel 8-bit input matrix.
 * columns             Columns per line in resulting char array.
 * font_aspect_ratio   Character width / height.
 * transform_op        Function used to transform values from mat to characters.
 *                     Defaults to CirclesByIntensity(), above.
 *
 * Returns a dynamically allocated character array wrapped in a unique_ptr.
 */
template <typename TransformOp = CirclesByIntensity>
std::unique_ptr<char[]> asciiImg(const cv::Mat1b& mat,
                                 const int32_t columns,
                                 const float font_aspect_ratio = 7.0f / 15.0f,
                                 TransformOp transform_op = TransformOp()) {
  if (columns < 1 || mat.rows < 1 || mat.cols < 1) {
    return nullptr;
  }

  const int32_t lines =
      std::max(1, int32_t(font_aspect_ratio * columns * mat.rows / mat.cols));

  // Size = rows * columns + (row count - 1) newlines + null terminator.
  const int32_t text_columns = columns + 1;
  const int64_t num_chars = lines * text_columns;
  std::unique_ptr<char[]> sdata(new char[num_chars]);

  // Make an cv::Mat wrapper around the output character string.
  // Use a stride of text_columns to account for the newline at the end of each
  // row of characters.
  auto* const udata = reinterpret_cast<unsigned char*>(sdata.get());
  cv::Mat1b img(lines, columns, udata, text_columns);

  // Resize the input image into the output wrapper.
  cv::resize(mat, img, img.size(), 0.f, 0.f, cv::INTER_NEAREST);
  DEBUG_ASSERT_EQ((void*)img.data, (void*)udata);

  // Transform the output data according to the TransformOp.
  for (int32_t i = 0; i < img.rows; ++i) {
    char* const sdata_i = sdata.get() + text_columns * i;
    const unsigned char* const img_i = img.ptr<unsigned char>(i);
    for (int32_t j = 0; j < img.cols; ++j) {
      sdata_i[j] = transform_op(img_i[j]);
    }
    sdata_i[img.cols] = '\n';
  }

  // Add null terminator.
  sdata[num_chars] = '\0';

  return sdata;
}
