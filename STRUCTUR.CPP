#include<stdio.h>
#include<conio.h>
void main()
{
struct  x
{int a;
char b[20];
float c;
};
struct x y[10];
int i,n;
clrscr();
printf("enter no. of student:");
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&y[i].a);
scanf("%s",&y[i].b);
fflush(stdin);
scanf("%f",&y[i].c);}
fflush(stdin);
for(i=0;i<n;i++)
printf("|%d| |%s| |%f|\n",y[i].a,y[i].b,y[i].c);
getch();
}