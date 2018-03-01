#include<stdio.h>
#include<conio.h>
void swap(int *a,int *b);
void main()
{
int a,b;
printf("enter the value of a=");
scanf("%d",&a);
printf("Enter the value of b=");
scanf("%d",&b);
swap(&a,&b);
printf("swapped values are : %d %d",a,b);
getch();
}
void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
getch();
}