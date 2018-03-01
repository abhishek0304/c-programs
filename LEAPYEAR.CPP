#include<stdio.h>
#include<conio.h>
void main()
{
int y;
clrscr();
printf("enter the value of y");
scanf("%d",&y);
if((y%4==0)&&(y%100!=0)||(y%400==0));
printf("a leap year",y);
else
printf("not a leap year");
getch();
}