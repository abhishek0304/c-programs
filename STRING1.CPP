#include<stdio.h>
#include<conio.h>
void main()
{
char s[40];
int i=0,l=0;
gets(s);
while(s[i]!='\0')
{
i++;
l++;
}
printf("%d",l);
getch();
}