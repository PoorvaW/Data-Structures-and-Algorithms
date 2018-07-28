//============================================================================
// Name        : intopost.cpp
// Author      : abr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class stack{
	int top,max;
	char a[50];
public:
	stack(int n)
	{
		max=n;
		top=-1;
	}
char tops();
void push(char ele);
void pop();
int isp(char ele);
bool isempty(){
	if(top==0)
		return true;
	else
		return false;
}

		};
void stack::push(char ele){
	top++;
	a[top]=ele;
}
void stack::pop(){
	top--;
}

char stack::tops(){

	return a[top];

}

int stack::isp(char ele)
{
switch(ele)
{
case '+':
	return 2;
	break;

case '-':
	return 2;
	break;

case '*':
	return 3;
	break;

case '/':
	return 3;
	break;

case '#':
	return 1;
	break;

}
}

void eval(char* po,int n)
{int *a=new int[n];
int t=-1;
for(int i=0;i<n;i++)
{

if(po[i]=='+'||po[i]=='-'||po[i]=='*'||po[i]=='/')
{
	switch(po[i])
	{
	case '+': a[t-1]=a[t-1]+a[t];
				t--;
			break;
	case '-': a[t-1]=a[t-1]-a[t];
				t--;
				break;
	case '*': a[t-1]=a[t-1]*a[t];
				t--;
				break;
	case '/': a[t-1]=a[t-1]/a[t];
				t--;
				break;
	}

}
else
{
	t++;
	a[t]=po[i]-48;
	
}


}
cout<<"\nAnswer is:"<<a[t];
}

int main() {
	int n;
	char exp[60];

	cout<<"Enter expression to be evaluated (in infix form)\n";
	cin>>exp;
	n=strlen(exp);
	exp[n]='#';
char *post=new char[n+1];
post[n]='#';

	stack s(n);
    s.push('#');
	int i=0,j=0;
	while(exp[i]!='#')
	{
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
		{
			while(s.isp(s.tops())>=s.isp(exp[i]))
			{
				cout<<s.tops();
				post[j++]=s.tops();
				s.pop();
			}
			s.push(exp[i]);
		}
		else{
			cout<<exp[i];
			post[j++]=exp[i];
		}
	i++;
	}

	while(!(s.isempty()))
	{
		cout<<s.tops();
		post[j++]=s.tops();
		s.pop();
	}
	eval(post,n);
	return 0;
}
