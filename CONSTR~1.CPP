#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class emp
{
int eno;
char name[20];
public:
emp()
{
eno=1;
strcpy(name,"xyz");
}
void getdata()
{
cout<<"Enter eno : ";
cin>>eno;
cout<<"Enter name : ";
gets(name);
}
void display()
{
cout<<eno<<" "<<name;
}
};
void main()
{
clrscr();
emp e1,e2;
e1.getdata();
e1.display();
cout<<"\n";
e2.display();
getch();
}