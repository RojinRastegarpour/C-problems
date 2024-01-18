#include <iostream>
#include <array>
using namespace std;
class Matrix
{
	private:
		double M[2][2];
	public:
	
	    Matrix(double a ,double b ,double c ,double d)        //constructor	
	    {   
	        M[0][0] = a;
		    M[0][1] = b;
			M[1][0] = c;
		    M[1][1] = d; 
		}
		
		Matrix(double m[4])   //constructor	
		{   int c=0;
			for(int i=0 ; i<2 ; i++)
			  for(int j=0 ; j<2 ; j++)
			  {
			  	M[i][j] = m[c]; 
			  	c++;
			  }
		}
			Matrix()   //constructor	
		{  
			for(int i=0 ; i<2 ; i++)
			  for(int j=0 ; j<2 ; j++)
			  {
			  	M[i][j] = 0; 
			  	
			  }
		}
		~Matrix()
		{
		}
		void printMatrix()
		{
		     
			    for(int j=0 ; j<2 ; j++)
			   {
			  	 cout <<"[" << M[0][j]<< "]"  ; 
			  	 
			   }
			   cout<< endl;
			    for(int j=0 ; j<2 ; j++)
			   {
			  	 cout <<"[" << M[1][j]<< "]"  ; 
			  	
			    }
		
		}
		Matrix transpose()
		{
			Matrix a;
			for(int i=0 ; i<2 ; i++)
			  for(int j=0 ; j<2 ; j++)
			  {
			  	a.M[i][j] = M[j][i]; 
			  	
			  }
			  return a;
		}
		
		// operator overloading
		Matrix operator*(double d)
	   {
		   Matrix result;
	       for(int i=0;i<2;i++)
			 for(int j=0;j<2;j++)
			 {
				result.M[i][j] = d * M[i][j] ;
			 }         
		   return result;
	   }
       	Matrix operator*(Matrix& rightMatrix)
	   {
		   Matrix result;
	       result.M[0][0]= M[0][0] *  rightMatrix.M[0][0] + M[0][1] *  rightMatrix.M[1][0] ;          
	       result.M[0][1]= M[0][0] *  rightMatrix.M[0][1] + M[0][1] *  rightMatrix.M[1][1] ;       
	       result.M[1][0]= M[1][0] *  rightMatrix.M[0][0] + M[1][1] *  rightMatrix.M[1][0] ;       
	       result.M[1][1]= M[1][0] *  rightMatrix.M[0][1] + M[1][1] *  rightMatrix.M[1][1] ; 
	       return result ;
	   }
	     Matrix operator+(Matrix& rightMatrix)
		{
			Matrix result;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
				{
					result.M[i][j] = M[i][j] + rightMatrix.M[i][j];
				}
			return result;
		}
	array<double , 2> operator[](int i)
	{ 
	    
		array<double , 2> a1{M[0][0] , M[0][1]} , a2{M[1][0] , M[1][1]};
		switch(i)
		{
		    case 0: return a1 ; break;
		    case 1: return a2 ; break;
		}
		
	}
        friend Matrix operator*(double d, const Matrix& rightMatrix);
        friend ostream & operator<<(ostream & os, const Matrix & rightMatrix);
       
};
class Vector
{
    
	protected:
	   double x ;
	   double y ;
	public:
		
	   void printVector()
	   {
	   	 cout<< '(' << x << ',' << y <<')' ; 
	   }
	   Vector operator*(double d)
	{
		Vector result;
		result.x = x * d;
		result.y = y * d;
		return result;
	}
	double operator[](unsigned int i)
	{
		switch(i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		default:
			return 0;
		}
	}
		 Vector operator+(Vector& rightVector)
		{
			Vector result;
			result.x = x +rightVector.x;
			result.y = y +rightVector.y;
			return result;
		}
		
	   
	   	friend Vector operator*(double d, const Vector& rightVector);	
	   	friend ostream & operator<<(ostream & os, const Vector & rightVector);
	   	//friend Vector operator*(Vector & leftVector , Matrix & rightMatrix);
};
class Vector_Horizontal : public Vector
{
	
