#include <omp.h>
#include <stdio.h>

#define DIMENSIONS 200000
#define NUM_THREADS 8
int main(){
    float a[DIMENSIONS], b[DIMENSIONS], c[DIMENSIONS];
    // fill the vectors
    printf("Filling vectors\n");
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for
    for (int i=0; i<DIMENSIONS; i++){
        a[i] = 0.0;
        b[i] = 1.0;
        c[i] = 2.0;
     }

     double start = omp_get_wtime();
     #pragma omp parallel for
     for (int i=0; i<DIMENSIONS; i++){
         a[i] = b[i] + c[i];
     }
     double end = omp_get_wtime();
     printf("compute time:%f\n ", end-start);
     for (int i=0; i<DIMENSIONS; i++){
         if(a[i]!=3){
             printf("BUZZ\n");
         }
     }


    return 0;
}
