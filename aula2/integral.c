// compilar:
// nvcc integral.c -o integral.o

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return 1.0;
}

double soma_integral(double a, double b, int N,
                     double (*f)(double))
{
    double s = 0.0;
    double dx = (b - a) / N;

    for (int k = 0; k < N; k++)
    {
        s += f(a + k * dx) * dx;
    }
    return s;
}

// Calculate Integral of constant function
int main(void)
{
    double a = 0.0;
    double b = 1.0;

    int N = 8;

    double s = soma_integral(a, b, N, f);

    printf("area = %g\n", s);

    return 0;
}