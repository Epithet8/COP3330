#include "Cow.h"

using namespace std;
Cow::Cow(const string& name){
    animalName = name;
}

Cow::~Cow(){}

// here we implement the interface
void Cow::animalSound(){    
    cout << animalName << " MOO!" << endl;
}
