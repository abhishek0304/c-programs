#include<stdio.h>
#include<conio.h>
int fibo(int n);
void main()
{
int f,n;
clrscr();
printf("enter the value of n=");
scanf("%d",&n);
f=fibo(n);
printf("%d",f);
getch();
}
int fibo(int n)
{
if(n==1)
return (0);
else if(n==2)
return(1);
else
return(fibo(n-2)+fibo(n-1));
}