#include"monster.h"
#include<stdlib.h>
using namespace std;
Monster::Monster(){
	health = rand()%35+1;
	while (health < 15){
		health = rand()%35+1;
	}
	power = rand()%6+1;
	reward = rand()%10+1;//check to see the reward generation ask prof or ta
	
	
	
}
int Monster::getHealth(){
    return health;
}
int Monster::getPower(){
    return power;
}
int Monster::getReward(){
    return reward;
}
void Monster::reduceHealth(int amt){
    health -= amt;
}