#include "course.h"
#include "studentDir.h"
#include <iostream>
#include <cstring>
#include <sstream>

Course::Course(){
	name = new char[5];
	strncpy(code, "null", 5);
        strncpy(location, "null", 5);
        roster = new int[2];
        maxLen = 2;
		rosterLen = 0;
}

Course::Course(char* nam, char* cod, char* locatio){
    	name = strcpy(new char[strlen(nam) + 1], nam);
	strncpy(code, cod, 6);
        strncpy(location, locatio, 9);
        roster = new int[2];
        maxLen = 2;
        rosterLen = 0;
}

Course::~Course(){
    //cout << "destroyed course: " << *this << endl;
    // if I uncomment these, run fails
    //delete[] name;
    //delete[] roster;
}

char* Course::Getname(){
    return name;
}
char* Course::Getcode(){
    return code;
}
char* Course::Getlocation(){
    return location;
}
int* Course::Getroster(){
    return roster;
}

void Course::Load(){
    char sname[128];
    char scode[7];
    char slocation[10];
    cout << "Enter course name: ";
    //cin >> sname;
    //cin.ignore(128, '\n');
    cin.getline(sname, sizeof(sname));
    cout << "Enter course code: ";
    cin >> scode;
    cin.ignore(128, '\n');
    cout << "Enter course location: ";
    cin >> slocation;
    cin.ignore(128, '\n');
    delete[] name;
    name = new char[strlen(sname) + 1];
    strcpy(name, sname);
    strncpy(code, scode, sizeof(code)-1);
    strncpy(location, slocation, sizeof(slocation)-1);    
}

void Course::Enroll(Student& student){
    roster[rosterLen++] = student.Getstudentid();
    if(rosterLen==maxLen){
		maxLen = rosterLen + 10;
		int* newRoster = new int[rosterLen];
		for(int i=0; i<rosterLen; i++){
			newRoster[i] = roster[i];
		}
		
		delete[] roster;
		roster = newRoster;
	}
}

void Course::RemoveStudent(int sid){
    bool found = false;
    for(int i=0; i<rosterLen; i++){
        if(roster[i] == sid){
            found = true;
        }
        if(found && i<rosterLen - 1){
            roster[i] = roster[i + 1];
        }
    }
    if(found){
        roster[rosterLen - 1] = 0;
        rosterLen--;
        cout << "Student removed from roster" << endl;
    }
}

void Course::Show(StudentDir& studentDi){
    studentDir = &studentDi;
    cout << *this << endl;;
}

ostream& operator<<(ostream& output, const Course& c) {
    output <<  "course name: "  <<  c.name;
    output << ", code: " << c.code;
    output << ", location: " << c.location;
    output << ", roster ids: ";
    for(int i=0; i<c.rosterLen; i++){
        if(i == 0){
            output << endl;
        }
        int sIdx = c.studentDir->FindStudentid(c.roster[i]);
        output << "\t" << c.studentDir->Getstudent(sIdx);
        if(i < c.rosterLen - 1){
            output << "," << endl;
        }
    }
    return output;
}
