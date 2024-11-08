/*
HPC
integral_b.c
Ivo Vargas
2024-11-08

Compilar:
nvc++ integral_b.c -fopenmp -o integral_b.o

Compilar com makefile:


Exemplo de integral para calcular areas
*/
#include <stdio.h>
#include <math.h>
#include <omp.h>
// #include <unistd.h> biblioteca da função sleep()

extern f(double);

int main()
{
    int tid = omp_get_thread_num();
    printf("Thread id = %f\n", tid);

    return 0;
}