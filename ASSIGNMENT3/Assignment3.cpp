
	#include <iostream>
	#include <math.h>
	using namespace std;

	int main()
	 {
	  int n,i,j,y,p1[10],p2[10],p3[10],p4[20],m;
	  cout<<"Enter degree of Polynomial:";
	  cin>>n;
	  cout<<"Enter Coefficients:";
	  for(i=0;i<=n;i++)
	{
		cin>>p1[i];

	}
	cout<<"Polynomial is:";
	for(i=0;i<=n;i++)
	{
		cout<<p1[i]<<"x^"<<(n-i)<<"+";
	}
	cout<<endl;
	cout<<"Enter a value of x:";
	cin>>y;
	int sum=0;
	for(i=0;i<=n;i++)
	{
	  sum=sum+(p1[i]*pow(y,(n-i)));
	}
	cout<<"Evaluated value is:"<<sum;

	cout<<"\nEnter degree of Polynomial to be added:";
	cin>>m;
	cout<<"\nEnter Coefficients:";
	for(i=0;i<=m;i++)
	{
		cin>>p2[i];

	}
	if(n==m)
	{
	for(i=0;i<=n;i++)
		p3[i]=p2[i]+p1[i];
	}
	else
		if(n>m)
		{for(i=n,j=m;j>=0,i>=(n-m);i--,j--)
				{p3[i]=p1[i]+p2[j];}

	for(i=(n-m-1);i>=0;i--)
	{
		p3[i]=p1[i];
	}
	cout<<"\nAddition is";
		for(i=0;i<=n;i++)
		{
	cout<<p3[i]<<"x^"<<(n-i)<<"+";
		}
		}
		else
		{for(i=n,j=m;i>=0,j>=(m-n);i--,j--)
						{p3[j]=p1[i]+p2[j];}

			for(j=(m-n-1);j>=0;j--)
			{
				p3[j]=p2[j];
			}
			cout<<"\nAddition is";
				for(j=0;j<=m;j++)
				{
			cout<<p3[j]<<"x^"<<(m-j)<<"+";
				}
		}
	for(i=0;i<=(m+n);i++)
	{
		p4[i]=0;
	}

	cout<<"\nMultiplication is"<<endl;
	for(i=0;i<=n;i++)
	{
	for(j=0;j<=m;j++)
	{
	p4[(i+j)]=p4[(i+j)]+(p1[i]*p2[j]);

	}
	}
	for(i=0;i<=(m+n);i++)
	{
	cout<<p4[i]<<"x^"<<(m+n-i)<<"+";
	}
	return 0;
	}
