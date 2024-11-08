#ifndef COW_H
#define COW_H

#include "Animal.h"

using namespace std;

class Cow: public Animal
{
public:
    Cow(const string& name);
    ~Cow();

    void animalSound() override;
};

#endif /* COW_H */

