#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int anoPassados(const time_t start){
    time_t clock = time(NULL);

    return clock - start;
}

int main(){
    //Para horario de nascimento
    time_t hora = time(0);
    struct tm tm = *localtime(&hora); //Para nascimentos
    struct tm dm = *localtime(&hora); //Para mortes
    //"Nascimento" do pai, time_t xIdade são usados para saber quando x nasceu
    printf("Nascimento do Pai. PID: %ld Hora: %ld:%ld:%ld \n", getpid(), tm.tm_hour,tm.tm_min,tm.tm_sec);
    time_t paiIdade = time(0);

    sleep(14);
    hora = time(0);
    tm = *localtime(&hora);
    time_t filho1Idade = time(0);
    int p = fork();
    
    if (p > 0){ //Pai
        sleep(2);
        hora = time(0);
        tm = *localtime(&hora);
        int pp = fork(); //Criar Filho2
        time_t filho2Idade = time(0);

        if(pp == 0){ //Filho2
            printf("Nascimento do Filho2. PID: %ld Hora: %ld:%ld:%ld\n", getpid(),tm.tm_hour,tm.tm_min,tm.tm_sec);
            sleep(14);
            hora = time(0);
            tm = *localtime(&hora);
            int pf2 = fork(); //Criar Neto2
            time_t neto2Idade = time(0);

            if (pf2 == 0){ //Neto2
                printf("Nascimento do Neto2. PID: %ld Hora: %ld:%ld:%ld\n", getpid(),tm.tm_hour,tm.tm_min,tm.tm_sec);
                sleep(18);
                hora = time(0);
                tm = *localtime(&neto2Idade);
                dm = *localtime(&hora);
                printf("Morte Neto2. Anos vividos: %ld , Nascimento: %ld:%ld:%ld,Morte: %ld:%ld:%ld \n",anoPassados(neto2Idade),tm.tm_hour,tm.tm_min,tm.tm_sec, dm.tm_hour,dm.tm_min,dm.tm_sec);
                exit(0);

            }
            sleep(16);
            hora = time(0);
            tm = *localtime(&filho2Idade);
            dm = *localtime(&hora);
            printf("Morte Filho2. Anos vividos: %ld , Nascimento: %ld:%ld:%ld,Morte: %ld:%ld:%ld \n",anoPassados(filho2Idade),tm.tm_hour,tm.tm_min,tm.tm_sec, dm.tm_hour,dm.tm_min,dm.tm_sec);
            exit(0);
        }
        sleep(44);
        hora = time(0);
        tm = *localtime(&paiIdade);
        dm = *localtime(&hora);
        printf("Morte do Pai. Anos vividos: %ld , Nascimento: %ld:%ld:%ld,Morte: %ld:%ld:%ld \n",anoPassados(paiIdade),tm.tm_hour,tm.tm_min,tm.tm_sec, dm.tm_hour,dm.tm_min,dm.tm_sec);
        exit(0);
    }
    
    if (p == 0){ //Filho
        printf("Nascimento do Filho1. PID: %ld Hora: %ld:%ld:%ld \n",getpid(), tm.tm_hour,tm.tm_min,tm.tm_sec);
        sleep(12);
        hora = time(0);
        tm = *localtime(&hora);
        int pf = fork();
        time_t neto1Idade = time(0);

        if (pf == 0){ //Neto1
            printf("Nascimento do Neto1. PID: %ld Hora: %ld:%ld:%ld\n", getpid(),tm.tm_hour,tm.tm_min,tm.tm_sec);
            sleep(12);
            hora = time(0);
            tm = *localtime(&neto1Idade);
            dm = *localtime(&hora);
            printf("Morte Neto1. Anos vividos: %ld, Nascimento: %ld:%ld:%ld, Morte: %ld:%ld:%ld\n",anoPassados(neto1Idade),tm.tm_hour,tm.tm_min,tm.tm_sec, dm.tm_hour,dm.tm_min,dm.tm_sec);
            exit(0);
        }
        sleep(18);
        hora = time(0);
        tm = *localtime(&filho1Idade);
        dm = *localtime(&hora);
        printf("Morte Filho1. Anos vividos: %ld, Nascimento: %ld:%ld:%ld, Morte: %ld:%ld:%ld \n",anoPassados(filho1Idade),tm.tm_hour,tm.tm_min,tm.tm_sec, dm.tm_hour,dm.tm_min,dm.tm_sec);
        exit(0);

    }
    return 0;
}