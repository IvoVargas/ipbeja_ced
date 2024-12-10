/*
* CED - Aula 8
* Ivo Vargas
* 10 dezembro de 2024
*
* testes com target
*/

#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

int main() {
    std::cout << "10 dezembro de 2024" << std::endl;

#ifdef _OPENMP
#pragma omp parallel
{
    // o número de threads
    int num_threads = omp_get_num_threads();
    int tid = omp_get_thread_num();
    if (tid == 23)
    {
        std::cout << "Número de threads: " << num_threads << std::endl;
    }
}
#endif

// Com critical
    int soma = 0;
#ifdef _OPENMP
#pragma omp parallel for
#endif
    for (int k = 0; k < 1000000; k++)
    {
        int a = 2;
#pragma omp critical
        soma += a;
    }

    std::cout << "Soma: " << soma << std::endl;

// Com reduction   
   soma = 0;
#ifdef _OPENMP
#pragma omp parallel for reduction(+:soma)
#endif
    for (int k = 0; k < 1000000; k++)
    {
        int a = 2;
        soma += a;
    }

    std::cout << "Soma: " << soma << std::endl;

// Com target no GPU
#ifdef _OPENMP
    int num_devices = omp_get_num_devices();
    std::cout << "Número de devices (GPUs): " << num_devices << std::endl;

    soma = 0;
    const int DEVICE_0 = 0;
#pragma target device(DEVICE_0) num_teams(4000) distrbute map(tofrom:a)
for (int k = 0; k < 1000000; k++)
    {
        int a = 2;
        soma += a;
    }
#endif
    std::cout << "Soma: " << soma << std::endl;

    return 0;
}