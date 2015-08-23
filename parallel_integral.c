//
// Created by Mohit Singh on 8/20/15.
//

#include <stdio.h>
#include <omp.h>
static long num_steps = 100000;

#define NUM_THREADS 2
int main(){
    double step;
    int  i, nthreads;
    double pi, sum[NUM_THREADS];
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    #pragma omp parallel

    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id==0) nthreads=nthrds;
        for (i = id, sum[id]=0.0; i < num_steps; i=i+nthrds) {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }
    double end = omp_get_wtime();
    for(i=0; i<nthreads; i++) {
        pi+=(float)sum[i]*step;;
    }
    printf("pi is %f\n", pi);
    printf("time elapsed: %f\n", end-start);
    return 0;
};