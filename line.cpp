//hello

#include "line.h"

Line::Line(){
    slope=1;
    xcord=0;
    ycord=0;

}

Line::Line(double y, double riserun){
    slope=riserun;
    xcord=0;
    ycord=y;
}

Line::Line(double x,double y,double riserun){
    xcord=x;
    ycord=y;
    slope=riserun;
}

Line::Line(double rise,double run,double x,double y){
    slope=rise/run;
    xcord=x;
    ycord=y;
}
void Line::PrintPointSlope(){
	cout<<"y -"<<ycord<<" = "<<slope<<"(x - "<<xcord<<")"<<endl;
}

void Line::PrintSlopeIntercept(){
	cout<<"y ="<<slope<<"x + "<<ycord-(slope*xcord)<<endl;
	
}


void Line::PrintStandard(){
	cout<<"a"<<xcord<<" + b"<<ycord<<" = c"<<endl;
}


void Line::Intersection(Line line){
	double x1 = xcord;
	double y1 = ycord;
	double intercept1 = ycord-(slope*xcord);
	
	double x2 = line.xcord;
	double y2 = line.ycord;
	double intercept2 = line.ycord-(line.slope*line.xcord);
//calculate and print out point of intersection 
   cout<<"x = "<<intercept2-intercept1<<"/"<<slope-line.slope<<endl;
   
	
}
		
		//setters
void Line::Setxcord(double x){
    xcord = x; 	
}

void Line::Setycord(double y){
	ycord =y;
}
void Line::SetSlope(double s){
	slope = s;
}		
		
		
		
		
		//end setters
double Line::Getxcord(){
	return xcord;
}
double Line::Getycord(){
	return ycord;
}
double Line::Getslope(){
	return slope;
}

        
 
Line Line::GetPerpendicular(){
	Line perpendicular = Line();
	//make sure to set the correct x and y cord
	perpendicular.SetSlope(-1.0/slope);
	perpendicular.Setxcord(3);
	perpendicular.Setycord(4);
	

	
	return perpendicular;	
} 
