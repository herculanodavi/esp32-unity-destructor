# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(IDF_TARGET "esp32s3")

set(COMPONENTS "main")


include($ENV{IDF_PATH}/tools/cmake/project.cmake)
add_compile_options(-fdiagnostics-color=always)
project(template)
