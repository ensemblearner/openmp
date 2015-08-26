//
// Created by Mohit Singh on 8/20/15.
//

#include <stdio.h>
#include <omp.h>
static long num_steps = 10000000;

#define NUM_THREADS 8
int main(){
    double step;
    double pi, sum, x;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    #pragma omp parallel for private(x) reduction(+:sum)
        for (int i = 0; i < num_steps; i++) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }


    double end = omp_get_wtime();
    pi = step * sum;
    printf("pi is %f\n", pi);
    printf("time elapsed: %f for threads: %d\n", end-start, NUM_THREADS);
    return 0;
};
