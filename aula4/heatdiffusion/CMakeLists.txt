# CMakeLists.txt
# cmake ~/ipbeja_ced/aula4/heatdiffusion
# cmake --build .

cmake_minimum_required(VERSION 3.22)
project(heat_diffusion LANGUAGES C)
find_package(CUDAToolkit)
set(CMAKE_C_FLAGS "-fopenmp")

add_executable(heat_diffusion 
    heat_diffusion.c
)
