#include<stdio.h>
#include<conio.h>
void main()
{
int i=0,l=0;
char s[30];
clrscr();
fflush(stdin);
printf("enter the string:\n");
gets(s);
while(s[i]!='\0')
{i++;
i=l;
}
printf("the length of string is : %d",l);
getch();
}
