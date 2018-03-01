#include<iostream.h>
#include<conio.h>
class test{
int a;
char b;
public:
test()
{
cout<<"Default constructor is called here "<<"\n";
a=0;
b='D';
cout<<a<<"\n";
cout<<b<<"\n";
}
test(int i,char j)
{
a=i;
b=j;
cout<<"Constructor with arguments called"<<"\n";
}
test(test &t)
{
a=t.a;
b=t.b;
cout<<"copy constr. working...\n";
}
void print()
{
cout<<a<<"\n";
cout<<b<<"\n";
}
};
void main()
{
clrscr();
test t1(4,'a');
t1.print();
test t2(t1);
t2.print();
test t3=t1;
t3.print();
getch();
}