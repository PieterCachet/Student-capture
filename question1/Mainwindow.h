#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

#include <QString>
#include <QGridLayout>
#include <QRegExp>


class Mainwindow:public QWidget{
    Q_OBJECT
public:
    Mainwindow();

public slots:
    void display();
private:
   static QRegExp regexStudentNum;
   static QRegExp regexModuleNum;

   QLineEdit* studentNum;
   QLineEdit* moduleNum;
   QSpinBox* mark;

   QPushButton* btnAdd;
   QGridLayout* layout;

};

#endif // MAINWINDOW_H
