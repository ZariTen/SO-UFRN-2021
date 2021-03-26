#include "trem.h"
#include <QtCore>

//Mutex das zonas criticas
QMutex t1t2;
QMutex t1t4;

QMutex t2t3;
QMutex t2t4;
QMutex t2t5;

QMutex t3t5;

QMutex t4t5;
//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 50;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    t1t2.unlock();
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x <310)
                x+=10;
            else if ((x == 310 || x==330) && y < 150){
                //Zona crítica (T2)
                t1t2.lock();
                for(; y != 150;){
                    if (x<330){x+=10;}
                    else{y+=10;}
                    emit updateGUI(ID,x,y);
                    msleep(velocidade);
                }
            }
            else if (x > 160 && y == 150){
                //Zona critica (T4)
                x-=10;
                if (x == 320) {t1t2.unlock();}
            }
            else if (x > 60 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x <580){
                if(x==360){t1t2.unlock();}
                x+=10;
            }
            else if (x == 580 && y < 150){
                //Zona critica (T3)
                t2t3.lock();
                for(;y!=150;){
                    if(x<600){x+=10;}
                    else{y+=10;}
                    emit updateGUI(ID,x,y);
                    msleep(velocidade);
                }
            }
            else if (x > 350 && y == 150){
                if(x==580){t2t3.unlock();}
                x-=10;
            }
            else{
                //Zona critica (T1)
                t1t2.lock();
                for (; y != 30;){
                    if (x>330){x-=10;}
                    else{y-=10;}
                    emit updateGUI(ID,x,y);
                    msleep(velocidade);
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 30 && x < 870){
                if(x==620){t2t3.unlock();}
                x+=10;
            }
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 620 && y == 150)
                x-=10;
            else{
                //Zona critica (T2)
                t2t3.lock();
                for(;y!=30;){
                    if(x>600){x-=10;}
                    else{y-=10;}
                    emit updateGUI(ID,x,y);
                    msleep(velocidade);
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 150 && x < 460)
                x+=10;
            else if (x == 460 && y < 270)
                y+=10;
            else if (x > 190 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 150 && x < 730)
                x+=10;
            else if (x == 730 && y < 270)
                y+=10;
            else if (x > 460 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}



