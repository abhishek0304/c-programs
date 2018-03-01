#include<stdio.h>
#include<conio.h>
float area(int r);
void main()
{
int r; float a;
clrscr();
printf("enter the radius of the circle\n");
scanf("%d",&r);
a=area(r);
printf("area=%f\n",a);
printf("enter the value of r\n");
scanf("%d",&r);
a=area(r);
printf("area=%f",a);
getch();
}
float area(int r)
{
float area;
area=(3.14*r*r);
return area;}