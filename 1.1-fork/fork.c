#include <stdio.h>
#include <unistd.h>
#include <time.h>

int anoPassados(const time_t start){
    time_t clock = time(NULL);

    return clock - start;
}

int main(){
    time_t start,stop;
    start = time(NULL);
    int year = 0;


    sleep(14);
    printf("Nascimento do Filho1. Ano: %ld \n", anoPassados(start));
    int p = fork();
    if (p > 0){ //Pai
        int pp = fork(); //Criar Filho2

        if(pp == 0){ //Filho2
            int pf2 = fork(); //Criar Neto2

            if (pf2 == 0){ //Neto2

            }
        }

    }
    
    if (p == 0){ //Filho
        int pf = fork();

        if (pf == 0){ //Neto1

        }

    }
    return 0;
}