cmake_minimum_required(VERSION 2.8.3)
project(eigen_cpp0x)

# Find Eigen3
find_package(PkgConfig)
pkg_check_modules(EIGEN3 eigen3)
add_definitions(${EIGEN3_CFLAGS_OTHER})
include_directories(${EIGEN3_INCLUDE_DIRS})

add_definitions(--std=c++0x)

## Declare a cpp executable
add_executable(${PROJECT_NAME} src/main.cpp)
