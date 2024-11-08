#include "pig.h"

using namespace std;
Pig::Pig(const string& name){
    animalName = name;
}

Pig::~Pig(){}

// here we implement the interface
void Pig::animalSound(){    
    cout << animalName << " Oink" << endl;
}
