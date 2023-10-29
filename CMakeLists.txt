cmake_minimum_required(VERSION 3.10)

project(AllCppSolutions)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ALL_CPP_FILES *.cpp)

#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

foreach(FILE ${ALL_CPP_FILES})
    get_filename_component(FILENAME ${FILE} NAME_WE)
    add_executable(${FILENAME} ${FILE})
    # target_link_libraries(${FILENAME} ${OpenCV_LIBS})
endforeach()

