#include<stdio.h>
#include<conio.h>
int fact(int n);
void main()
{
int f,n;
clrscr();
printf("enter the value of n=");
scanf("%d",&n);
f=fact(n);
printf("\nfactorial=%d",f);
getch();
}
int fact(int n)
{
if(n==1)
return(1);
else
return(n*fact(n-1));
}