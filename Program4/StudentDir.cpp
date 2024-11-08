#include <iostream>
#include <cstring>		// for strcmp
#include "studentDir.h"

using namespace std;

StudentDir::StudentDir()			
// Set up empty directory of entries.
{ 
   maxSize = 2; 
   currentSize = 0; 
   studentList = new Student[maxSize];
}

StudentDir::~StudentDir()
// This destructor function for class StudentDir
// deallocates the directory's list of Entry objects.
{
   delete [] studentList;
}

void StudentDir::Insert()
// Insert a new entry into the direrctory.
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();
   studentList[currentSize++].Load();	// read new entry.
}

void StudentDir::Insert(Student student)
// Insert a new entry into the direrctory.
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();
   studentList[currentSize++] =student;	// read new entry.
}

void StudentDir::Lookup() const
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
	studentList[thisEntry].Show();	// display entry.
   }
}

void StudentDir::Remove()
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
		studentList[j - 1] = studentList[j];
			
	currentSize--;		// Decrement the current number of entries.
	cout << "Entry removed.\n";
   }
}

void StudentDir::Update()
// Update an existing directory entry by reentering
// each of its values (name, phone, and room number).
{
   cout << "\nPlease enter the name of the student to be modified: ";
   char aName[20];
   cin.getline(aName, 20);

   int thisEntry = FindName(aName);
	
   if (thisEntry == -1)
	cout << aName << " not found in current directory\n";
   else
   {
	cout << "\nCurrent entry is: \n";
	studentList[thisEntry].Show();		// Display the current entry.
		
	cout << "\nReplace with new entries as follows: \n";
	studentList[thisEntry].Load();		// Get new values for entry.
   }
}

void StudentDir::DisplayDirectory() const
// Display the current directory entries
// on the standard output (the screen).
{
   if (currentSize == 0)
   {
	cout << "\nCurrent directory is empty.\n";
	return;
   }
	
   for (int i = 0; i < currentSize; i++)	// For each entry,
	studentList[i].Show();			// send it to output
}

void StudentDir::Grow()
// Double the size of the directory's entry list
// by creating a new, larger array of entries
// and changing the directory's pointer to refer to
// this new array.
{
   maxSize = currentSize + 1;			// Determine a new size.
   Student* newList = new Student[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++)	// Copy each entry into
	newList[i] = studentList[i];		// the new array.
		
   delete [] studentList;			// Remove the old array
   studentList = newList;			// Point old name to new array.
}

int StudentDir::FindName(char* aName) const
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
   for (int i = 0; i < currentSize; i++)	// Look at each entry.
	if (strcmp(studentList[i].Getname(), aName) == 0)
		return i;		// If found, return position and exit.
			
   return -1;				// Return -1 if never found.
 }
 
int StudentDir::FindStudentid(int id) const

{
   for (int i = 0; i < currentSize; i++)	// Look at each entry.
	if (id == studentList[i].Getstudentid())
		return i;		// If found, return position and exit.
			
   return -1;				
  }
  
Student& StudentDir::Getstudent(int idx){
    return studentList[idx];
}