#include <iostream>
#include <cstring>		// for strcmp
#include "courseDir.h"

using namespace std;

CourseDir::CourseDir()			
// Set up empty directory of entries.
{ 
   maxSize = 2; 
   currentSize = 0; 
   courseList = new Course[maxSize];
}

CourseDir::~CourseDir()
// This destructor function for class CourseDir
// deallocates the directory's list of Entry objects.
{
   delete [] courseList;
}

void CourseDir::Insert()
// Insert a new entry into the direrctory.
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();
   courseList[currentSize++].Load();	// read new entry.
}

void CourseDir::Insert(Course course)
// Insert a new entry into the direrctory.
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();
   courseList[currentSize++] = course;	// read new entry.
}

void CourseDir::Lookup(StudentDir& studentDir) const
//  Display the directory entry for a name.
{
   // Prompt the user for a name to be looked up
   char aName[20];
   cout << "\tType the name to be looked up, followed by <Enter>: ";
   cin.getline(aName, 20);
	
   int thisEntry = FindName(aName);	// Locate the name in the directory.
	
   if (thisEntry == -1)
	cout << aName << " not found in current directory\n";
   else
   {
	cout << "\nEntry found: ";
	courseList[thisEntry].Show(studentDir);	// display entry.
   }
}

void CourseDir::Remove()
// Remove an entry from the directory.
{
   // Prompt the user for the name to be removed.
   char aName[20];
   cout << "\nType name to be removed, followed by <Enter>: ";
   cin.getline(aName, 20);
	
   int thisEntry = FindName(aName);	// Locate the name in the directory.
	
   if (thisEntry == -1)
	cout << aName << " not found in directory";
   else
   {
	// Shift each succeding element "down" one position in the
	// Entry array, thereby deleting the desired entry.
	for (int j = thisEntry + 1; j < currentSize; j++)
		courseList[j - 1] = courseList[j];
			
	currentSize--;		// Decrement the current number of entries.
	cout << "Entry removed.\n";
   }
}


void CourseDir::RemovebyIdx(int idx)
// Remove an entry from the directory.
{
	for (int j = idx + 1; j < currentSize; j++)
		courseList[j - 1] = courseList[j];
			
	currentSize--;		
	cout << "Entry removed.\n";
   
}


void CourseDir::Update(StudentDir& studentDir)
// Update an existing directory entry by reentering
// each of its values (name, phone, and room number).
{
   cout << "\nPlease enter the name of the course to be modified: ";
   char aName[20];
   cin.getline(aName, 20);

   int thisEntry = FindName(aName);
	
   if (thisEntry == -1)
	cout << aName << " not found in current directory\n";
   else
   {
	cout << "\nCurrent entry is: \n";
	courseList[thisEntry].Show(studentDir);		// Display the current entry.
		
	cout << "\nReplace with new entries as follows: \n";
	courseList[thisEntry].Load();		// Get new values for entry.
   }
}

void CourseDir::DisplayDirectory(StudentDir& studentDir) const
// Display the current directory entries
// on the standard output (the screen).
{
   if (currentSize == 0)
   {
	cout << "\nCurrent directory is empty.\n";
	return;
   }
	
   for (int i = 0; i < currentSize; i++)	// For each entry,
	courseList[i].Show(studentDir);			// send it to output
}

void CourseDir::Grow()
// Double the size of the directory's entry list
// by creating a new, larger array of entries
// and changing the directory's pointer to refer to
// this new array.
{
   maxSize = currentSize + 1;			// Determine a new size.
   Course* newList = new Course[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++)	// Copy each entry into
	newList[i] = courseList[i];		// the new array.
		
   delete [] courseList;			// Remove the old array
   courseList = newList;			// Point old name to new array.
}

int CourseDir::FindName(char* aName) const
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
   for (int i = 0; i < currentSize; i++)	// Look at each entry.
	if (strcmp(courseList[i].Getname(), aName) == 0)
		return i;		// If found, return position and exit.
			
   return -1;				// Return -1 if never found.
}

int CourseDir::Findcode(char* acode) const
{
   for (int i = 0; i < currentSize; i++)	
	if (strcmp(courseList[i].Getcode(), acode) == 0)
		return i;		
			
   return -1;				
}

int CourseDir::Findlocation(char* alocation) const

{
   for (int i = 0; i < currentSize; i++)	// Look at each entry.
	if (strcmp(courseList[i].Getlocation(), alocation) == 0)
		return i;		
			
   return -1;				
}

Course& CourseDir::Getcourse(int idx){
    return courseList[idx];
}