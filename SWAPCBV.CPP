#include<stdio.h>
#include<conio.h>
void swap(int a,int b);
void main()
{
int a,b;
printf("enter the value of a=\nb=...\n");
scanf("%d%d",&a,&b);
swap(a,b);
getch();
}
void swap(int a,int b)
{
int t;
t=a;
a=b;
b=t;
printf("swaped values are : %d %d",a,b);
getch();
}