//hello
#include<iostream>
#include "line.h"
using namespace std;

//uses lines perpendicuolar to each other
int main(){
    Line basic = Line();
	Line basic2 = Line( 2,3);
	Line basic3 = Line(4,3,0.75);
	Line basic4 = Line(3,4,0.7,0.5);
    
	basic.Setxcord(2);
	basic.Setycord(3);
	basic.SetSlope(1);
	
	cout<<basic.Getxcord()<<endl;
	cout<<basic.Getycord()<<endl;
	cout<<basic.Getslope()<<endl;

    basic.PrintPointSlope();
	basic.PrintSlopeIntercept();
	basic.PrintStandard();
    
    (basic.GetPerpendicular()).PrintSlopeIntercept();	
	basic.Intersection(basic2);
 
return 0;
}
