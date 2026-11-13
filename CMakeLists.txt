cmake_minimum_required(VERSION 3.20)
project(Kinetis LANGUAGES CXX OBJCXX)

if(NOT APPLE)
    message(FATAL_ERROR "Kinetis requires macOS and Apple Metal frameworks.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Kinetis
    main.cpp
        KinetisAppDelegate.cpp
        KinetisAppDelegate.h
        KinetisViewDelegate.cpp
        KinetisViewDelegate.h
    MetalCppImplementation.cpp
        Renderer.cpp
        Renderer.h
)

# Pre compile shaders
# Process the Shaders directory
add_subdirectory(Shaders)

# Ensure Metal shaders are built with Aluminum
add_dependencies(Kinetis KinetisShaders)

# Provide compiled shader library path to C++
target_compile_definitions(Kinetis PRIVATE
        KINETIS_METALLIB_PATH=\"${KINETIS_METALLIB}\"
)

target_include_directories(Kinetis PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Backend/metal-cpp
)

find_package(Chrono REQUIRED CONFIG)


target_link_libraries(Kinetis PRIVATE
    "-framework Metal"
    "-framework Foundation"
    "-framework QuartzCore"
    "-framework AppKit"
    "-framework MetalKit"
        ${CHRONO_TARGETS}
)
