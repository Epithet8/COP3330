#include"party.h"

using namespace std;

Party::Party(){
	charactercount = rand()%5+1;
        treasurecount = 0;
	characters = new Character[charactercount];
}
Party::~Party(){
        cout << "deleting characters" << endl;
	delete[]characters;
}
ostream& operator<<(ostream& s, const Party& p) {
        s << "Party treasure:" << p.treasurecount << endl;
        Character* c = p.characters;
	for(int i = 0; i < p.charactercount; i++) {
            s << "character_" << i;
            s << ":[health:" << c->getHealth();
            s << ", power:" << c->getPower() << "]";
            if(i < p.charactercount - 1 ){
                s << endl;
            }
            c++;
	}	
	return s;
}
int Party::getCharactercount(){
    return charactercount;
}
int Party::getTreasurecount(){
    return treasurecount;
}
Character* Party::getCharacters(){
    return characters;
}
void Party::addTreasurecount(int amt){
    treasurecount += amt;
}
void Party::reduceCharactercount(){
    charactercount--;
}