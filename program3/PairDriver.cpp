#include "Pair.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    //ordered pairs that where given

	Pair op1=Pair(4,1);
	Pair op2=Pair(1,3);
	Pair op3=Pair(2,4);
	Pair op4=Pair(4,9);
	Pair op5=Pair(6,7);
	Pair op6=Pair(3,10);
	Pair op7=Pair(1,17);
	Pair op8=Pair(9,2);
	
	
	Pair p0 = Pair(0,0);
	Pair p1 = Pair(1, 3);
    Pair p2 = Pair(3, 8);
    Pair p3 = p1 + p2;
    double p4 = p1 * p2;
    Pair p5 = 7 * p1;
    Pair p6 = p1 * 7;
    
	//
	cout<<p1 + p0<<endl;
	cout<<7*op8<<endl;
    cout<<p4<<endl;
 // cout<<p5<<endl;
 // cout<<p6<<endl;
   //out<<((op6*op7)*op1-(op2+op3))<<endl;
	cout<<(((3,10)*(1,17))*(4,1)) + ((1,3)-(2,4))<<endl;
	cout<<(((4,9)*(6,7))*(4,1)) - ((1,3)+(2,4))<<endl;
    if(p1 == p3){
        cout<<p1<<" equals "<<p3<<endl;
    }else{
        cout<<p1<<" does not equal "<<p3<<endl;
    }
    return 0;
}

