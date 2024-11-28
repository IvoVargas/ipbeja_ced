// Ivo Vargas
// 2024 - Beja - IPBEJA
// heat diffusion simulation
// To compile with cmake:
// cmake --build . --config Release
// To run: ./farao

#include <iostream>
#include <fstream>
#include "farao.h"

int main (int argc, char *argv[]) {
    std::cout << "Eu sou o Ivo" << std::endl;

    const int M = 1000; // em mm
    const int N = 100;

    // reserva de memória
    double** A = new double*[ M ];
    double** B = new double*[ M ];

    for(int k = 0; k < M; k++) {
        A[ k ] = new double[ N ];
        B[ k ] = new double[ N ];
    }

    heat_diffusion_2d(A, B, M, N);

    std::ofstream out_file;
    out_file.open("simul30seg.txt");

    for(int m = 0; m < M; m++) {
        for(int n = 0; n < N; n++) {
            out_file << m << ' ' << n << ' ' << A[ m ][ n ] << std::endl;
        }
        out_file << std::endl;
    }
    out_file.close();

    for(int k = 0; k < M; k++) {
        delete [] A[ k ];
        delete [] B[ k ];
    }

    delete [] A;
    delete [] B;

    return 0;
}