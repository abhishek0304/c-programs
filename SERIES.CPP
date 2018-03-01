#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
int n;
float s=0,a,i;
clrscr();
printf("enter the value of n\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
a=1/pow(i,2);
s=s+a;
}
printf("the sum is %f",s);
getch();
}