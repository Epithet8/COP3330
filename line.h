#include<iostream>

using namespace std;


class Line{
    
   //methods are public members are private
   public:
        Line();
        Line(double y,double riserun);
        Line(double x,double y,double riserun);
        Line(double rise,double run,double x,double y);

        void PrintPointSlope();
		void PrintSlopeIntercept();
		void PrintStandard();
		void Intersection(Line Line);
		
		//setters
		void Setxcord(double x);
        void Setycord(double y);
        void SetSlope(double s);		
		
		
		
		
		//end setters
	    double Getxcord();
        double Getycord();
		double Getslope();

        
 
		Line GetPerpendicular();
	

    private:
        double slope;
        double xcord;
        double ycord;

};
