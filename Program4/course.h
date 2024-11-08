#include "studentDir.h"
#include <string>

using namespace std;

class Course {
	
	public:
			
		
		Course();
                Course(char* name, char* code, char* location);
                
                ~Course();
		
		
		int GetrosterLen();
                char* Getname ();
		char* Getcode();
		char* Getlocation();
		int* Getroster();
               
                void Load();
                void Enroll(Student&);
                void RemoveStudent(int sid);
                void Show(StudentDir& studentDi);

                friend ostream& operator<<(ostream& output, const Course& c);
	private:
                char* name;
		char code[7];
		char location[10];
                int rosterLen;
		int* roster;
		int maxLen;
		StudentDir* studentDir;
	
};
