#include <omp.h>
#include <stdio.h>

int main(){
    int size = 10;
    int A[size], B[size];
    int cum;
    #pragma omp parallel for
    for (int i=0; i < size; i++){
        A[i] = 1;
    }
    B[0] = A[0];
    #pragma omp parallel for ordered
    for (int i=1; i<size; i++){
        #pragma omp ordered
        {
            B[i] = B[i-1] + A[i];
        }
    }
    for(int i=0; i < size; i++){
        printf("%d=>%d\n", A[i], B[i]);
    }

}
