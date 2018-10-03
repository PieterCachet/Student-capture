#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <QList>
#include "student.h"

class StudentList
{
public:
    StudentList();
    ~StudentList();

    StudentList *getInstance();
    void addStudent(Student * student);
    QList<Student *> returnList() const;
    int exists(QString student) const;
    Student *getStudent(int i) const;
    int size();

private:
    StudentList * onlyInstance;
    QList<Student*> studentList;
};

#endif // STUDENTLIST_H
