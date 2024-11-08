#include"character.h"
#include <cstdlib>
using namespace std;
Character::Character(){
	health = rand()%100+1;
	while (health < 80){
		health = rand()%100+1;
	}
	power = rand()%10+1;
	while (power < 4){
		power = rand()%10+1;
	}	
}
int Character::getHealth(){
    return health;
}
int Character::getPower(){
    return power;
}
void Character::reduceHealth(int amt){
    
    health -= amt;
}