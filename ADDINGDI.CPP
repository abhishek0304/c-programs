#include<stdio.h>
#include<conio.h>
void main()
{
int s=0,a[10][10],i,j,r1,c1;
clrscr();
printf("enter the no. of rows and column of A=");
scanf("%d%d",&r1,&c1);
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
scanf("%d",&a[i][j]);
}
}
{
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{if(i==j)
s=s+a[i][j];
printf("|%d|",s);
}
printf("\n");
}}
getch();
}