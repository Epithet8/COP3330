#include <iostream>
#include "DoubleContainer.h"

using namespace std;

DoubleContainer::DoubleContainer()			
{ 
   // cout << "Default Constructor: " << endl;
   maxSize = 5; 
   currentSize = 0; 
   content = new double[maxSize];
}

DoubleContainer::DoubleContainer(double* contentp, int len)			
{ 
   // cout << "Content Constructor: " << endl;
   maxSize = len + 5; 
   currentSize = len;
   content = new double[maxSize];
   for(int i=0; i<len; i++){
       content[i] = contentp[i];
   }
}

DoubleContainer::DoubleContainer(const DoubleContainer& contain)			
{ 
   // cout << "Container Constructor: " << endl;
   int len = contain.currentSize;
   maxSize = len + 5; 
   currentSize = len;
   content = new double[maxSize];
   for(int i=0; i<len; i++){
       content[i] = contain.content[i];
   }
}

DoubleContainer::~DoubleContainer()
{
   delete [] content;
}

int DoubleContainer::getLength(){
    return currentSize;
}

double* DoubleContainer::getContent(){
    return content;
}

void DoubleContainer::Add(double value)
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();
   content[currentSize++] = value;	// read new entry.
}

void DoubleContainer::Clear()
{
   delete [] content;
   maxSize = 5; 
   currentSize = 0; 
   content = new double[maxSize];
}

double DoubleContainer::Remove()
{
    double tmp = content[currentSize - 1];
    content[--currentSize] = 0;
    return tmp;
}

void DoubleContainer::Grow()
{
   maxSize = currentSize + 5;			// Determine a new size.
   double* newContent = new double[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++){	// Copy each entry into
	newContent[i] = content[i];
   }
        
		
   delete [] content;			// Remove the old array
   content = newContent;			// Point old name to new array.
}

ostream& operator<<(ostream& output, const DoubleContainer& dc) {
    int len = dc.currentSize;
    output << "<";    
    for(int i=0; i<len; i++){
        output << dc.content[i];
        if(i < len - 1){
            output << ", ";
        }
    }
    output << ">";
    return output;
}

DoubleContainer DoubleContainer::operator=(const DoubleContainer& dc){
   // cout << "Operator= copy:" << endl;
   int len = dc.currentSize;
   maxSize = len + 5; 
   currentSize = len;
   content = new double[maxSize];
    for(int i=0; i<len; i++){
        content[i] = dc.content[i];
    }
    return *this;
}

DoubleContainer operator+(DoubleContainer& dc1, const DoubleContainer& dc2){
    DoubleContainer ans;
    ans = dc1;
    for(int i=0; i<ans.currentSize; i++){
        ans.content[i] += dc2.content[i];
    }
    return ans;
}

DoubleContainer operator-(DoubleContainer& dc1, const DoubleContainer& dc2){
    DoubleContainer ans;
    ans = dc1;
    for(int i=0; i<ans.currentSize; i++){
        ans.content[i] -= dc2.content[i];
    }
    return ans;
}

// unary operator-, negate overload
DoubleContainer operator-(const DoubleContainer& dc1){
    // need to deal with unequal lengths
    DoubleContainer ans;
    ans = dc1;
    for(int i=0; i<ans.currentSize; i++){
        ans.content[i] *= -1;
    }
    return ans;
}

DoubleContainer operator*(double d, const DoubleContainer& dc2){
    // need to deal with unequal lengths
    DoubleContainer ans;
    ans = dc2;
    for(int i=0; i<ans.currentSize; i++){
        ans.content[i] *= d;
    }
    return ans;
}

DoubleContainer operator*(DoubleContainer& dc1, const double d){
    // need to deal with unequal lengths
    DoubleContainer ans;
    ans = dc1;
    for(int i=0; i<ans.currentSize; i++){
        ans.content[i] *= d;
    }
    return ans;
}

double operator*(DoubleContainer& dc1, const DoubleContainer& dc2){
    double sum = 0;    
    for(int i=0; i<dc1.currentSize; i++){
        sum += dc1.content[i] * dc2.content[i];
    }
    return sum;
} 