#include<stdio.h>
#include<conio.h>
void main()
{
int a[10][10],b[10][10],c[10][10],i,j,r1,c1,r2,c2;
clrscr();
printf("enter the no. of rows and column of A=");
scanf("%d%d",&r1,&c1);
printf("enter the no. rows and column of B=");
scanf("%d%d",&r2,&c2);
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
{
scanf("%d",&b[i][j]);
}
}
if(r1==r2&&c1==c2)
{
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{c[i][j]=a[i][j]+b[i][j];
printf("[%d]",c[i][j]);
}
printf("\n");
}}
getch();
}