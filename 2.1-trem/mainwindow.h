#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_t1Speed_sliderMoved(int position);

    void on_t2Speed_sliderMoved(int position);

    void on_t3Speed_sliderMoved(int position);

    void on_t4Speed_sliderMoved(int position);

    void on_t5Speed_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif // MAINWINDOW_H
