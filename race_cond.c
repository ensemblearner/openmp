#include <omp.h>
#include <stdio.h>
int main(){
    int size = 10000;
    float a[size];

    #pragma omp parallel for
    for (int i=0; i<size; i++){
        a[i] = 1.0;
    }
    float sum=0.0;
    #pragma omp parallel
    {
        float ps[omp_get_num_threads()]  ;
        #pragma omp parallel for
        for (int i=0; i<size; i++){

            ps[omp_get_thread_num()] = ps[omp_get_thread_num()] +a[i];
        }
        #pragma omp critical
        {
            sum+=ps[omp_get_thread_num()];
        }
    }

    printf("%f\n", sum);
}
