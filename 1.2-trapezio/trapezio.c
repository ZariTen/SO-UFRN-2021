#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int a,b,n,t; // a-b: inicio e fim da função | n: numero trapezios | t: numero threads


double f1(double x){
    return 5.0;
}

double f2(double x){
    return sin(2.0 * x) + cos(5.0 * x);    
}

void* trap_area(void *idThread){
    int local_a,local_b,local_n;
    printf("Thread %d\n",(int)(size_t)idThread);
    //Solução 2
    //double h = (local_b-local_a)/local_n;
    pthread_exit(NULL);

}

int main(int argc, char *argv[]){
    // Argumento 1: N de threads ; Argumento 2: N de trapezios
    if (argc < 2){
        return 1;
    }
    t =  atoi(argv[1]);
    n = atoi(argv[2]);
    double memoria[t];
    pthread_t threads[t];
    int i;
    void *thread_return;

    for (i = 0; i < t; i++){
        int pcreate = pthread_create(&threads[i],NULL,trap_area, (void*)(size_t)i);

        if(pcreate != 0){
            return 1;
        }
    }

    for(i = 0; i <t; i++){
        pthread_join(threads[i],&thread_return);
    }

}
