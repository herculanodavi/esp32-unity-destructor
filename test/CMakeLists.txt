cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(IDF_TARGET "esp32s3")

set(EXTRA_COMPONENT_DIRS "../components")
set(TEST_COMPONENTS "raii")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(components_test_app)
