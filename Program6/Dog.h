#ifndef DOG_H
#define DOG_H

#include "Animal.h"

using namespace std;

class Dog: public Animal
{
public:
    Dog(const string& name);
    ~Dog();

    void animalSound() override;
};

#endif /* DOG_H */

