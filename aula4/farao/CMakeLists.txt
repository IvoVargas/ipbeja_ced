# CMakeLists.txt
# cmake ~/ipbeja_ced/aula4
# cmake --build .

cmake_minimum_required(VERSION 3.22)
project(ced LANGUAGES C)
find_package(CUDAToolkit)
set(CMAKE_C_FLAGS "-fopenmp")

add_executable(farao 
    farao.c
    f.c
    soma_integral.c
    farao.h
)