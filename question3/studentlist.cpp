#include "studentlist.h"

StudentList::StudentList(){
}

StudentList::~StudentList(){
    delete(&studentList);
}

//Dont think Ill need this but just incase.
StudentList *StudentList::getInstance(){
    if(onlyInstance == 0){
        onlyInstance = new StudentList();
    }
    return onlyInstance;
}

//Append a Student Object.
void StudentList::addStudent(Student *s){
    studentList.append(s);
}

//Return the List Of Student Objects
QList<Student *> StudentList::returnList() const{
    return studentList;
}

//Check if student exists,
/* PLEASE NOTE : I will return negative one(-1) if a student doenst exist.*/
int StudentList::exists(QString stdntNum) const{
      int count = 0, idx = 0;
      bool exists = false;
      foreach(Student * student , studentList){
        if(student->getNumber() == stdntNum){
            exists = true;
            idx = count;
        }
         count ++;
      }

      if(exists){
          return idx;//return index at which student was found.
      }
      return -1;//doesnt exist
}

//Return Student Object at index point.
Student *StudentList::getStudent(int i) const{
    return studentList.at(i);
}

//The Size of the Student List Object, have no reason atm to use this but good to have.
int StudentList::size(){
    return studentList.count();
}
