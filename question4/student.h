#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QMap>
#include <QObject>
#include <QRegularExpression>

class Student : public QObject{

protected:
    QString studentNumber;
    QMap<QString, int> studentModules;


public:
    Student();
    double average() const;
    bool graduate() const;
    QString getNumber() const;
    QMap<QString, int> getModules() const;

    void addModule(QString module, int mark);
    void setNumber(QString num);
};

#endif // STUDENT_H
