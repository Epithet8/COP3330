#include <cstdlib>
#include <iostream>
#include <cstring>
#include "courseDir.h"
#include "studentDir.h"


using namespace std;

int main(int argc, char** argv) {
   
    CourseDir courses = CourseDir();
    StudentDir students = StudentDir();
    
    // pre-loaded courses to speed up testing
    courses.Insert(Course("calcI", "m123", "unionA"));
    courses.Insert(Course("calcII", "m223", "unionB"));
    courses.Insert(Course("calcIII", "m223", "unionC"));
    // pre-loaded students to speed up testing
    students.Insert(Student("cindy loper", '1', "music", 654321));
    students.Insert(Student("bob saget", '1', "communications", 654322));
    students.Insert(Student("jane goodall", '2', "biology", 654323));
    students.Insert(Student("ralph cramden", '3', "political science", 654324));
    // pre-enroll students in coursed to speed up testing
    courses.Getcourse(0).Enroll(students.Getstudent(0));
    courses.Getcourse(0).Enroll(students.Getstudent(1));
    courses.Getcourse(0).Enroll(students.Getstudent(2));
    courses.Getcourse(1).Enroll(students.Getstudent(3));
    cout << "***Pre-Loaded courses with enrollments" << endl;
    courses.DisplayDirectory(students);
    cout << "***Pre-Loaded students" << endl;
    students.DisplayDirectory();
    cout << "***" << endl;
         
    int choice = -1;
    while(choice != 0){
        cout << "1. Add course" << endl;
        cout << "2. Add student" << endl;
        cout << "3. Add student to course" << endl;
        cout << "4. Update course record" << endl;
	cout << "5. Update student record" << endl;
        cout << "6. Remove student from course" << endl;
        cout << "7. List courses" << endl;
        cout << "8. List students" << endl;
        cout << "9. Find student by name" << endl;
        cout << "10. Find student by student id" << endl;
        cout << "11. Find course by name" << endl;
        cout << "12. Find course by code" << endl;
        cout << "13. Find course by location" << endl;
        cout << "14. Remove course by code" << endl;

        cout << "0. Quit" << endl;
        cout << "Enter choice: ";        
        cin >> choice;
        cin.ignore(128, '\n');     
      
        switch(choice){
            case 0:
                break;
            case 1:{
                courses.Insert();
                courses.DisplayDirectory(students);
                break;
            }
            case 2:{             
                students.Insert();
                students.DisplayDirectory();
                break;
            }
            case 3:{
                char sname[128];
                cout << "Enter course name to add student: ";
                //cin >> sname;
                //cin.ignore(128, '\n');
                cin.getline(sname, sizeof(sname));
                int cIdx = courses.FindName(sname);
                if(cIdx == -1){
                    cout << "Course not found, try again" << endl;
                     break;
                }
                cout << "Enter student name to enroll: ";
                //cin >> sname;
                //cin.ignore(128, '\n');
                cin.getline(sname, sizeof(sname));
                int sIdx = students.FindName(sname);
                if(sIdx == -1){
                    cout << "Student not found, try again" << endl;
                    break;
                }
                courses.Getcourse(cIdx).Enroll(students.Getstudent(sIdx));
                courses.DisplayDirectory(students);
                break;
            }
            case 4:{
                courses.Update(students);
                courses.DisplayDirectory(students);
                break;
            }
            case 5:{
                students.Update();
                students.DisplayDirectory();
                break;
            }
            case 6:{
                char sname[128];
                cout << "Enter course name to remove student: ";
                //cin >> sname;
                //cin.ignore(128, '\n');
                cin.getline(sname, sizeof(sname));
                int cIdx = courses.FindName(sname);
                if(cIdx == -1){
                    cout << "Course not found, try again" << endl;
                    break;
                }
                courses.Getcourse(cIdx).Show(students);
                int sid;
                cout << "Enter student id to remove from course: ";
                cin >> sid;
                cin.ignore(128, '\n');

                courses.Getcourse(cIdx).RemoveStudent(sid);
                courses.Getcourse(cIdx).Show(students);
                break;
            }
            case 7:{
                courses.DisplayDirectory(students);
                break;
            }
            case 8:{
                students.DisplayDirectory();
                break;
            }
            case 9:{
                    char sname[128];
                    cout << "Enter student name to Find: ";
                    //cin >> sname;
                    //cin.ignore(128, '\n');
                    cin.getline(sname, sizeof(sname));
                    int sIdx = students.FindName(sname);
                    if(sIdx == -1){
                        cout << "Student not found, try again" << endl;
                        break;
                    }
                    students.Getstudent(sIdx).Show();
                    break;
            }			
            case 10:{
                    int sid;
                    cout << "Enter studentid to Find: ";
                    cin >> sid;
                    cin.ignore(128, '\n');
                    int sIdx = students.FindStudentid(sid);
                    if(sIdx == -1){
                        cout << "Student not found, try again" << endl;
                        break;
                    }
                    students.Getstudent(sIdx).Show();
                    break;
            }			
            case 11:{
                    char sname[128];
                    cout << "Enter course name to find: ";
                    //cin >> sname;
                    //cin.ignore(128, '\n');
                    cin.getline(sname, sizeof(sname));
                    int cIdx = courses.FindName(sname);
                    if(cIdx == -1){
                        cout << "Course not found, try again" << endl;
                         break;
                    }
                    courses.Getcourse(cIdx).Show(students);
                    break;
            }			
            case 12:{
                    char scode[32];
                    cout << "Enter course code to find: ";
                    //cin >> scode;
                    //cin.ignore(128, '\n');
                    cin.getline(scode, sizeof(scode));
                    int cIdx = courses.Findcode(scode);
                    if(cIdx == -1){
                        cout << "Course not found, try again" << endl;
                         break;
                    }
                    courses.Getcourse(cIdx).Show(students);
                    break;
            }			
            case 13:{
                    char sloc[32];
                    cout << "Enter location to find course: ";
                    //cin >> sloc;
                    //cin.ignore(128, '\n');
                    cin.getline(sloc, sizeof(sloc));
                    int cIdx = courses.Findlocation(sloc);
                    if(cIdx == -1){
                        cout << "Course not found, try again" << endl;
                         break;
                    }
                    courses.Getcourse(cIdx).Show(students);
                    break;
            }			
            case 14:{
                    char scode[32];
                    cout << "Enter course code to remove: ";
                    //cin >> scode;
                    //cin.ignore(128, '\n');
                    cin.getline(scode, sizeof(scode));
                    int cIdx = courses.Findcode(scode);
                    if(cIdx == -1){
                        cout << "Course not found, try again" << endl;
                         break;
                    }
                    courses.RemovebyIdx(cIdx);
                    courses.DisplayDirectory(students);
                    break;
            }		
            default:
                cout << "[Enter a valid choice]" << endl;
        }
    }
    
    return 0;
}
