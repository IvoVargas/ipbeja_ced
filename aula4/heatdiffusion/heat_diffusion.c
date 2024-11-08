// Heat diffusion
// Ivo Vargas
// 2024-11-08

#include <stdio.h>
#include <math.h>
#include <omp.h>

void heat_diffusion()
{
    const int N = 1000; // mm, mil milímetros
    double *T_n [N];
    double *T_n1 [N];
    double alpha_gold = 127; // mm2/s, coeficiente de diffusão termica
    double t_f = 10.0; // final time in seconds
    double t = 0.0; // time in seconds

    // time representation of each iteration in time
    double dt = 1; // seconds

    // initial temperatures
    for( int k = 0; k < N-2; k++ ) {
        T_n[ k ] = 25.0;
    }

    T_n[0] = 100.0; // one edge
    T_n[N-1] = 100.0; // the other edge of the stick

    while (t < t_f)
    {   
        // Heat Diffusion equation
        for( int k = 1; k < N - 3; k++ )
        {
            T_n1[ k ] = T_n[ k ] + (T_n[k+2] - 2.0 * T_n[k+1] + T_n[k]) * dt / alpha_gold;
        }

        printf("t = %f T(t) = %f\n", t, T_n[N / 2]);
        t += dt;

        for( int k = 0; k < N; k++ )
        {
            T_n[ k ] = T_n1[ k ];
        }
    }

    //delete *T_n;
    //delete *T_n1;
}

int main()
{
    heat_diffusion();
    return 0;
}