	public:	
	     Vector_Horizontal(double xComponent)    //constructor	
	     {
	         x=xComponent;
	         y=0;
		 }
		  Vector_Horizontal()     //constructor	
	     {
	         x=1;
	         y=0;
		 }
	    
	    ~Vector_Horizontal() //destructor	
	    {
		} 
		
};

class Vector_Vertical : public Vector
{
	
	public:	
	     Vector_Vertical(double yComponent)    //constructor	
	     {
	         x=0;
	         y=yComponent;
		 }
		  Vector_Vertical()       //constructor	
	     {
	         x=0;
	         y=1;
	     } 
	    
          ~Vector_Vertical()    //destructor
	    {
		}    
};
 ostream & operator<<(ostream & os, const Matrix & rightMatrix)
{
	os << '[' << rightMatrix.M[0][0] << ']' <<'[' << rightMatrix.M[0][1]<< ']' << endl << '[' << rightMatrix.M[1][0] << ']' <<'[' << rightMatrix.M[1][1] <<']'<< endl;
   	return os;
}
  ostream & operator<<(ostream & os, const Vector & rightVector)
  {
	os << '(' << rightVector.x << ',' << rightVector.y << ')';
	return os;
  }
Vector operator*(double d, const Vector& rightVector)
{
	
	Vector result;
	result.x = d * rightVector.x;
	result.y = d * rightVector.y;
	return result;
}

Matrix operator*(double d, const Matrix& rightMatrix)
{	
	Matrix result;
    for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			result.M[i][j] = d * rightMatrix.M[i][j];
		}
		return result;
}

int main()
{ 
  Vector_Horizontal v1(3);	
  Vector_Vertical v2(6) ;
  
    double a[4]={11,12,13,14};
    Matrix m1(a) , m2(1,2,3,4) , m3(1,2,-2,-1) , m4 ;
    cout << m1[1][1]<<  endl;
    cout<< "Matrix 1"<<endl<< m1<<endl;
    cout<< "Matrix 2" <<endl;
    m2.printMatrix() ; cout<<endl;
    cout<<endl<< "Matrix 3"<<endl<< m3<<endl;
    m4 = m2.transpose() ; 
    cout<< "transposed Matrix 2"<<endl<< m4<<endl;
    m4 = m2 + m3 ;
    cout<< "Matrix 2 + Matrix 3"<<endl<< m4 <<endl;
    m4= m2 * 5;
    cout<< "Matrix 2 * 5 "<<endl<< m4 <<endl;
    m4= 7 * m2 ;
    cout<< "7 * Matrix 2 "<<endl<< m4 <<endl;
    m4= m2 * m3;
    cout<< " Matrix 2 * Matrix 3 "<<endl<< m4 <<endl;
    cout<< "Horizontal Vector      : " ; 
    v1.printVector(); cout <<endl;
    cout<< "Vertical Vector        : "  << v2  << endl;
    cout<< "Vertical Vector * 3    : "  << v2*3  << endl;
    cout<< "5 * Horizontal Vector  : "  << 5 * v1  << endl;
    cout<< "Vertical Vector + Horizontal Vector  : "  << v2 + v1  << endl;
   cout<< "[ ] overloading : "<<endl<<"                  " <<v1[0] <<endl<<"                  "<< v2[1] ;
  return 0;	
}
/* baraye khubi va badi 2 tarahi transpose mitavan goft : agar taghirat roye matrix asli eijad shavad , matrix avalie ra az dast midahim
   va dar soorat niaz be oon matrix , nadarimesh !
   vali agar transpose matrix dar matrix digari zakhire shavad in moshkel vojood nakhahad dasht.
   vali ba eijad matrix jadid hafeze bishtari niaz ast . */
   

