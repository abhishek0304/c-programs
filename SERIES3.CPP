#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int n; float s,i;
clrscr();
printf("\nenter n:");
scanf("%d",&n);
for(i=1;i<=n;i++)
s=s+(i/i+1); printf("sum=%f",s);
getch();
}