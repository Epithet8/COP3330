#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>

using namespace std;

class Character {
	public:
	
		Character();
                int getHealth();
                int getPower();
                void reduceHealth(int amt);
		
	
	private:
		int health;
		int power;
		


};
#endif