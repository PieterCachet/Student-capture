#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QProcess>
#include <QLineEdit>
#include <QLabel>
#include <QRegExp>
#include <QRegExpValidator>
#include <QMessageBox>
#include "student.h"
#include "studentlist.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void addModule();
    void readyReadStandardOutput();
    void avarage();
    void display();
    void graduate();

private:
     Student * student;
     StudentList * studentList;
     QLineEdit * studentNum;
     QPushButton * btnAdd;
     QPushButton * btnDisplay;
     QPushButton * btnAvg;
     QPushButton * btnGrad;
     QTextEdit * txtListEdt;
     QProcess * proccess;
     void setUpGui();
     Student *getStudent(int index);
     int studentIndex();
     static QRegExp regexStudentNum;
};

#endif // MAINWINDOW_H
