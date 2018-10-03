#include "mainwindow.h"

//Student Edit Field regex.
QRegExp MainWindow::regexStudentNum ( "\\d{4}");

MainWindow::MainWindow(){
     setUpGui();
}

//Setup my GUI
void MainWindow::setUpGui(){

    //Student Edit validation regex.
    QRegExpValidator* validStudentNum(new QRegExpValidator(regexStudentNum,this));

    studentList = new StudentList();
    this->setWindowTitle("Process Student");
    btnAdd = new QPushButton("Add Module");
    btnAvg = new QPushButton("Average");
    btnDisplay = new QPushButton("Display");
    btnGrad = new QPushButton("Graduate?");
    QLabel *lblStudent  = new QLabel("Student number: ");

    studentNum = new QLineEdit();
    txtListEdt = new QTextEdit();
    QGridLayout * layout = new QGridLayout();
    txtListEdt->setReadOnly(true);
    layout->addWidget(lblStudent,0,0);
    layout->addWidget(studentNum,0,1);
    layout->addWidget(btnDisplay,1,0);
    layout->addWidget(btnAvg,1,1);
    layout->addWidget(btnGrad,1,2);
    layout->addWidget(btnAdd,1,3);
    layout->addWidget(txtListEdt,2,0);
    this->setLayout(layout);

    //Force the Student Edit Field to this regex.
    studentNum->setValidator(validStudentNum);


    //Button Setup
    connect(btnAdd,SIGNAL(clicked()),this,SLOT(addModule()));
    connect(btnAvg,SIGNAL(clicked()),this,SLOT(avarage()));
    connect(btnDisplay,SIGNAL(clicked()),this,SLOT(display()));
    connect(btnGrad,SIGNAL(clicked()),this,SLOT(graduate()));

}

//Get Student Object based on index;
Student *MainWindow::getStudent(int idx){
    return studentList->getStudent(idx);
}

//Check if Student exists, or we have data.
int MainWindow::studentIndex(){
    int idx = studentList->exists(studentNum->text());
    if(idx < 0){
        QMessageBox::warning(this, "No Data Found", "Please Check Student Number and try again.");
    }
   return idx;
}

//Call Question One in Proccess.
void MainWindow::addModule(){
    proccess = new QProcess();
    connect(proccess, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    proccess->start("question1");

}

//Capture the Process incoming Stream data.
void MainWindow::readyReadStandardOutput(){
    QByteArray bytes = proccess->readAllStandardOutput();
    txtListEdt->append(QString(bytes));
    QString data = QString(bytes).replace("\r\n", "");
    QRegExp separator("(Number: |Module: |Mark: )");
    QStringList list = data.split(separator);

    //Check to see if a Student object exists, if so append else create new.
    int exists = studentList->exists(list.at(1));
    if( exists == -1){
        Student * s = new Student();
        s->setNumber(list.at(1));
        s->addModule(list.at(2),list.at(3).toInt());

        studentList->addStudent(s);
    }else {
        Student * s = studentList->getStudent(exists);
        s->addModule(list.at(2),list.at(3).toInt());
    }
}

//Display The avarage of specific student.
void MainWindow::avarage(){
    int studentIdx = studentIndex();
    if(studentIdx >= 0){
         Student * s = getStudent(studentIdx);
         double avg = s->average();
         txtListEdt->clear();
         txtListEdt->append(QString("Student: %1 \nAvarage : %2%").arg(s->getNumber()).arg(avg));
         return;
     }
}

//Dispaly all modules and marks achieved for a student.
void MainWindow::display(){
    int studentIdx = studentIndex();
    if(studentIdx >= 0){
         Student * s = getStudent(studentIdx);
         txtListEdt->clear();
         txtListEdt->append(QString("Student: %1").arg(s->getNumber()));
         QMapIterator<QString, int> i(s->getModules());
         while (i.hasNext()) {
             i.next();
             txtListEdt->append(QString("Module: %1, Mark: %2%").arg(i.key()).arg(i.value()));
         }
         return;
     }
}

//Check if a student can/has graduated?
void MainWindow::graduate(){
    int studentIdx = studentIndex();
    if(studentIdx >= 0){
         Student * s = getStudent(studentIdx);
         txtListEdt->clear();
         txtListEdt->append(QString("Graduate: %1").arg(s->graduate()? "YES" : "NO"));
         return;
     }
}
