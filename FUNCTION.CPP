#include<stdio.h>
#include<conio.h>
int sum(int a,int b);
void main()
{
int a,b,s=0;
clrscr();
printf("enter a and b\n");
scanf("%d%d",&a,&b);
s=sum(a,b);
printf("%d+%d=%d\n",a,b,s);
printf("enter a and b\n");
scanf("%d%d",&a,&b); s=sum(a,b);
printf("%d+%d=%d",a,b,s);
getch();
}
int sum(int c,int d)
{int result;
result=c+d;
return result;
}