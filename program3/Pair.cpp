#include "Pair.h"
#include <cstdlib>
#include <valarray>

Pair::Pair(){
	this->x = 0;
	this->y = 0;
	
}

Pair::Pair(double x, double y){
	this->x = x;
	this->y = y;
	
}

Pair::Pair(double x){
	this->x = x;
}
//
double Pair::Getx(){
    return x;
}

double Pair::Gety(){
    return y;
}

void Pair::Setx(double x){
    this->x = x;
}

void Pair::Sety(double y){
    this->y = y;
}

ostream& operator<<(ostream& output, const Pair& p) {
    output<<"("<<p.x<<","<<p.y<<")";
}

Pair Pair::operator+(Pair other){
			
			Pair temp;
			temp.x = this->x + other.x;
			temp.y = this->y + other.y;
			
			return temp;
		}
		
Pair Pair::operator-(Pair other){
			Pair temp;
			temp.x = this->x - other.x;
	        temp.y = this->y - other.y;
			
			return temp;
	
	
}		
		
		

Pair operator*(double scalar, const Pair& other){			
			Pair temp;
                        temp.x = scalar * other.x;
                        temp.y = scalar * other.y;
			return temp;
		}

Pair Pair::operator*(double other){			
			Pair temp;
                        temp.x = this->x * other;
                        temp.y = this->y * other;
			return temp;
		}
double Pair::operator*(Pair other){			
			return this->x * other.x + this->y * other.y;
		}

bool Pair::operator==(Pair other){
			
                        if(this->x == other.x && this->y == other.y){
                            return true;
                        }else{
                            return false;
                        }
		}