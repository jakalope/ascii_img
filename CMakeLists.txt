cmake_minimum_required(VERSION 2.8)
project(ascii_img)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(LIBRARY_SRC
    include/ascii_img.h
  )

include_directories(include)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# add_library(${PROJECT_NAME} ${LIBRARY_SRC})
# target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

#
# EXAMPLES
#

add_executable(img_to_ascii example/img_to_ascii.cpp)
target_link_libraries(img_to_ascii ${OpenCV_LIBS})

add_executable(video_to_ascii example/video_to_ascii.cpp)
target_link_libraries(video_to_ascii ${OpenCV_LIBS})

#
# TESTS
#

enable_testing()

add_executable(ascii_img_test test/ascii_img_test.cpp)
target_link_libraries(ascii_img_test ${OpenCV_LIBS})

add_test(ascii_img_test_case ascii_img_test)
