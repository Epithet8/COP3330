#include <valarray>

#include "Animal.h"

using namespace std;

Animal::Animal(){
    animalName = "noname";
}

Animal::Animal(const string& name){
    animalName = name;
}

Animal::~Animal(){}

void Animal::animalSound(){
    cout << "no sound" << endl;
}      
