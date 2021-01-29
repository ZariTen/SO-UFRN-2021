#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

int anoPassados(const time_t start){
    time_t clock = time(NULL);

    return clock - start;
}

int main(){
    pid_t wpid;
    time_t start;
    time_t hora = time(0);
    struct tm tm = *localtime(&hora);
    start = time(NULL);
    int year = 0;


    sleep(14);
    hora = time(0);
    tm = *localtime(&hora);
    printf("Nascimento do Filho1. Hora: %ld:%ld:%ld Data: %ld/%ld/%ld\n", tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);

    int p = fork();
    
    if (p > 0){ //Pai
        sleep(2);
        hora = time(0);
        tm = *localtime(&hora);
        printf("Nascimento do Filho2. Hora: %ld:%ld:%ld Data: %ld/%ld/%ld\n", tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
        int pp = fork(); //Criar Filho2

        if(pp == 0){ //Filho2
            sleep(14);
            hora = time(0);
            tm = *localtime(&hora);
            printf("Nascimento do Neto2. Hora: %ld:%ld:%ld Data: %ld/%ld/%ld\n", tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
            int pf2 = fork(); //Criar Neto2

            if (pf2 == 0){ //Neto2
                sleep(18);
                kill(pf2,SIGTERM);

            }
            sleep(16);
            kill(pp,SIGTERM);
        }
        while ((wpid = wait(0))>0); //Esperar até que todos os filhos tenham morrido

    }
    
    if (p == 0){ //Filho
        sleep(12);
        hora = time(0);
        tm = *localtime(&hora);
        printf("Nascimento do Neto1. Hora: %ld:%ld:%ld Data: %ld/%ld/%ld\n", tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
        int pf = fork();

        if (pf == 0){ //Neto1
            sleep(12);
        }
        sleep(18);
        kill(p,SIGTERM);

    }
    return 0;
}