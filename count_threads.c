#include <omp.h>
#include <stdio.h>

int main(){
    int nthreads = 10;
    int id;
    omp_set_num_threads(nthreads);
    int sum=0;
    #pragma omp parallel private(id) shared(sum,nthreads)
    {

        id = omp_get_thread_num();
        printf("hello from thread %d of %d threads\n",id, omp_get_num_threads());
        sum++;


    }
    printf("sum is %d\n",sum);
    return 0;
}
