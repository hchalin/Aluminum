cmake_minimum_required(VERSION 3.20)
project(Aluminum LANGUAGES CXX OBJCXX)

if(NOT APPLE)
    message(FATAL_ERROR "Aluminum requires macOS and Apple Metal frameworks.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Aluminum
    main.cpp
    AluminumAppDelegate.cpp
    AluminumAppDelegate.h
    AluminumViewDelegate.cpp
    AluminumViewDelegate.h
    MetalCppImplementation.cpp
        Renderer.cpp
        Renderer.h
)

target_include_directories(Aluminum PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Backend/metal-cpp
)

find_package(Chrono REQUIRED CONFIG)


target_link_libraries(Aluminum PRIVATE
    "-framework Metal"
    "-framework Foundation"
    "-framework QuartzCore"
    "-framework AppKit"
    "-framework MetalKit"
        ${CHRONO_TARGETS}
)
