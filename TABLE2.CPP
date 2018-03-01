#include<stdio.h>
#include<conio.h>
void main()
{
int n,i;
clrscr();
printf("enter the table you want to see:");
scanf("%d",&n);   printf("*************************");printf("\n"); printf("Multiplication table of %d",n); printf("\n*************************");
for(i=1;i<=20;i++){ printf("\n%d*%d=%d",n,i,(n*i));}
getch();
}