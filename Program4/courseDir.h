#include "course.h"

using namespace std;

class CourseDir {
	
	public:
			
		
		CourseDir();
                
                ~CourseDir();
		
		void Insert();
                void Insert(Course course);
                void Lookup(StudentDir& studentDir) const;
                void Remove();
		void RemovebyIdx(int idx);
                void Update(StudentDir& studentDir);
                void DisplayDirectory(StudentDir& studentDir) const;
                void Grow();
                int FindName(char* aName) const;
                int Findcode(char* acode) const;
                int Findlocation(char* alocation) const;
                Course& Getcourse(int idx);
				
				
	
	private:
                int currentSize;
                int maxSize;
                Course* courseList;
	
	
};

