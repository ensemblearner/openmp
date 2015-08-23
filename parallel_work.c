#include <omp.h>
#include <stdio.h>
#include <math.h>

#define SIZE 2000000
#define NUM_THREADS 6

float fancy_comp(int num){
    int square = num*num;
    return sqrt(square+1);
}
int main(){

    int id;
    float output[SIZE];
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    #pragma omp parallel for
    //{
        //id = omp_get_thread_num();

        for (int i=0; i<SIZE;i++){
            id = omp_get_thread_num();
            //printf("current thread :%d of %d threads\n", id, omp_get_num_threads());
            output[i] = fancy_comp(i);
        }
    //}
    double end = omp_get_wtime();

    printf("time elapsed: %f for %d threads\n", end-start, NUM_THREADS);
}
