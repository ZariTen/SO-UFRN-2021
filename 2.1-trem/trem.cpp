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
    t1t4.unlock();
    t2t3.unlock();
    t2t4.unlock();
    t2t5.unlock();
    t3t5.unlock();
    t4t5.unlock();
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x <330){
                if(x==310){t1t2.lock();}
                if(x==320){t1t4.lock();}
                x+=10;
            }
            else if (x==330 && y < 150){
                //Zona crítica (T2)
                y+=10;
            }
            else if (x > 160 && y == 150){
                //Zona critica (T4)
                x-=10;
                if (x == 320) {t1t2.unlock();}
                if (x == 180) {t1t4.unlock();}
            }
            else if (x > 60 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x <600){
                if(x==360){t1t2.unlock();}
                if(x==590){t2t3.lock();}
                x+=10;
            }
            else if (x == 600 && y < 150){
                //Zona critica (T3)
                y+=10;
            }
            else if (x > 330 && y == 150){
                if(x==580){t2t3.unlock();}
                if(x==350){t1t2.lock();}
                if(x==480){t2t4.lock();}
                x-=10;
            }
            else{
                //Zona critica (T1)
                if(y==120){t2t4.unlock();}
                y-=10;
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
            else if (x > 600 && y == 150){
                if(x==620){t2t3.lock();}
                x-=10;
            }
            else{
                //Zona critica (T2)
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 150 && x < 460){
                if(x==350){t1t4.unlock();}
                if(x==440){t4t5.lock();}
                x+=10;
            }
            else if (x == 460 && y < 270){
                if(y==170){t2t4.unlock();}
                y+=10;
            }
            else if (x > 190 && y == 270){
                if(x==440){t4t5.unlock();}
                x-=10;
            }
            else{
                y-=10;
                if (y==160){t1t4.lock();}
                if (y==160){t2t4.lock();}
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 150 && x < 730){
                //if(x==580){t3t5.lock();}
                if(x==480){t4t5.unlock();}
                x+=10;
            }
            else if (x == 730 && y < 270)
                y+=10;
            else if (x > 460 && y == 270){
                if(x==480){t4t5.lock();}
                x-=10;
            }
            else{
                //if(y==170){t2t5.lock();}
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}




