#include <cstdlib>
#include <iostream>

#include "DoubleContainer.h"

using namespace std;

int main(int argc, char** argv) {
   
    DoubleContainer v1, v2;
    
    // pre-loaded courses to speed up testing
    v1.Add(-1.23); v2.Add(-3.21);
    v1.Add(1.5); v2.Add(4.6);
    v1.Add(1.7); v2.Add(5.7);
    v1.Add(2.3); v2.Add(6.2);
    v1.Add(3.1); v2.Add(7.5);
    v1.Add(4.4); v2.Add(8.9); 
    cout << "pre-loaded V1: " << v1 << endl;
    cout << "pre-loaded V2: " << v2 << endl;
         
    int choice = -1;
    while(choice != 0){
        cout << "1. Add to V1 and V2 vectors" << endl;
        cout << "2. Clear V1 and V2 vectors" << endl;
        cout << "3. Remove last V1 and V2 values" << endl;
        cout << "4. Display vectors" << endl;
        cout << "5. V1 + V2" << endl;
        cout << "6. V1 - V2" << endl;
        cout << "7. -V1, -V2" << endl;
        cout << "8. x * V1, V2 * x" << endl;
        cout << "9. V1 * V2" << endl;
        cout << "10. Deep Copy by content constructor V1->V3 " << endl;
        cout << "11. Deep Copy by object constructor V2->V4 " << endl;
        cout << "12. Deep Copy by assignment operator V1->V5 " << endl;

        cout << "0. Quit" << endl;
        cout << "Enter choice: ";        
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(128, '\n');
            choice = -1;
        }else{
            cin.ignore(128, '\n');
        }
      
        switch(choice){
            case 0:
                break;
            case 1:{
                cout << "Enter V1 value: ";
                double value;
                cin >> value;
                v1.Add(value);
                cout << "Enter V2 value: ";
                cin >> value;
                v2.Add(value);
                cout << "V1: " << v1 << endl;
                cout << "V2: " << v2 << endl;
                break;
            }
            case 2:{
                cout << "Clearing V1 and V2 vectors:" << endl;
                v1.Clear();
                v2.Clear();
                cout << "V1: " << v1 << endl;
                cout << "V2: " << v2 << endl;
                break;
            }
            case 3:{
                cout << "Removed last V1 value: " << v1.Remove() << endl;
                cout << "Removed last V2 value: " << v2.Remove() << endl;
                break;
            }
			
            case 4:{
                cout << "Displaying V1 and V2 vectors:" << endl;
                cout << "V1: " << v1 << endl;
                cout << "V2: " << v2 << endl;
                break;
            }			
            case 5:{
                if(v1.getLength() != v2.getLength()){
                    cout << "V1 and V2 are of different lengths" << endl;
                    break;
                }
                cout << "  V1: " << v1 <<endl;
                cout << "+ V2:" << v2 << endl;
                DoubleContainer* ans = new DoubleContainer(v1 + v2);
                cout << "=   :" << *ans << endl;\
                delete ans;
                break;
            }			
            case 6:{
                if(v1.getLength() != v2.getLength()){
                    cout << "V1 and V2 are of different lengths" << endl;
                    break;
                }
                cout << "  V1: " << v1 <<endl;
                cout << "- V2:" << v2 << endl;
                DoubleContainer* ans = new DoubleContainer(v1 - v2);
                cout << "=   :" << *ans << endl;
                delete ans;
                break;
            }
            case 7:{
                DoubleContainer* ans = new DoubleContainer(-v1);
                cout << "-V1 = " << *ans << endl;
                ans = new DoubleContainer(-v2);
                cout << "-V2 = " << *ans << endl;
                delete ans;
                break;
            }
            case 8:{
                double value;
                cout << "Enter Scaling value: ";
                cin >> value;
                DoubleContainer* ans = new DoubleContainer(value * v1);
                cout << "x * V1 = " << *ans << endl;
                ans = new DoubleContainer(v2 * value);
                cout << "V2 * x = " << *ans << endl;
                delete ans;
                break;
            }
            case 9:{
                double sum = v1 * v2;
                cout << "dot product of V1 and V2: " << sum << endl;
                break;
            }
            case 10:{
                DoubleContainer* v3 = new DoubleContainer(v1.getContent(), v1.getLength());
                cout << "V3: " << *v3 << endl;
                delete v3;
                break;
            }
            case 11:{
                DoubleContainer* v4 = new DoubleContainer(v2);
                cout << "V4: " << *v4 << endl;
                delete v4;
                break;
            }
            case 12:{
                DoubleContainer v5 = v1;
                cout << "V5: " << v5 << endl;
                break;
            }

            default:
                cout << "[Enter a valid choice]" << endl;
        }
    }
    
    return 0;
}
