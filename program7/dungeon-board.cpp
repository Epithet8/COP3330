#include "dungeon-board.h"
#include"monsterparty.h"
#include <cstdlib>
DungeonBoard::DungeonBoard(int _size=10):maxTreasures(_size/2),maxMobs(_size) {
	
	size = _size;
	//allocate a new board
	boardState = new char*[size];
	for(int i = 0; i < size; i++) {
		boardState[i] = new char[size];
		for(int j = 0; j < size; j++) {
			if(i == 0 || i == size-1) {
				boardState[i][j]= '-';
				continue;
			} else if (j == 0 || j == size-1) {
				boardState[i][j] = '|';
				continue;
			}
			boardState[i][j] = ' ';
		}
	}
	
	//set the entrance
	setupEntrance();
	//set the treasures
	setupTreasure();
	//set the mobs
	setupMobs();
}

DungeonBoard::~DungeonBoard() {
	cout << "Destroying game board state..." << endl;
	for(int i = 0; i < size; i++) {
		delete [] boardState[i];
	}
	delete [] boardState;
	
	cout << "Destroying mob state..." << endl;
	for(int i = 0; i < numMobs; i++) {
		cout << "Destroying mob " << i << endl;
		delete [] mobs[i];
	}
	cout << "Destroying mob list..." << endl;
	delete [] mobs;
	
	cout << "Destroying treasure state..." << endl;
	for(int i = 0; i < numTreasures; i++) {
		cout << "Destroying treasure " << i << endl;
		delete [] treasures[i];
	}
	delete [] treasures;
}

ostream& operator<<(ostream& s, const DungeonBoard& db) {
	for(int i = 0; i < db.size; i++) {
		for(int j = 0; j < db.size; j++) {
			s << db.boardState[i][j] << "\t";
		}
		s << endl<<endl;
	}
	
	return s;
}

void DungeonBoard::setupEntrance() {
	//find the entry
	srand(time(0));
	//pick a number 0-3 to figure out what wall the entrance will be on
	int wall = rand()%4;
	//pick a number 1-8 to figure out what position on that wall the entrance will be at (this keeps the door from being in a corner)
	int pos = rand()%(size-2) + 1;
	switch(wall) {
		case 0:
			boardState[pos][0] = 'X';
			boardState[pos-1][0] = '-';
			boardState[pos+1][0] = '-';
                        y_cur = pos;
                        x_cur = 0;
			break;
		case 1:
			boardState[0][pos] = 'X';
			boardState[0][pos-1] = '|';
			boardState[0][pos+1] = '|';
                        y_cur = 0;
                        x_cur = pos;
			break;
		case 2:
			boardState[pos][size-1] = 'X';
			boardState[pos-1][size-1] = '-';
			boardState[pos+1][size-1] = '-';
                        y_cur = pos;
                        x_cur = size - 1;
			break;
		case 3:
			boardState[size-1][pos] = 'X';
			boardState[size-1][pos-1] = '|';
			boardState[size-1][pos+1] = '|';
                        y_cur = size - 1;
                        x_cur = pos;
			break;
	}
}

void DungeonBoard::setupTreasure() {
	numTreasures = rand() % maxTreasures + 1;
	treasures = new int*[numTreasures];
	for(int i = 0; i < numTreasures; i++) {
		//get row
		int row = rand()%(size-2) + 1;
		//get column
		int column = rand()%(size-2) + 1;
		//place treasures
		boardState[row][column] = 'T';

		treasures[i] = new int[2];
		treasures[i][0] = row;
		treasures[i][1] = column;
		cout << "Allocated treasure " << i << endl; 
	}
}

void DungeonBoard::setupMobs() {
	numMobs = rand() % maxMobs + 1;
	mobs = new int*[numMobs];
	for(int i = 0; i < numMobs; i++) {
		//get row
		int row = rand()%(size-2) + 1;
		//get column
		int column = rand()%(size-2) + 1;
		//place treasures
		boardState[row][column] = 'M';
		mobs[i] = new int[2];
		mobs[i][0] = row;
		mobs[i][1] = column;
		cout << "Allocated mob " << i << endl;
	}
}

