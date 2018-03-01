#include<stdio.h>
#include<conio.h>
int pattern(int n);
void main()
{
int n,p;
clrscr();
printf("enter any no.\n");
scanf("%d",&n);
p=pattern(n);
printf("%d",p);
getch();
}
int pattern(int n)
{ int i,j;
for(i=1;i<=n;i++)
{ for(j=1;j<=i;j++)
{printf("%d",j);
}printf("\n");}
 return i;}