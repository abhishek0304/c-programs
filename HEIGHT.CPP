#include<iostream.h>
#include<conio.h>
#include<dos.h>
/*class height
{
int feet;
int inch;
public:
void getdata(int a,int b)
{
feet=a;
inch=b;
}
void sum(height h1,height h2)
{
inch=((h1.inch+h2.inch)%12);
feet=(h1.feet+h2.feet+(h1.inch+h2.inch)/12);
}
void display()
{
cout<<feet<<" ft "<<inch<<"  inch";
}
};
void fx()
{
static int c=1;
cout<<c;
c++;
}
void gx()
{
int d=1;
cout<<d;
d++;
} */
class A
{
int a;
static int count;
public:
void getdata()
{
cout<<"Enter no. ";
cin>>a;
count++;
}
void display()
{
cout<<a;
cout<<count;
}
void dispcount()
{
cout<<count;
}
};
void main()
{
clrscr();
/*height h1,h2,h3;
h1.getdata(5,20);
h2.getdata(5,15);
h3.sum(h1,h2);
h3.display();
fx();
fx();
fx();
gx();
gx();
gx();          */
A a1,a2,a3;
a1.getdata();
a2.getdata();
a1.display();
a1.dispcount();
getch();
}