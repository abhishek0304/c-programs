#include<stdio.h>
#include<conio.h>
int f1(int n);
void main()
{
int f,n;
clrscr();
printf("enter the value of n=");
scanf("%d",&n);
f=f1(n);
printf("%d",f);
getch();
}
int f1(int n)
{int r,s;
r=n%10;
s=s*10+r;
if(n==0)
return (0);
else
return(r+f1(n/10));
}