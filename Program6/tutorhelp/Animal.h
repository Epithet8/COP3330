	#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal();
    Animal(const string& name);

    virtual ~Animal();

    virtual void animalSound();

protected:
    string animalName;
};

#endif /* ANIMAL_H */

