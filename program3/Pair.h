

#include <iostream>
using namespace std;
//
class Pair {
		public:
			Pair();
			Pair(double x, double y);
			Pair(double x);
			
			
			//getter 
			double Getx();
			double Gety();
			
			void Setx(double x);
			void Sety(double y);
		
		
		
		friend ostream& operator<<(ostream& output, const Pair& p);
                
                Pair operator+(Pair other);
				Pair operator-(Pair other);
                
                friend Pair operator*(double scalar, const Pair& other);
                Pair operator*(double other); // for Pair * double
                double operator*(Pair other);
		
                bool operator==(Pair other);
		
		private:
			double x;
			double y;
	
		
	
};