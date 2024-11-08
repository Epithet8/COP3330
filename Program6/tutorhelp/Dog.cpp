#include "Dog.h"

using namespace std;

Dog::Dog(const string& name){
    animalName = name;
}

Dog::~Dog(){}

// here we implement the interface
void Dog::animalSound(){    
    cout << animalName << " woof" << endl;
}
