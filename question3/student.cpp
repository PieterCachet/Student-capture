#include "Student.h"

Student::Student(){}

//Check the average of the student.
double Student::average() const{
    int sum = 0, count = 0;
    QMapIterator<QString, int> i(studentModules);
    while (i.hasNext()) {
        i.next();
        sum += i.value();
        count++;
    }
    return (double)sum/count;
}

//Check if the student can/has graduated.
bool Student::graduate() const{
    int year1 = 0, year3 = 0, count = 0;
    QMapIterator<QString, int> i(studentModules);
    while (i.hasNext()) {
        i.next();
        //50 is pass rate.
       if(i.value() >= 50){
          count++;
            QString code = i.key();
            code.replace(QRegularExpression("([^0-9])"), "");//replace any non-numeric chars.
            if(code.at(0) == '1'){
                year1 ++;
            }
            if(code.at(0) == '3'){
                year3 ++;
            }

       }
    }
    /*If the student has passed
     *5 modules, of which at most 2 are
     *1st year modules and at least
     *1 is a 3rd year module.*/
   return ( count >= 5 && year1 <= 2 && year3 >= 1) ;

}

//Return student number
QString Student::getNumber() const{
    return studentNumber;
}

//Return the student modules
QMap<QString, int> Student::getModules() const{
    return studentModules;
}

//Insert Module and Mark to Student
void Student::addModule(QString module, int mark){
    studentModules.insert(module, mark);
}

//Set student number.
void Student::setNumber(QString num){
    studentNumber = num;
}
