#include<stdio.h>
#include<conio.h>
void main()
{
int p,r,t;
float si;
clrscr();
printf("enter p:");
scanf("%d",&p);
printf("enter r:");
scanf("%d",&r);
printf("enter t:");
scanf("%d",&t);
si=p*r*t/100;
printf("simple interest=%f",si);
getch();
}