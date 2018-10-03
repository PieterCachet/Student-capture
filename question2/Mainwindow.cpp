#include "Mainwindow.h"
#include<QTextStream>
#include<QDebug>

QTextStream cout(stdout);
Mainwindow::Mainwindow(){
     setUpGui();
}

void Mainwindow::setUpGui(){

    this->setWindowTitle("Process Student");
    btnAdd = new QPushButton("Add Module");
    txtListEdt = new QTextEdit();
    QGridLayout * layout = new QGridLayout();
    txtListEdt->setReadOnly(true);

    layout->addWidget(btnAdd,0,0);
    layout->addWidget(txtListEdt,2,0);
    this->setLayout(layout);

    connect(btnAdd,SIGNAL(clicked()),this,SLOT(addModule()));

}
void Mainwindow::addModule(){

    proccess = new QProcess();
    connect(proccess, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    proccess->start("question1");

}

void Mainwindow::readyReadStandardOutput(){

    QByteArray bytes = proccess->readAllStandardOutput();
    txtListEdt->append(QString(bytes));
}


