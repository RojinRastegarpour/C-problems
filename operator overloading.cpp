#include <iostream>
using namespace std;

class Fraction
{
	private:
		int top;
		int bottom;
	public:
	    Fraction(int t , int b)	: top{t} , bottom{b}         //constructor
	    {
		}
		Fraction()	: top{1} , bottom{1}         //constructor
	    {
		}
    	Fraction operator+(const Fraction& rightFraction)
	    {
		   Fraction result;
		   result.top = top * rightFraction.bottom + bottom * rightFraction.top ;
		   result.bottom = bottom * rightFraction.bottom;
		   return result;
    	}
    	
    	Fraction operator*(double d)
	    {
		   Fraction result;
		   result.top = top * d;
		   result.bottom = bottom;
		   return result;
    	}
    	
    	Fraction operator*(const Fraction& rightFraction)
	    {
		   Fraction result;
		   result.top = top * rightFraction.top;
		   result.bottom = bottom * rightFraction.bottom;
		   return result;
    	} 
    	
    	bool operator<(const Fraction& rightFraction)
    	{
    		if(top * rightFraction.bottom < bottom * rightFraction.top){
    			return true;
			}
			return false;
		}
		
		bool operator>(const Fraction& rightFraction)
    	{
    		if(top * rightFraction.bottom > bottom * rightFraction.top){
    			return true;
			}
			return false;
		}
		
		bool operator<=(const Fraction& rightFraction)
    	{
    		if(top * rightFraction.bottom <= bottom * rightFraction.top){
    			return true;
			}
			return false;
		}
		
		bool operator>=(const Fraction& rightFraction)
    	{
    		if(top * rightFraction.bottom >= bottom * rightFraction.top){
    			return true;
			}
			return false;
		}
		
		bool operator==(const Fraction& rightFraction)
    	{
    		if(top * rightFraction.bottom == bottom * rightFraction.top){
    			return true;
			}
			return false;
		}
        friend Fraction operator*(double d, const Fraction& rightFraction);
        friend ostream & operator<<(ostream & os, const Fraction & rightFraction);
};
Fraction operator*(double d, const Fraction& rightFraction)
{
	Fraction result;
	result.top = d * rightFraction.top;
	result.bottom = rightFraction.bottom ;
	return result;
}
ostream & operator<<(ostream & os, const Fraction & rightFraction)
{
	os <<  rightFraction.top << '/' << rightFraction.bottom ;
	return os;
}
int main()
{
	Fraction a(5,2) , b(7,3) , c(1,5) , d(1,5);
	
	cout<< " a*b = " << a*b << endl ;
	cout<< " a+b = " << a+b << endl ;
	cout<< " a*5 = " << a*5 << endl ;
	cout<< " 6*b = " << 6*b << endl ;
	if(a>b)
	 cout<< " a>b " << endl  ;
	if(c<a)
	 cout<< " c<a " << endl  ;
	if(c==d)
	 cout<< " c==d " << endl ;
	

	return 0;
}
