// Ivo Vargas
// 2024 - Beja - IPBEJA
// heat diffusion simulation
// To compile with cmake:
// cmake --build . --config Release
// To run: ./farao
// If "cache error"
// do: cmake .

#include <iostream>
#include <omp.h>
#include <cmath>

int main (int argc, char *argv[]) {

    // Primeiro exemplo
    #ifdef _OPENMP
    #pragma omp parallel num_threads(8)
    #endif
    {
        int tld = 0;
        #ifdef _OPENMP
        tld = omp_get_thread_num();
        #endif
        //std::cout << "Aqui estou eu " << tld << std::endl;
    }
    
    // Segundo exemplo
    double* A = new double[8];

    #ifdef _OPENMP
    #pragma omp parallel num_threads(8)
    #endif
    {
        int tld = 0;
        #ifdef _OPENMP
        tld = omp_get_thread_num();
        #endif
        A [ tld ] = tld;
    }
        
    /*for (size_t i = 0; i < 8; i++)
    {
        std::cout << A[i] << std::endl;
    }*/

    delete [] A;

    // Terceiro exemplo
    A = new double[8];
    double* B = new double[8];
    double* C = new double[8];

    #ifdef _OPENMP
    #pragma omp parallel num_threads(8)
    #endif
    //for (int i = 0; i < 8; i++)
    {
        #ifdef _OPENMP
        int i = omp_get_thread_num();
        #endif

        A[i] = i;
        B[i] = 2 * i;
    }

    for (int k = 0; k < 8; k++)
    {
        C[k] = A[k] + B[k];
    }

    /*for (int i = 0; i < 8; i++)
    {
        std::cout << C[i] << std::endl;
    }*/

    delete [] A;
    delete [] B;
    delete [] C;

    // Quarto exemplo
    int NN = 21477;

    A = new double[NN];
    B = new double[NN];
    C = new double[NN];

    #ifdef _OPENMP
    #pragma omp parallel for num_threads(8)
    #endif
    for (int i = 0; i < NN; i++)
    {
        A[i] = i;
        B[i] = 2 * i;
    }

    for (int k = 0; k < NN; k++)
    {
        C[k] = A[k] + B[k];
    }

    for (int i = 0; i < NN; i++)
    {
        std::cout << C[i] << std::endl;
    }

    delete [] A;
    delete [] B;
    delete [] C;

    // Quinto exemplo "reducao"
    NN = 21477;

    A = new double[NN];
    B = new double[NN];
    int s = 0;

    for (int i = 0; i < NN; i++)
    {
        A[i] = i;
        B[i] = 2 * i;
    }

    #ifdef _OPENMP
    #pragma omp parallel for num_threads(112) reduction(+:s)
    #endif
    for (int k = 0; k < NN; k++)
    {
        s += A[k] + B[k];
    }

    std::cout << s << std::endl;
    
    delete [] A;
    delete [] B;

    // Sexto exemplo. reduction to prevent memory collisions, and collapse to divide second for processing
    // private to allow external variables
    NN = 1000;

    A = new double[NN];
    B = new double[NN];
    s = 0;

    for (int i = 0; i < NN; i++)
    {
        A[i] = i;
        B[i] = 2 * i;
    }

    int k, j;
    #ifdef _OPENMP
    #pragma omp parallel for num_threads(112) reduction(+:s) collapse(2) private(k, j)
    #endif
    for (k = 0; k < NN; k++)
    {
        for (j = 0; j < NN; j++)    
        {
            s += A[k] + B[k];
        }
    }

    std::cout << s << std::endl;
    
    delete [] A;
    delete [] B;

    return 0;
}