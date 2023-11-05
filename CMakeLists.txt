cmake_minimum_required(VERSION 3.10)

project(AllCppSolutions)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ALL_CPP_FILES *.cpp)

## OpenCV
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
foreach(FILE ${ALL_CPP_FILES})
    get_filename_component(FILENAME ${FILE} NAME_WE)
    add_executable(${FILENAME} ${FILE})
    target_link_libraries(${FILENAME} gtest)
endforeach()


# copy test data
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
