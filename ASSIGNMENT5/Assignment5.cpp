
#include<iostream>
using namespace std;


class node{
		int data;
		node *prev;
		node *next;
public:
		friend class binary;
};

class binary
{	public :
	int num,temp;
	node *first;

	binary(){
		num=0;
		first=NULL;
		temp=0;
	}
	void get();
	void ones();
	void twos();
	void add(binary l);
	void convert(int num);
	void display();
};
void binary::get(){
	cout<<"Enter the Number(In Decimal)"<<endl;
	cin>>num;
	temp=num;
	do{
		convert(num%2);
		num=num/2;
	}while(num!=0);
}
void binary::add(binary l){
	int sum;
	sum=temp+l.temp;
	
	do{
			convert(sum%2);
			sum=sum/2;
		}while(sum!=0);
}
void binary::ones(){
	node *temp;
	temp=first;
	while(temp!=NULL)
	{
		if(temp->data==1)
			temp->data=0;
		else
			temp->data=1;

		temp=temp->next;
	}
}

void binary::display(){
	node *temp;
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp!=NULL)
	{cout<<temp->data<<endl;
	temp=temp->prev;
	}
}
void binary::twos(){
		int ans=1;
		node *temp;
		temp=first;
		while(temp!=NULL)
		{
			ans=ans+temp->data;
			if(ans==1)
				{temp->data=ans;
				ans=0;
				}
			else
				if(ans==2)
				{ans=1;
				temp->data=0;
				}

		temp=temp->next;
		}




}


void binary::convert(int n){
	node *temp=first;
	if(temp==NULL)
	{
		node *obj=new node();
		temp=obj;
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=n;
		first=temp;
	}
	else
	{
		while(temp->next!=NULL)
		temp=temp->next;
	node *obj=new node();
	temp->next=obj;
	temp->next->next=NULL;
	temp->next->prev=temp;
	temp->next->data=n;
	}
}


int main(){
	binary b1,b2;
	int i;
	char dec;
	do{
		cout<<"Enter your choice"<<endl;
		cout<<"1.Perform One's Complement"<<endl;
		cout<<"2.Perform Two's Complement"<<endl;
		cout<<"3.Add two Numbers"<<endl;
		cin>>i;

		switch(i){
		case 1:         b1.get();
						b1.ones();
						b1.display();
					break;
		case 2: 		b1.get();
						b1.ones();
						b1.twos();
						b1.display();
					break;
		case 3:
						cout<<"Number One"<<endl;
						b1.get();
						cout<<"Number Two"<<endl;
						b2.get();
						b1.first=NULL;
						b2.first=NULL;
						b1.add(b2);
						b1.display();
					break;

		}
				b1.first=NULL;
				b2.first=NULL;
		cout<<"Do you want to continue(y\\n)"<<endl;
		cin>>dec;

	}while(dec=='y');

}
