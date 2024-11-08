using namespace std;

class DoubleContainer {
	
	public:
			
		
		DoubleContainer();
                DoubleContainer(double* contentp, int len);
                DoubleContainer(const DoubleContainer& con);
                
                ~DoubleContainer();
		
                int getLength();
                double* getContent();
                void Add(double value);
                double Remove();
                void Clear();
                void Grow();
                
                friend ostream& operator<<(ostream& output, const DoubleContainer& dc);
                DoubleContainer operator=(const DoubleContainer& dc);
                
                friend DoubleContainer operator+(DoubleContainer& dc1, const DoubleContainer& dc2);
                
                friend DoubleContainer operator-(DoubleContainer& dc1, const DoubleContainer& dc2);
                friend DoubleContainer operator-(const DoubleContainer& dc1);  // unary operator-, negate overload
                
                friend DoubleContainer operator*(double d, const DoubleContainer& dc2);
                friend DoubleContainer operator*(DoubleContainer& dc1, const double d);
                friend double operator*(DoubleContainer& dc1, const DoubleContainer& dc2);              
                
	private:
                int currentSize;
                int maxSize;
                double* content;
	
};

