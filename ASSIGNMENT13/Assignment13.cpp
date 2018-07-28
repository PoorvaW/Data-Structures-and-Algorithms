#include <iostream>
using namespace std;

class student
{
    public:
	char name[15];
	int rno;
	float mks;

	void get();
	void display();
	friend void qsort(student *s,int,int);
	friend int partion(student *s,int,int);
	};

void student::get()                       //getdata
{
	cout<<"\n Enter rollno and marks"<<endl;
	cin>>rno>>mks;
}

void student::display()
{

		cout<<rno<<"\t"<<mks<<"\n";

}


int partion(student *a,int l,int u){
int i=l;
int j=u+1;
float v=a[l].mks;

do{
do{i++;}while(a[i].mks<v&&i<=u);
do{j--;}while(v<a[j].mks);
if(i<j){
student temp;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l].mks=a[j].mks;
a[j].mks=v;
return j;
}

void qsort(student *a,int l,int u){
int j;
if(l<u){
	j=partion(a,l,u);
	qsort(a,l,j-1);
	qsort(a,j+1,u);
}}



int main() {
	int n;
	cout<<"\n Enter number of students";  //getdata
	cin>>n;
	student *s=new student[n];
	for(int i=0;i<n;i++)
	{
	    s[i].get();
	}
	qsort(s,0,n-1);
	cout<<"The top 5 are"<<endl;
              for(int i=(n-1);i>=(n-5);i--)
    			{
    				s[i].display();
    			}


	return 0;

}
