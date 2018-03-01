#include<stdio.h>
#include<conio.h>
void main()
{
int n,m,s=0;
printf("\nenter the value of m:");
scanf("%d",&m);
printf("\nenter the value of n:");
scanf("%d",&n);
while(m<=n)
{s=s+m;
m++;}
printf("sum=%d",s);
getch();
}
