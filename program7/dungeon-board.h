#include<iostream>
#include"party.h"
using namespace std;

class DungeonBoard {
	friend ostream& operator<<(ostream& s, const DungeonBoard& db);
	public:
		DungeonBoard(int _size);
		~DungeonBoard();
                int movePlayer(char c, Party& party);
                int getTreasure(int row, int col);
                int doBattle(int row, int col, Party& party);
				bool isBoardClear();
				void moveMob(int y_cur, int x_cur);
	private:
		//data
		const int maxTreasures;
		int numTreasures;
		const int maxMobs;
		int numMobs;
		int size;
		char** boardState;
		int** treasures;
		int** mobs;
		
                int x_cur;
                int y_cur;
                
		//entrance
		int x_enter;
		int y_enter;
		
		//exit
		int x_exit;
		int y_exit;
		
		//functionality
		void setupEntrance();
		void setupTreasure();
		void setupMobs();

};