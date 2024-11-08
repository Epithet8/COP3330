#ifndef MONSTER_H
#define MONSTER_H

using namespace std;
class Monster {
	public:
	
		Monster();
                int getHealth();
                int getPower();
                int getReward();
                void reduceHealth(int amt);
		
	
	private:
		int health;
		int power;
		int reward;


};
#endif