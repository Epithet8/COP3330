using namespace std;

class DoubleContainer {
	
	public:
			
		
		DoubleContainer();
                DoubleContainer(double* contentp, int len);
                DoubleContainer(DoubleContainer& con);
                
                ~DoubleContainer();
		
                int getLength();
                double* getContent();
                void Add(double value);
                double Remove();
                void Clear();
                void Grow();
                
                friend ostream& operator<<(ostream& output, DoubleContainer& dc);
                DoubleContainer operator=(DoubleContainer& dc);
                
                friend DoubleContainer operator+(DoubleContainer& dc1, DoubleContainer& dc2);
                
                friend DoubleContainer operator-(DoubleContainer& dc1, DoubleContainer& dc2);
                friend DoubleContainer operator-(DoubleContainer& dc1);  // unary operator-, negate overload
                
                friend DoubleContainer operator*(double d, DoubleContainer& dc2);
                friend DoubleContainer operator*(DoubleContainer& dc1, double d);
                friend double operator*(DoubleContainer& dc1, DoubleContainer& dc2);              
                
	private:
                int currentSize;
                int maxSize;
                double* content;
	
};

