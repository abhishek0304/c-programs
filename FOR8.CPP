#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,k,p,n;
clrscr();printf("enter no. of rows"); scanf("%d",&n);
for(i=1;i<=n;i++)
{for(j=1;j<=i;j++)
printf("%d%d ",i,j); printf("\n");
}
getch();  }