cmake_minimum_required(VERSION 3.22)
project(ced LANGUAGES CXX)
find_package(CUDAToolkit)
set(CMAKE_CXX_FLAGS "-fopenmp -O3")

add_executable(farao
    farao.cpp
    heat_diffusion_2D.cpp
    farao.h
)