int DungeonBoard::movePlayer(char c, Party& party){
    int treasure = 0;
	
	int state = 0;
    switch(c){
        case 'i'://up
            if(y_cur > 1 && boardState[y_cur - 1][x_cur] != '-'){
                if(boardState[y_cur - 1][x_cur] == 'T'){
                    treasure = getTreasure(y_cur - 1, x_cur);
                }else if(boardState[y_cur - 1][x_cur] == 'M'){
				  state =	doBattle(y_cur - 1, x_cur,party);
                }
                boardState[y_cur--][x_cur] = ' ';
                boardState[y_cur][x_cur] = 'X';
				if(state == -1){
					moveMob(y_cur,x_cur);
				}
            }else{
                cout << " Invalid move" << endl;
            }
            break;
        case 'm'://down
            if(y_cur < size - 2 && boardState[y_cur + 1][x_cur] != '-'){
                if(boardState[y_cur + 1][x_cur] == 'T'){
                    treasure = getTreasure(y_cur + 1, x_cur);
                }else if(boardState[y_cur + 1][x_cur] == 'M'){
                  state = doBattle(y_cur + 1, x_cur,party);
                }
                boardState[y_cur++][x_cur] = ' ';
                boardState[y_cur][x_cur] = 'X';
				if(state == -1){
					moveMob(y_cur,x_cur);
				}
            }else{
                cout << " Invalid move" << endl;
            }
            break;
        case 'j'://left
            if(x_cur > 1 && boardState[y_cur][x_cur - 1] != '|'){
                if(boardState[y_cur][x_cur - 1] == 'T'){
                    treasure = getTreasure(y_cur, x_cur - 1);
                }else if(boardState[y_cur][x_cur - 1] == 'M'){
                  state = doBattle(y_cur, x_cur - 1,party);
                }
                boardState[y_cur][x_cur--] = ' ';
                boardState[y_cur][x_cur] = 'X';
				if(state == -1){
					moveMob(y_cur,x_cur);
				}
            }else{
                cout << " Invalid move" << endl;
            }
            break;
        case 'k'://right
            if(x_cur < size - 2 && boardState[y_cur][x_cur + 1] != '|'){
                if(boardState[y_cur][x_cur + 1] == 'T'){
                    treasure = getTreasure(y_cur, x_cur + 1);
                }else if(boardState[y_cur][x_cur + 1] == 'M'){
                  state = doBattle(y_cur, x_cur + 1,party);
                }
                boardState[y_cur][x_cur++] = ' ';
                boardState[y_cur][x_cur] = 'X';
				if(state == -1){
					moveMob(y_cur,x_cur);
				}
            }else{
                cout << " Invalid move" << endl;
            }
            break;
        default:
            cout << "Bad input" << endl;
    }
    return treasure;
}

int DungeonBoard::getTreasure(int trow, int tcol){
    cout << " Getting Treasure" << endl;
    for(int i=0; i<numTreasures; i++){
        if(treasures[i][0] == trow && treasures[i][1] == tcol){
            return rand() % 10 + 1;;
        }
    }
    return 0;
}


void DungeonBoard::moveMob(int row, int col){
    cout << "Moving Mob" << endl;
    int trow = rand()%(size-2) + 1;
    int tcol = rand()%(size-2) + 1;
    while(boardState[trow][tcol] != ' '){
        trow = rand()%(size-2) + 1;
        tcol = rand()%(size-2) + 1;
    }
    for(int i=0; i<numMobs; i++){
        if(mobs[i][0] == row && mobs[i][1] == col){
            boardState[trow][tcol] = 'M';
            mobs[i][0] = trow;
            mobs[i][1] = tcol;
            break;
        }
    }
}


bool DungeonBoard::isBoardClear(){
    bool clear = true;
    for(int row=1; row<size - 1; row++){
        for(int col=1; col<size - 1; col++){
            if(boardState[row][col] != ' ' && boardState[row][col] != 'X'){
                clear = false;
            }
        }
    }
    return clear;
}


int DungeonBoard::doBattle(int mrow, int mcol, Party& party){
    cout << " Doing Battle" << endl;
	Monsterparty mparty = Monsterparty();
	Monster* monsters = mparty.getMonsters();
	cout<<mparty<<endl;
	Character* characters = party.getCharacters();
	cout<< "Enter: R to run, or A to attack"<<endl;
	char c;
	cin>>c;
	int state = 1;
	while(state!=0){
		int chance = 0;
		switch (c){
			case 'R':case'r':
			chance = 50 - (mparty.getMonstercount()-1) * 10;
			if (rand()%100 + 1 > chance){
				cout<<"You ran away succesfully"<<endl;
				state = -1;
				return state;
				
			}
			else{
				cout<<"Failed to run away"<<endl;
			}
			//break;  //we need to continue the battle still
			case 'A':case'a':
			cout<<party<<endl;
			for(int i=0;i<party.getCharactercount();i++ ){
				cout<<"What monster does "<<i<<" attack"<<endl;
				int monstern;
				cin>>monstern;
				if(rand()%100+1 > 15){
					monsters[monstern].reduceHealth(characters[i].getPower());
				}
			}
			break;
			default: cout<<"Wrong input"<<endl;
		}
		state=0;
		for(int i=0;i<mparty.getMonstercount();i++){
			if(monsters[i].getHealth()>0){
				state = 1; 
				int ch = rand()% party.getCharactercount();
				if(rand()%100+1 > 50){
					characters[ch].reduceHealth(monsters[i].getPower());
				}
			}
		}
		cout<<mparty<<endl;
		
		if(state==0){
			for(int i=0;i<mparty.getMonstercount();i++){
				party.addTreasurecount(monsters[i].getReward());
			}
				
		}
	}
	return state;
}