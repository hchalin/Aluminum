cmake_minimum_required(VERSION 3.20)
project(Aluminum LANGUAGES CXX OBJCXX)

if(NOT APPLE)
    message(FATAL_ERROR "Aluminum requires macOS and Apple Metal frameworks.")
endif()

set(CMAKE_CXX_STANDARD 26)

add_executable(Aluminum
        main.cpp
        AluminumAppDelegate.cpp
        AluminumAppDelegate.h
)

target_include_directories(Aluminum PRIVATE
        Backend/metal-cpp
)


target_link_libraries(Aluminum PRIVATE
    "-framework Metal"
    "-framework Foundation"
    "-framework QuartzCore"
    "-framework AppKit"
    "-framework MetalKit"
)
