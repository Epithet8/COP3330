#include <cstdlib>
#include "Dog.h"
#include "cat.h"
#include "pig.h"
#include "Cow.h"
using namespace std;
Animal** grow(int cnt, int& maxSize, Animal**animals);
/*
 * 
 */
int main(int argc, char** argv) {
    int cnt = 0;
	int maxSize =2;
	
	Animal **animals=new Animal*[maxSize];
	string name;
	int count = 0;
	int choice = -1;
    while(choice != 0){
        cout << "1. Add Dog" << endl;
        cout << "2. Add Cat" << endl;
        cout << "3. Add Pig" << endl;
        cout << "4. add Cow" << endl;
		cout << "5. Print list of animals" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter choice: ";        
        cin >> choice;
        cin.ignore(128, '\n');     
      
        switch(choice){
            case 0:
                break;
            case 1:{
				
				cout << "Enter name of the Dog: "<<endl;
				cin>>name;
				if(cnt==maxSize){
					animals = grow(cnt,maxSize,animals);
				}
                animals [count++] = new Dog(name);
                break;
            }
            case 2:{             
                cout << "Enter name of the Cat: "<<endl;
				cin>>name;
				if(cnt==maxSize){
					animals = grow(cnt,maxSize,animals);
				}
                animals [count++] = new Cat(name);
                break;
            }
            case 3:{
                cout << "Enter name of the Pig: "<<endl;
				cin>>name;
				if(cnt==maxSize){
					animals = grow(cnt,maxSize,animals);
				}
                animals [count++] = new Pig(name);
                break;
            }
            case 4:{
                cout << "Enter name of the Cow: "<<endl;
				cin>>name;
				if(cnt==maxSize){
					animals = grow(cnt,maxSize,animals);
				}
                animals [count++] = new Cow(name);
                break;
            }
            case 5:{
                cout << "List of animals"<<endl;
				for(int i = 0; i < count;i++){
					animals[i]->animalSound();
				}
                break;
            }
            
            default:
                cout << "[Enter a valid choice]" << endl;
				
			
        }
    }
   


   /*Dog dog = Dog("cody");
    dog.animalSound();
	Cat cat = Cat("blade");
	cat.animalSound();
	Pig pig = Pig("Porkers");
    pig.animalSound();
	Cow cow = Cow("Moolisa");
	cow.animalSound();
    return 0;
}*/


	return 0;
}

Animal** grow(int cnt, int& maxSize, Animal** animals){
    maxSize += 2;
    Animal** newAnimals = new Animal*[++maxSize];
    for(int i=0; i<cnt; i++){
        newAnimals[i] = animals[i];
    }
    delete[] animals;
    return newAnimals;        
}

