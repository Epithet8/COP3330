#include"party.h"
#include"monsterparty.h"
#include"dungeon-board.h"
#include <cstdlib>
using namespace std;
bool isPartyAlive(Party& party);
bool isBoardClear(DungeonBoard& db, int size);

int main(){
    int size = 10;
    DungeonBoard db = DungeonBoard(size);//allow it to default to 10 later
    Party party = Party();
    cout << party << endl;
    cout << db << endl;
    cout << "Valid commands: (q)uit, (p)rint party, i-up, m-down, j-left, r-right" << endl;
    char c;
    cin >> c;
    while(c != 'q'){
        switch(c){
            case 'p':
                cout << party << endl;
                break;
            default:
                party.addTreasurecount(db.movePlayer(c, party));
                bool pAlive = isPartyAlive(party);
                if(!pAlive){
                    cout << "Party lost___" << endl;
                    return 1;
                }
                bool bClear = db.isBoardClear();
                if(bClear){
                    cout << "Party won!!!" << endl;
                    return 0;
                }
        }
        cout << db << endl;
        cout << "Valid commands: (q)uit, (p)rint party, i-up, m-down, j-left, k-right" << endl;
        cin >> c;
    }
    return 0;
}
bool isPartyAlive(Party& party){
    bool alive = false;
    Character* characters = party.getCharacters();
    for(int i=0; i<party.getCharactercount(); i++){
        if(characters[i].getHealth() > 0){
            alive = true;
        }else if(i < party.getCharactercount() - 1){
            for(int j=i; j<party.getCharactercount(); j++){
                characters[i] = characters[i + 1];
            }
            party.reduceCharactercount();
        }
    }
    return alive;
}