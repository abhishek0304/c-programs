#include<stdio.h>
#include<conio.h>
void main()
{
int n,i=0;
clrscr();
printf("enter the value of n");
scanf("%d",&n);
while(i<10)
{i++;
printf("\n%d*%d=%d",n,i,n*i);}
getch();
}