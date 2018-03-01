#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c;
clrscr();
printf("\n Enter the value of a=");
scanf("%d",&a);
printf("\n Enter the value of b=");
scanf("%d",&b);
printf("\n Enter the value of c=");
scanf("%d",&c);
if(a>b)
{
if(b>c)
printf("\n a is max");
else
printf("\n c is max");
}
else
{
if(a>c)
printf("\n b is max");
else
printf("\n c is max");
}
getch();
}