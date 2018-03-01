#include<stdio.h>
#include<conio.h>
void main()
{
int i,j;
char ch=65;
clrscr();
for(i=1;i<=5;i++)
{for(j=1;j<=i;j++)
{if(ch==65)
printf("%c ",ch++); else  printf("%c ",ch--);
}
printf("\n");
}
getch();
}