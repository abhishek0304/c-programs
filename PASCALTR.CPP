#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,k,p,n;
clrscr();printf("enter no. of rows"); scanf("%d",&n);
for(i=1;i<=n;i++)
{for(k=n;k>=i;k--)  printf(" ",k);
for(j=1;j<=i;j++)
printf("%d",j);
for(p=i-1;p>=1;p--)printf("%d",p);printf("\n"
);
}
getch();  }