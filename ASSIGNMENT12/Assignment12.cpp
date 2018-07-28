//============================================================================
// Name        : Sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class student
{
    public:
	int rno;
	float mks;

	void get();
	void display();
	friend void bubsort(student * s,int);
	friend void selsort(student * s,int);
	};

void student::get()
{

	cout<<"\n Enter rollno"<<endl;
	cin>>rno;
	cout<<"\n Enter marks"<<endl;
	cin>>mks;

}

void bubsort(student * s,int n)
{
	student temp;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
          if(s[j].mks>s[j+1].mks)
          {
        	 temp=s[j];
        	 s[j]=s[j+1];
        	 s[j+1]=temp;
          }
		}
	}
}

void selsort(student *s,int n)
{   student temp1;
	for(int i=0;i<n;i++)
	{	int min=i;
	for(int j=i;j<n;j++)
		if(s[min].mks>s[j].mks)
		min=j;
	temp1=s[i];
	s[i]=s[min];
	s[min]=temp1;	

	}

}

void student::display()
{

		cout<<rno<<"\t"<<mks<<"\n";

}
int main() {
	student s[50];
	int i,n;
	char type;
	cout<<"\n Enter number of students";  //getdata
	cin>>n;
	for(i=0;i<n;i++)
	{
	    s[i].get();
	}
	cout<<"Enter the type of sorting you want(bubble-b/selection-s)"<<endl;
	cin>>type;
	switch(type)
	{
	case 'b':  bubsort(s,n);
				cout<<"The sorted marks are"<<endl;
				for(i=0;i<n;i++)
				              {
				            	  s[i].display();
				              }
				cout<<"The top 5 are"<<endl;
              for(i=0;i<5;i++)
              {
            	  s[i].display();
              }
              break;
	case 's':  selsort(s,n);
				cout<<"The sorted marks are"<<endl;
					for(i=0;i<n;i++)
					              {
					            	  s[i].display();
					              }
				cout<<"The top 5 are"<<endl;
    			for(i=(n-1);i>=(n-5);i--)
    			{
    				s[i].display();
    			}
    			break;

	}
	return 0;

}
