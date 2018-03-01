#include<stdio.h>
#include<conio.h>
void main()
{
int n,f=1;
clrscr();
printf("enter any no.");
scanf("%d",&n);
while(n>0)
{f=f*n;
n=n-1;}
printf("factorial=%d",f);
getch();
}