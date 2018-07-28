//============================================================================
// Name        : Matrix.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : matrix.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int A[30][30],B[30][30],mult[30][30],n;
public:
	void read()
	{	cout<<"Enter degree \n";
		cin>>n;
		cout << "Input the matrix A:\n";
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					cin>>A[i][j];
	}
	void upper()
	{	int count=0;
			for(int i=1;i<n;i++){
					for(int j=0;j<i;j++)
					if(A[i][j]==0)
						count++;
						}
	
			if(count>=(n*n-n)/2)
				cout<<"Matrix A is upper triangular matrix\n";
					else cout<<"Matrix A is not an upper triangular matrix\n";
			
	}
	void transpose()
	{
		cout<<"\nTranspose matrix";
			for(int i=0;i<n;i++){
					cout<<"\n";
				for(int j=0;j<n;j++)	
					cout<<A[j][i]<<"\t";
						}
	}
	void operations()
	{

		cout<<"\nInput the matrix to be added/subtracted/multiplied:\n";
		for(int i=0;i<n;i++)
						for(int j=0;j<n;j++)
						{
							cin>>B[i][j];
						}
		cout<<"\n Matrix addition:";
		for(int i=0;i<n;i++)
		{  cout<<"\n";
			for(int j=0;j<n;j++)
			    {
					cout<<A[i][j]+B[i][j]<<"\t";
				}
		}
		cout<<"\n Matrix Subtraction:";
			for(int i=0;i<n;i++)
		{  cout<<"\n";
			for(int j=0;j<n;j++)
			    {
					cout<<A[i][j]-B[i][j]<<"\t";
				}
		}
			cout<<"\n Matrix Multiplication:";
					for(int i=0;i<n;i++)
					{
						cout<<"\n";
						for(int j=0;j<n;j++)
						    {mult[i][j]=0;
							 for(int k = 0; k < n; ++k)
							            {
							                mult[i][j] += A[i][k] * B[k][i];
							            }

								cout<<mult[i][j]<<"\t";
							}
					}
	}
	bool saddle()
	{
		for(int i=0;i<n;i++)
		{
			int min=A[i][0];
			int col=0;
			for(int j=0;j<n;j++)
				if(min>A[i][j])
					{
					min=A[i][j];
					col=j;
					}
			int k;
			for(k=0;k<n;k++)
				if(min<A[k][col])
					break;
			if(k==n){
				cout<<"\nValue of saddle point: "<<min;
				return true;
		}
		return false;
	}
}
};





int main()
{

matrix m1;
	m1.read();
	m1.upper();
	m1.transpose();
	m1.operations();
	if(m1.saddle()==false)
		cout<<"No Saddle Point";
    return 0;
}
