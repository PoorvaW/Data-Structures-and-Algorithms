//============================================================================
// Name        : linkedlist.cpp
// Author      : Poorva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Pinnacle {
	int prn;
	string name;
	Pinnacle *next;

public:
	void get() {
		cout << "Enter prn and Name" << endl;
		cin >> prn >> name;
	}
	friend class linkedlist;
};

class linkedlist {
public:
	Pinnacle *first;

	linkedlist() {
		first = NULL;

	}
	void create();
	void addpresident();
	void addsecretary();
	void addmember();
	void deletemember();
	void display();
	void reverse();
	void rev(Pinnacle *);
	void concat();
	void count();
	void sort();
};

void linkedlist::addpresident() {
	Pinnacle *obj = new Pinnacle[sizeof(int) + sizeof(string)];
	obj->get();
	obj->next = NULL;
	first = obj;
}
void linkedlist::addsecretary() {
	Pinnacle *obj = new Pinnacle[sizeof(int) + sizeof(string)];
	Pinnacle *temp;
	temp = first;
	obj->get();
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = obj;
	temp->next->next = NULL;

}
void linkedlist::addmember() {
	int t;
	Pinnacle *obj = new Pinnacle[sizeof(int) + sizeof(string)];
	Pinnacle *temp;
	temp = first;

	cout << "Enter prn after which you want to add" << endl;
	cin >> t;
	obj->get();
	while (temp->prn != t) {
		temp = temp->next;
	}
	obj->next = temp->next;
	temp->next = obj;

}

void linkedlist::deletemember() {
	int t;
	Pinnacle *temp;
	temp = first;

	cout << "Enter prn of the member you want to delete" << endl;
	cin >> t;
	while (temp->next->prn != t) {
		temp = temp->next;
	}
	temp->next = temp->next->next;

}

void linkedlist::display() {
	Pinnacle *temp;
	temp = first;
	while (temp->next != NULL) {
		cout << "Prn: " << temp->prn << "\t" << "Name: " << temp->name << endl;
		temp = temp->next;
	}
	cout << "Prn: " << temp->prn << "\t" << "Name: " << temp->name << endl;
}

void linkedlist::reverse() {
	Pinnacle *temp = first;
	rev(temp);

}

void linkedlist::rev(Pinnacle *temp) {
	if (temp->next != NULL) {
		rev(temp->next);
	}
	cout << "Prn: " << temp->prn << "\t" << "Name: " << temp->name << endl;
}

void linkedlist::count() {
	int count = 0;
	Pinnacle *temp;
	temp = first;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	cout << "Number of members is " << count << endl;
}

void linkedlist::concat() {
	char dec;
	int i;
	linkedlist l1;
	cout << "Operations for List 2" << endl;

	do {
		cout << "What operation you want to perform?" << endl;
		cout << "1.Add President" << endl;
		cout << "2.Add Secretary" << endl;
		cout << "3.Add Member" << endl;
		cout << "4.Delete Member" << endl;
		cout << "5.Display All" << endl;
		cout << "6.Reverse the list" << endl;
		cin >> i;

		switch (i) {
		case 1:
			l1.addpresident();
			break;
		case 2:
			l1.addsecretary();
			break;
		case 3:
			l1.addmember();
			break;
		case 4:
			l1.deletemember();
			break;
		case 5:
			l1.display();
			break;
		case 6:
			l1.reverse();
			break;
		}

		cout << "Do you want to continue?(y\\n)" << endl;
		cin >> dec;

	} while (dec == 'y');
	Pinnacle *temp;
	temp = first;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = l1.first;
}
void linkedlist::sort(){
int p;
string n;
Pinnacle *t1,*t2;

for(t1=first;t1!=NULL;t1=t1->next){
	for(t2=t1;t2!=NULL;t2=t2->next)
		if(t1->prn>t2->prn){
			p=t1->prn;
			n=t1->name;

			t1->prn=t2->prn;
			t1->name=t2->name;

			t2->prn=p;
			t2->name=n;
		}


}

}

int main() {
	char dec;
	int i;
	linkedlist l;

	do {
		cout << "What operation you want to perform?" << endl;

		cout << "1.Add President" << endl;
		cout << "2.Add Secretary" << endl;
		cout << "3.Add Member" << endl;
		cout << "4.Delete Member" << endl;
		cout << "5.Display All" << endl;
		cout << "6.Reverse the list" << endl;
		cout << "7.Count the number of Members" << endl;
		cout << "8.Concatenate with other list" << endl;
		cout << "9.Sort the List" << endl;

		cin >> i;

		switch (i) {
		case 1:
			l.addpresident();
			break;
		case 2:
			l.addsecretary();
			break;
		case 3:
			l.addmember();
			break;
		case 4:
			l.deletemember();
			break;
		case 5:
			l.display();
			break;
		case 6:
			l.reverse();
			break;
		case 7:
			l.count();
			break;
		case 8:
			l.concat();
			l.display();
			break;
		case 9:
			l.sort();
			l.display();
			break;
		}

		cout << "Do you want to continue?(y\\n)" << endl;
		cin >> dec;

	} while (dec == 'y');

	return 0;
}

