//============================================================================
// Name        : queue.cpp
// Author      : abr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Q{
	int front,rear,max;
	string* job;
public:
Q(int n)
	{
	max=n;
	front=rear=0;
	job=new string[n+1];
	}
void add();
void dis();
string del();
bool isempty();
bool isfull();
};

void Q::dis(){
	if(isempty())
		cout<<"Queue is Empty\n";
	else{
	for(int i=front+1;i<=rear;i++)
		cout<<job[i]<<"\n";
	}

}


void Q::add(){
	string j;
	if(front!=0 && rear==max)
	{cout<<"Enter job\n";
	cin>>j;
		while(front!=0)
		{
		for(int i=front;i<=rear;i++)
			job[i]=job[i+1];
			rear--;
			front--;
		}
		job[++rear]=j;
	}
	else
		if(isfull())
			cout<<"Queue is full";
		else{
		     cout<<"Enter job\n";
			 cin>>j;
			job[++rear]=j;
		}
}

bool Q::isfull(){
	if(front==0&&rear==max)
		return true;
	else
		return false;
}
bool Q::isempty(){
	if(front==rear)

		return true;
	else
		return false;
}

string Q::del(){
	if(isempty())
		return "Queue is empty\n";
	else
		{front++;
		return "Deleted Successfully\n";

}}

int main() {

int n,choice;
char dec;

cout<<"Enter number of jobs\n";
cin>>n;
Q que(n);

do{
	cout<<"Enter operation:\n1. Adding job\n2. Removing Job\n3.Display Queue contents\n";
	cin>>choice;
	switch(choice){
	case 1:	que.add();
		break;
	case 2:cout<<que.del();
		break;
	case 3:que.dis();
		break;
	}
	cout<<"Do you want to continue?(y/n)\n";
	cin>>dec;
}while(dec=='y'||dec=='Y');

	return 0;
}
