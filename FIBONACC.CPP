#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,a,b,c;
clrscr();
printf("Enter a no.\n");
scanf("%d",&n);
i=1;
a=0;
b=1;
while(i<=n)
{
printf("%d ",a);
c=a+b;
a=b;
b=c;
i++;
}
getch();
}