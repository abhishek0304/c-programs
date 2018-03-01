#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int n; float s,i;
clrscr();
printf("enter n");
scanf("%d",&n);
for(i=1;i<=n;i++)
s=s+(1/pow(i,2)); printf("sum=%f",s);
getch();
}