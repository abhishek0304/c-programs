#include<stdio.h>
#include<conio.h>
void main()
{
char a[40],b[40]; int i=0,j=0;
clrscr();
printf("enter the string :\n");
gets(a);gets(b);
while(b[i]!='\0')
i++;
while(a[j]!='\0')
{
b[i]=a[j];
i++;
j++;} b[i]='\0';
puts(b);
getch();
}