#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int x1,x2,y1,y2;
float d;
clrscr();
printf("\nenter x1:");
scanf("%d",&x1);
printf("\nenter x2:");
scanf("%d",&x2);
printf("\nenter y1:");
scanf("%d",&y1);
printf("\nenter y2:");
scanf("%d",&y2);
d=sqrt((x1-x2)+(y1-y2));printf("distance=%f",d);
getch();
}