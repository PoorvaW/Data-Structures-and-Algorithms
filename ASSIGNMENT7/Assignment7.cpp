//============================================================================
// Name        : parenthesis.cpp
// Author      : abr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <string.h>
using namespace std;

class stack{
	int top;
	int max;
	char exp[30];
	public:
	void push(char ele);
	bool isempty();
	void pop();
	stack(int n){
		top=-1;
		max=n;
	}
};

void stack::push(char ele){

	top++;
	exp[top]=ele;
}

void stack::pop(){
	if(top!=-1)
		top--;
	else
		top=max;
}

bool stack::isempty(){
	if(top==-1)
		return true;
	else
		return false;

}


int main() {

	int n;
	char exps[50];

cout<<"Enter Expression"<<endl;
		cin>>exps;
n=strlen(exps);
stack s1(n),s2(n),s3(n);

for(int i=0;i<n;i++)
{
switch(exps[i])
{
case '(':	s1.push(exps[i]);

		break;
case '{':	s2.push(exps[i]);

		break;
case '[':	s3.push(exps[i]);

		break;
case ')':	s1.pop();

		break;
case '}':	s2.pop();

		break;
case ']':	s3.pop();
;
		break;
}

}
if(s1.isempty()&&s2.isempty()&&s3.isempty())
	cout<<"Valid Expression\n";
else
	cout<<"Invalid Expression\n";

return 0;
}
