//============================================================================
// Name        : Search.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Student
{
		int rollno;
		string name;
public:
		void getdata();
		friend void linearsearch(Student *s,int,int);
		friend void sentinelsearch(Student *s,int,int);
		friend void binarysearch(Student *s,int,int);
		friend int fibonaccisearch(Student *s,int,int);
		friend int min(int a,int b);

};
int min(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}

void linearsearch(Student *s,int n,int ele)
{
	int i;

		for(i=0;i<n&&s[i].rollno!=ele;i++);
		if(i==n)
			cout<<"The student did not attend"<<endl;
		else
			cout<<"The student attended"<<endl;
}

void sentinelsearch(Student *s,int n,int ele)
{
	int i;
	s[n].rollno=ele;

			for(i=0;s[i].rollno!=ele;i++);
			if(i<n)
				cout<<"The student attended"<<endl;
			else
				cout<<"The student did not attend"<<endl;
}

void binarysearch(Student *s,int n,int ele)
{
	Student temp;
			for(int j=0;j<n;j++)
			{
	          if(s[j].rollno>s[j+1].rollno)
	          {
	        	 temp=s[j];
	        	 s[j]=s[j+1];
	        	 s[j+1]=temp;
	          }
			}

	int first=0;
	int last=n-1;
		while(first<=last)
		{
			int middle=(first+last)/2;
				if(s[middle].rollno < ele)
					first=middle+1;
				else if(s[middle].rollno==ele)
					{cout<<"The student attended"<<endl;
					break;}
				else
					last=middle-1;
		}
	if(first>last)
		cout<<"The student did not attend"<<endl;

}

int fibonaccisearch(Student *s,int n,int ele)
{
	Student temp;
			for(int j=0;j<n;j++)
			{
	          if(s[j].rollno>s[j+1].rollno)
	          {
	        	 temp=s[j];
	        	 s[j]=s[j+1];
	        	 s[j+1]=temp;
	          }
			}
int f=1,f1=1,f2=0;

while(f<n){
	f2=f1;
	f1=f;
	f=f1+f2;
}
int x=0;
while(f>0){
	int i=min(f1+x,n);
	if(ele==s[i].rollno)
		return f1;

	if(ele<s[i].rollno){
		if(f2==0)
			return -1;
		f2=f1-f2;
		f=f1;
		f1=f2;
	}
	else{
		if(f1==1)
			return -1;
		f=f-f1;
		f1=f1-f2;
		f2=f-f1;
		x=i;

	}
}
return -1;
}



void Student:: getdata()
{
	cout<<"Enter Roll No. and Name"<<endl;
	cin>>rollno>>name;
}


int main() {
			int n,ele,check;
			Student s[20],s1;
			char c,d;

			cout<<"Enter number of elements";
			cin>>n;

			for(int i=0;i<n;i++)
				s[i].getdata();


			do{
				cout<<"Enter type of search"<<endl;
				cout<<"l-linear\n s-sentinel\n b-binary\n f-fibonacci\n"<<endl;
				cin>>c;

				cout<<"Enter roll no of student you want to check for"<<endl;
				cin>>ele;
			switch (c)
			{
			case 'l' :linearsearch(s,n,ele);
						break;
			case 's' :sentinelsearch(s,n,ele);
						break;
			case 'b' :binarysearch(s,n,ele);
						break;
			case 'f' :check=fibonaccisearch(s,n,ele);
			if(check==-1)
				cout<<"The student did not attend\n";
			else
				cout<<"The student attended\n";
						break;
			}
			cout<<"Do you want to Search another roll no(y\n)"<<endl;
			cin>>d;
			}
			while(d=='y'||d=='Y');


	return 0;
}
