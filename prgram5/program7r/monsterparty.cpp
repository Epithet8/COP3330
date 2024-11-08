#include"monsterparty.h"

using namespace std;
Monsterparty::Monsterparty(){
	monstercount = rand()%5+1;
	monsters = new Monster[monstercount];
	
}
Monsterparty::~Monsterparty(){
        cout << "deleting monsters" << endl;
	delete[]monsters;
	
}

//easier than programing a manual overload
ostream& operator<<(ostream& s, const Monsterparty& mp) {
        Monster* m = mp.monsters;
	for(int i = 0; i < mp.monstercount; i++) {
            s << "monster_" << i;
            s << ":[health:" << m->getHealth();
            s << ", power:" << m->getPower();
            s << ", reward:" << m->getReward() << "]";
            if(i < mp.monstercount - 1 ){
                s << endl;
            }
            m++;
	}	
	return s;
}
int Monsterparty::getMonstercount(){
    return monstercount;
}
Monster* Monsterparty::getMonsters(){
    return monsters;
}