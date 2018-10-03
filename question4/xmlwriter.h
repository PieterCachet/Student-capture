#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QDomDocument>
#include "student.h"

class XMLWriter
{
public:
    XMLWriter();
    void addStudent(Student * m);
    QDomDocument getDoc() const;

private:
    QDomDocument doc;
    QDomElement rootElement;
};

#endif // XMLWRITER_H
