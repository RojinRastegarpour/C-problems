#include <iostream>
using namespace std;

template<typename T, unsigned int row, unsigned int col>
class Matrix
{
	public:
     	T M[row][col];
		Matrix(T m[row*col])   //constructor	
		{   int c=0;
			for(unsigned int i=0 ; i<row ; i++)
			  for(unsigned int j=0 ; j<col ; j++)
			  {
			  	M[i][j] = m[c]; 
			  	c++;
			  }
		}
			Matrix()   //constructor	
		{  
			for(unsigned int i=0 ; i<row ; i++)
			  for(unsigned int j=0 ; j<col ; j++)
			  {
			  	M[i][j] = 0; 
			  	
			  }
		}
		~Matrix()
		{
		}
	
		void printMatrix()
		{
		     
			    
			for(unsigned int i=0 ; i<row ; i++)
			{
				for(unsigned int j=0 ; j<col ; j++)
			   {
			  	 cout <<"[" << M[i][j]<< "]"  ; 
			  	 
			   }
			   cout<< endl;
		    }
		 
		}
	
		// operator overloading
		Matrix<T,row,col> operator*(double d)
	   {
		   Matrix<T , row, col> result;
	       for(unsigned int i=0;i<row;i++)
			 for(unsigned int j=0;j<col;j++)
			 {
				result.M[i][j] = d * M[i][j] ;
			 }         
		   return result;
	   }

       	Matrix<T,row,col> operator*(Matrix<T,row,col>& rightMatrix)
	   {
	  
		    Matrix<T,row,col> result;
	      for(unsigned int i = 0; i <row; i++)
	      {
             for(unsigned int j = 0; j < col; j++)
             {
                for(unsigned int k = 0; k < col; k++)
                  result.M[i][j] += this->M[i][k] * rightMatrix.M[k][j];
             
             }
   
          }
	       return result ;
	   }
	     Matrix<T,row,col>  operator+( Matrix<T,row,col> & rightMatrix)
		{
			Matrix<T,row,col> result;
			for(unsigned int i=0;i<row;i++)
				for(unsigned int j=0;j<col;j++)
				{
					result.M[i][j] = this->M[i][j] + rightMatrix.M[i][j];
				}
			return result;
		}
		
		 Matrix<T,row,col>  operator-( Matrix<T,row,col> & rightMatrix)
		{
			Matrix<T,row,col> result;
			for(unsigned int i=0;i<row;i++)
				for(unsigned int j=0;j<col;j++)
				{
					result.M[i][j] = this->M[i][j] - rightMatrix.M[i][j];
				}
			return result;
		}
		
	   T& operator()(unsigned int i, unsigned int j)
	   {
	      return M[i][j];
	   }	
};

template<typename T, unsigned int row, unsigned int col> class Matrix;	
template<typename T, unsigned int row, unsigned int col>
ostream& operator<<(ostream& os, const Matrix<T,row,col> & rightMatrix)
{
		for(unsigned int i=0 ; i<row ; i++)
			{
				for(unsigned int j=0 ; j<col ; j++)
			   {
			  	 cout <<"[" <<rightMatrix.M[i][j]<< "]"  ; 
			  	 
			   }
			   cout<< endl;
			}
   	return os;
}
template<typename T, unsigned int row, unsigned int col>
Matrix<T,row,col> operator*(double d, const Matrix<T,row,col>& rightMatrix)
{	
	Matrix<T,row,col> result;
    for(unsigned int i=0;i<row;i++)
		for(unsigned int j=0;j<col;j++)
		{
			result.M[i][j] = d * rightMatrix.M[i][j];
		}
		return result;
}
template<typename T, unsigned int col>
using rowVec = Matrix<T,1,col>;

template<typename T, unsigned int row >
using colVec = Matrix<T,row,1>;

int main()
{ 
  int a[12] = {1,2,3,4,5,6,7,8,9,10,11,12}; 
  int b[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
  char c[6] = {65,66,67,68,69,70};
  double d[9] = {3,2,4,2,3,5,7,6,8};
  Matrix<int,4,3> m1(a); //  first constructor
  Matrix<int,4,3> m2;    //  second constructor
  Matrix<char,2,3> m3(c);
  Matrix<int,4,3> m4(b);
  Matrix<double,3,3> m5(d);
  Matrix<double,3,3> m6(d); 
  m1.printMatrix();
  cout<<endl;
  m2= m1 + m4;
  m2.printMatrix();
  cout<<endl;
  m3.printMatrix();
  cout<<endl;
  m4.printMatrix();
  m2=m1-m4;
  cout<<endl;
  cout<<m2;
  cout<<endl;
  m1 = 3*m2;
  cout<<m1;
  cout<<endl;
  m1 = m2*3;
  cout<<m1;
  cout<<endl;
  cout<<m1(2,1);
  cout<<endl<<endl;
  rowVec<int,3> v1;
  cout<<v1;
  colVec<int,3> v2(a);
  cout<<endl;
  cout<<v2;
  Matrix<double,3,3> m7 ;
  m7 = m5*m6;
  cout<<endl;
  cout<< m6;
  
  return 0;	
}

