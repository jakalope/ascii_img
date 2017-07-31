#pragma once

#ifndef NDEBUG

#include <cstdlib>
#include <iostream>

#define DEBUG_ASSERT_LT(x, y)                                                  \
  if (x >= y) {                                                                \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " >= " #y " = " << y << std::endl;           \
    std::abort();                                                              \
  }

#define DEBUG_ASSERT_LE(x, y)                                                  \
  if (x > y) {                                                                 \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " > " #y " = " << y << std::endl;            \
    std::abort();                                                              \
  }

#define DEBUG_ASSERT_EQ(x, y)                                                  \
  if (x != y) {                                                                \
    std::cerr << __FILE__ << ":" << __LINE__ << " assert failure: ";           \
    std::cerr << #x " = " << x << " != " #y " = " << y << std::endl;           \
    std::abort();                                                              \
  }

#else

#define DEBUG_ASSERT_LT(x, y)
#define DEBUG_ASSERT_LE(x, y)
#define DEBUG_ASSERT_EQ(x, y)

#endif
