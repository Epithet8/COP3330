#ifndef PARTY_H
#define PARTY_H

#include"character.h"
#include<iostream>
using namespace std;
class Party {
        friend ostream& operator<<(ostream& s, const Party& p);
	public:                
		Party();
		~Party();
                int getCharactercount();
                int getTreasurecount();
                Character* getCharacters();
                void addTreasurecount(int amt);
                void reduceCharactercount();
	
	private:
		int charactercount;
		int treasurecount;
		Character* characters;
		

};
#endif