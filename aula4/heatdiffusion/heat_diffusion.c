// Heat diffusion
// Ivo Vargas
// 2024-11-08

#include <stdio.h>
#include <math.h>
#include <omp.h>

void heat_diffusion()
{
    const int N = 1000; // mm, mil milímetros
    double T_n [N];
    double T_n1 [N];
    double alpha_gold = 1.27; // mm2/s, coeficiente de diffusão termica
    double t_f = 1000.0; // final time in seconds
    double t = 0.0; // time in seconds

    // time representation of each iteration in time
    double dt = 1; // seconds

    // initial temperatures
    for( int k = 0; k < N; k++ ) {
        T_n[ k ] = 25.0;
    }

    while (t < t_f)
    {
        T_n[0] = 100.0; // one edge
        T_n[N-1] = 100.0; // the other edge of the stick

        // Heat Diffusion equation
        for( int k = 1; k < N - 2; k++ )
        {
            T_n1[ k ] = T_n[ k ] + (T_n[k+1] - 2.0 * T_n[k] + T_n[k-1]) * dt / alpha_gold;
        }
        t += dt;

        for( int k = 0; k < N; k++ )
        {
            T_n[ k ] = T_n1[ k ];
        }
        printf("t = %f, T_middle = %f, T_left = %f, T_right = %f\n", t, T_n[N/2], T_n[1], T_n[N-2]);
    }
}

int main()
{
    heat_diffusion();
    return 0;
}