#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char a[40],b[40]; int i=0,t=0;
clrscr();
printf("enter the string :\n");
gets(a);gets(b);
while(a[i]!='\0'||b[i]!='\0')
{
if(a[i]!=b[i])
break;i++;}
t=a[i]-b[i];
if(t==0)
printf("same");
else
printf("not same");

getch();
}