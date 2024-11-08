#include "cat.h"

using namespace std;
Cat::Cat(const string& name){
    animalName = name;
}

Cat::~Cat(){}

// here we implement the interface
void Cat::animalSound(){    
    cout << animalName << " Meow" << endl;
}
