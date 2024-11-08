#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
	
	public:
			
		Student();
		Student(char* name, char classification, char* major, int studentid);
		~Student();
                
		char * Getname ();
                char Getclassification();
		char * Getmajor();		
		int Getstudentid();
		
                
                void Load();
                void Show();
    
                friend ostream& operator<<(ostream& output, const Student& s);
	private:
                char * name;
                char classification;
		char * major;			
		int studentid; 
	
	
};
#endif

