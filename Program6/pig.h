#ifndef PIG_H
#define PIG_H

#include "Animal.h"

using namespace std;

class Pig: public Animal
{
public:
    Pig(const string& name);
    ~Pig();

    void animalSound() override;
};

#endif /* PIG_H */

