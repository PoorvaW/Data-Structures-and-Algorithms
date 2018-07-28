#include <iostream>
#include <math.h>
using namespace std;

class node{
    int coef,exp;
    node *next;
public:

    void get(){
        cout<<"Enter Coefficient\n";
        cin>>coef;
        cout<<"Enter Exponent\n";
        cin>>exp;
                }


    node(){
        coef=0;
        exp=0;
        next=NULL;
                }

friend class poly;
};



class poly{
    node *first;
public:
    poly(){
        first=NULL;
            }
    void getf();
    void disp();
    void add(poly b);
    void put(int x,int y);
    void eval(int num);
};

void poly::eval(int num){
        int sum=0;
        node *temp=first;
        do{
        sum=sum+temp->coef*pow(num,temp->exp);
        temp=temp->next;
        }while(temp!=first);

        cout<<sum<<"\n";
                        }


void poly::put(int x,int y){
        node *temp=first;
        node *obj=new node();
        obj->coef=x;
        obj->exp=y;

        if(temp==NULL){
        first=obj;
        obj->next=first;
        }
        else{
        while(temp->next!=first)
        temp=temp->next;

        temp->next=obj;
        obj->next=first;
        }
                        }


void poly::getf()
{
        char dec;
        do{
        node *temp=first;
        node *obj=new node();
        obj->get();
        if(temp==NULL){
        first=obj;
        obj->next=first;
        }
        else{
        while(temp->next!=first)
        temp=temp->next;

        temp->next=obj;
        obj->next=first;
        }
        cout<<"Do you want to enter another term?(y/n)\n";
        cin>>dec;
        }while(dec=='y'||dec=='Y');
                        }


void poly::disp(){
        node *temp;
        temp=first;
        while(temp->next!=first){
        cout<<temp->coef<<"x^"<<temp->exp<<"+";
        temp=temp->next;
        }
        cout<<temp->coef<<"x^"<<temp->exp<<"\n";
                        }

void poly::add(poly b){
poly c;
node *t1=first;
node *t2=b.first;
int cof;
while(t1->next!=first&&t2->next!=b.first)
{
if(t1->exp==t2->exp)
{   cof=t1->coef+t2->coef;
    if(cof!=0)
    c.put(cof,t1->exp);
    t1=t1->next;
    t2=t2->next;
 }
 else
    if(t1->exp>t2->exp)
        {c.put(t1->coef,t1->exp);
        t1=t1->next;
        }
        else{
            c.put(t2->coef,t2->exp);
            t2=t2->next;
            }
}

if(t1->exp==t2->exp)
{   cof=t1->coef+t2->coef;
    if(cof!=0)
    c.put(cof,t1->exp);
    t1=t1->next;
    t2=t2->next;
 }
 else
    if(t1->exp>t2->exp)
        {c.put(t1->coef,t1->exp);
        t1=t1->next;
        }
        else{
            c.put(t2->coef,t2->exp);
            t2=t2->next;
            }



while(t2!=b.first){
    c.put(t2->coef,t2->exp);
                t2=t2->next;
    }


while(t1!=first)
    {c.put(t1->coef,t1->exp);
            t1=t1->next;
            }
c.disp();
}


int main(){
    int x;
    poly p,p1;
        p.getf();
        p.disp();
cout<<"Enter the value of x for which you want to evaluate\n";
cin>>x;
cout<<"EVALUATED VALUE:\n";
        p.eval(x);
        p1.getf();
        p1.disp();
cout<<"ADDITION IS:\n";
        p.add(p1);
return 0;
}
