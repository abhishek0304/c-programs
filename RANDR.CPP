#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
clrscr();
const int low=25;
randomize();
int point=5,number;
for(int i=1;i<=4;i++)
{
number=low+random(point);
cout<<number<<":";
point--;
}
getch();
}