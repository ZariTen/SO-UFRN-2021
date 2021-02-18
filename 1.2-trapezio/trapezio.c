#include <stdio.h>
#include <math.h>
#include <pthread.h>

int a,b,n,t; // a-b: inicio e fim da função | n: numero trapezios | t: numero threads


double f1(double x){
    return 5.0;
}

double f2(double x){
    return sen(2.0 * x) + cos(5.0 * x);    
}

double trap_area(){
    int local_a,local_b,local_n;
    //Solução 2
    double h = (local_b-local_a)/local_n;

}

int main(){
    t = 2;
    double memoria[t];
    pthread_t threads[t];

}
