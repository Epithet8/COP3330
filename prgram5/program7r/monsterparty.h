#include"monster.h"
#include<iostream>

using namespace std;
class Monsterparty {
        friend ostream& operator<<(ostream& s, const Monsterparty& m);
	public:
	
		Monsterparty();
		~Monsterparty();
                int getMonstercount();
                Monster* getMonsters();
	
	private:
		int monstercount;
		
		Monster* monsters;
};