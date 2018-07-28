//============================================================================
// Name        : dequeue.cpp
// Author      : abr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class dque{
	int front,rear,max;
	int* array;

public:
	dque(int n){
		max=n;
		front=rear=0;
		array=new int[n];
	}

	void addfront();
	void addrear();
	void delrear();
	void delfront();
	void dis();
	bool isempty();
	bool isfull();

};
bool dque::isempty(){
	if(rear==front)
		return true;
	else
		return false;
}
bool dque::isfull(){
	if(front==0&&rear==max)
			return true;
		else
			return false;
}
void dque::addfront(){
	int j;
if(isfull())
	cout<<"Queue is Full";
else
	if(front==0 && rear!=max)
	{cout<<"Enter Element to be added\n";
	cin>>j;
	while(rear!=max){
	for(int i=rear;i>front;i--)
	array[i]=array[i-1];
	rear++;
	front++;
	}
	array[front--]=j;
	}
	else{
		cout<<"Enter Element to be added\n";
				cin>>j;
		array[front--]=j;
	}
}
void dque::addrear(){
	int j;
		if(front!=0 && rear==max)
		{cout<<"Enter Element to be added\n";
		cin>>j;
			while(front!=0)
			{
			for(int i=front;i<=rear;i++)
				array[i]=array[i+1];
				rear--;
				front--;
			}
			array[++rear]=j;
		}
		else
			if(isfull())
				cout<<"Queue is full";
			else{
			     cout<<"Enter element to be added\n";
				 cin>>j;
				array[++rear]=j;
			}
}
void dque::delrear(){
if(isempty())
cout<<"Queue is Empty\n";
else
{
rear--;
cout<<"Deleted Successfully";
}
}
void dque::delfront(){
	if(isempty())
			cout<<"Queue is empty\n";
		else
			{front++;
			cout<<"Deleted Successfully\n";
			}
}
void dque::dis(){
	if(isempty())
			cout<<"Queue is Empty\n";
		else{
			for(int i=front+1;i<=rear;i++)
			cout<<array[i]<<"\n";
		}
}


int main() {

	int n;
	int choice;
	char dec;

	cout<<"Enter number of elements\n";
	cin>>n;
	dque q(n);

	do{
		cout<<"Enter operation:\n1. Add element to rear\n2. Delete element from front\n3.Display contents\n4. Add element to Front\n5.Delete element from Rear\n";
		cin>>choice;
		switch(choice){
		case 1:	q.addrear();
			break;
		case 2:q.delfront();
			break;
		case 3:q.dis();
			break;
		case 4: q.addfront();
			break;
		case 5: q.delrear();
			break;
		}
		cout<<"Do you want to continue?(y/n)\n";
		cin>>dec;
	}while(dec=='y'||dec=='Y');

		return 0;
}
