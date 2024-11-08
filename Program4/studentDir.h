#ifndef STUDENTDIR_H
#define STUDENTDIR_H

#include "student.h"
using namespace std;

class StudentDir {
	
	public:
			
		
		StudentDir();
                
                ~StudentDir();
		
		void Insert();
                void Insert(Student student);
                void Lookup() const;
                void Remove();
                void Update();
                void DisplayDirectory() const;
                void Grow();
                int FindName(char* aName) const;
				int FindStudentid(int id) const;
                Student& Getstudent(int idx);

	
	private:
                int currentSize;
                int maxSize;
                Student* studentList;
	
	
};
#endif

