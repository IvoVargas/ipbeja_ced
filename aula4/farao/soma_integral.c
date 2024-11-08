# include <stdio.h>
# include <math.h>
# include <omp.h>

double somaintegral(){
   double soma = 0.0;
   double dx = (b-a)/N; 

#pragma omp parallel for
    for(size_t k = 1; k <= N; k++) {
        int tid = omp_get_thread_num();
        if (_OPENMP) {
            printf("Thread id = %d\n", tid);
        }
        soma += f( a + k*dx )* dx;
    }
}