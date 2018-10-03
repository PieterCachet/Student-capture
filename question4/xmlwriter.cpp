#include "xmlwriter.h"

XMLWriter::XMLWriter(){
    rootElement = doc.createElement("StudentList");
    doc.appendChild(rootElement);
}

void XMLWriter::addStudent(Student* m){
    QDomElement student = doc.createElement("student");

    QDomElement studentNumber = doc.createElement("number");
    QString nameStr = m->getNumber();
    QDomText studentDom = doc.createTextNode(nameStr);
    studentNumber.appendChild(studentDom);

    QDomElement modules = doc.createElement("modules");
    QMapIterator<QString, int> i( m->getModules());
    while (i.hasNext()) {
      QDomElement module = doc.createElement("module");
      i.next();
      QDomElement code = doc.createElement("code");
      QString codeStr = i.key();
      QDomText codeDom = doc.createTextNode(codeStr);
      code.appendChild(codeDom);

      QDomElement mark = doc.createElement("mark");
      QString markStr = QString::number(i.value());
      QDomText markDom = doc.createTextNode(markStr);
      mark.appendChild(markDom);

      module.appendChild(code);
      module.appendChild(mark);
      modules.appendChild(module);
     }
    student.appendChild(studentNumber);
    student.appendChild(modules);
    rootElement.appendChild(student);
}

QDomDocument XMLWriter::getDoc() const{
    return doc;
}

