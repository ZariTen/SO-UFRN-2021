#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define PI 3.1416

int n,t; // a-b: inicio e fim da função | n: numero trapezios | t: numero threads
double a,b;
double memoria[50];

//Limites a=0.0 b=10.0
double f1(double x){
    return 5.0;
}

//Limites a=0.0 b=2.0*PI
double f2(double x){
    return sin(2.0 * x) + cos(5.0 * x);    
}

void* trap_area(void *idThread){
    double local_a,local_b;
    double local_n = n/t;

    local_a = a/t * (int)(size_t)idThread + b/t *(int)(size_t) idThread;

    local_b = local_a + b/t;

    printf("Thread %d: a=%f | b=%f | n=%f \n",(int)(size_t)idThread,local_a,local_b,local_n);


    double h = (local_b-local_a)/local_n;
    double area_total = (f1(local_a)+f1(local_b))/2;
    for(int i = 1; i < local_n; i++){
        double x_i = local_a + i*h;
        area_total += f1(x_i);
    }
    area_total = h*area_total;
    memoria[(int)(size_t)idThread] = area_total;

    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    // Argumento 1: N de threads ; Argumento 2: N de trapezios
    if (argc < 2){
        return 1;
    }
    t =  atoi(argv[1]);
    n = atoi(argv[2]);
    pthread_t threads[t];
    int i;
    void *thread_return;

    //Função 1
    a = 0.0;
    b = 10.0;
    for (i = 0; i < t; i++){
        int pcreate = pthread_create(&threads[i],NULL,trap_area,(void*)(size_t)i);

        if(pcreate != 0){
            return 1;
        }
    }

    for(i = 0; i <t; i++){
        pthread_join(threads[i],&thread_return);
    }

    double resultado = 0;
    for(int i = 0; i < t; i++){
        resultado += memoria[i];
    }
    printf("Soma total: %f \n",resultado);

}
