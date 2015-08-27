//
// Created by Mohit Singh on 8/18/15.
//

#include <omp.h>
#include <stdio.h>

int foo(int i){
    return i*i;
}
int main() {
   #pragma omp parallel for
        for(int i=0; i<5;i++){
            int ID = omp_get_thread_num();
            printf("Hello(%d) => %d\n", ID,i);
        }

    return 0;
}
