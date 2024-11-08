#ifndef CAT_H
#define CAT_H

#include "Animal.h"

using namespace std;

class Cat: public Animal
{
public:
    Cat(const string& name);
    ~Cat();

    void animalSound() override;
};

#endif /* CAT_H */

