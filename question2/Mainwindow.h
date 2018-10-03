#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QProcess>

class Mainwindow:public QWidget{
    Q_OBJECT
public:
     Mainwindow();

public slots:
    void addModule();
    void readyReadStandardOutput();

private:
     QPushButton * btnAdd;
     QTextEdit * txtListEdt;
     QProcess * proccess;
     void setUpGui();
};


#endif // MAINWINDOW_H
