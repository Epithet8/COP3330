#include "student.h"
#include <iostream>
#include <cstring>
#include <sstream>

	
Student::Student(){
	name = new char[5];
        strcpy(name, "null");
	
	classification = '0';
	
	major = new char[5];
        strcpy(major, "null");
	
	studentid = 0;
};

Student::Student(char* nam, char classificatio, char* majo, int studenti){
    	name = strcpy(new char[strlen(nam) + 1], nam);
	
	classification = classificatio;
	
	major = strcpy(new char[strlen(majo) + 1], majo);
	
	studentid = studenti;
}

Student::~Student(){
    //cout << "destroyed student: " << *this << endl;
    // if I uncomment these, run fails
    //delete[] name;
    //delete[] major;
}

char* Student::Getname(){
    return name;
}
char Student::Getclassification(){
    return classification;
}
char* Student::Getmajor(){
    return major;
}
int Student::Getstudentid(){
    return studentid;
}

void Student::Load(){
    char sname[128];
    char smajor[128];
    cout << "Enter student name: ";
    //cin >> sname;
    //cin.ignore(128, '\n');
    cin.getline(sname, sizeof(sname));
    cout << "Enter student classification: ";
    cin >> classification;
    cin.ignore(128, '\n');
    cout << "Enter student major: ";
    //cin >> smajor;
    //cin.ignore(128, '\n');
    cin.getline(smajor, sizeof(smajor));
    cout << "Enter student id: ";
    cin >> studentid;
    cin.ignore(128, '\n');
    delete[] name;
    name = new char[strlen(sname) + 1];
    strcpy(name, sname);
    delete[] major;
    major = new char[strlen(smajor) + 1];
    strcpy(major, smajor);
}

void Student::Show(){
    cout << *this << endl;
}

ostream& operator<<(ostream& output, const Student& s) {
    output  <<  "student name: " << s.name;
    output << ", classification: " << s.classification;
    output << ", major: " << s.major;
    output << ", studentid: " << s.studentid;
    return output;
}