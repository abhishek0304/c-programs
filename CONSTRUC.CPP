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
cout<<a<<"\n";
cout<<b<<"\n";
}
};
void main()
{
clrscr();
test t1(4,'a');
test t2(t1);
test t3=t1;
test t5;
test t4;
t4=t5;
getch();
}