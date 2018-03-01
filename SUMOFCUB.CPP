#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int n,num; float s,i;
clrscr();
printf("\nenter n:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{num=pow(i,3);
s=s+(float)num; printf("sum=%f",s);}
getch();
}