#include "Mainwindow.h"
#include <QRegExpValidator>
#include <QTextStream>

QRegExp Mainwindow::regexStudentNum ( "\\d{4}");
QRegExp Mainwindow::regexModuleNum("([A-Z]{1,3})([1-3]{1,1})(\\d{2})(\\d|[A-Z]{1,1})");

Mainwindow::Mainwindow(){

    setWindowTitle("GetStudent");

    QLabel *lblStudent  = new QLabel("Student Number ");
    QLabel *lblModuleAdd = new QLabel("Add Module: ");
    QLabel *lblModule= new QLabel("Module code ");
    QLabel *lblMark  = new QLabel("Mark");

    btnAdd  = new QPushButton("Add");
    layout = new QGridLayout(this);
    studentNum = new QLineEdit();
    moduleNum = new QLineEdit();
    mark = new QSpinBox();
    mark->setRange(0,100);

    layout->addWidget(lblStudent,0,0);
    layout->addWidget(lblModuleAdd,1,0);
    layout->addWidget(lblModule,2,0);
    layout->addWidget(lblMark,3,0);

    layout->addWidget(studentNum,0,1);
    layout->addWidget(moduleNum,2,1);
    layout->addWidget(mark,3,1);
    layout->addWidget(btnAdd,4,1);
    this-> setLayout(layout);

    QRegExpValidator* validStudentNum(new QRegExpValidator(regexStudentNum,this));
    QRegExpValidator* validModule(new QRegExpValidator(regexModuleNum,this));

    studentNum->setValidator(validStudentNum);
    moduleNum->setValidator(validModule);

    connect(btnAdd,SIGNAL(clicked()),this, SLOT(display()));

}

void Mainwindow::display(){
    QTextStream out(stdout);
    QString stdNum = studentNum->text();
    QString mdlNum = moduleNum->text();
    int mrk = mark ->value();

     out << "Number: "<< stdNum << "\n"
             << "Module: "<< mdlNum << "\n"
             << "Mark: "  << mrk << "\n";

}
