#include<stdio.h>
#include<conio.h>
void main()
{
int i=0,j=0;
char a[50],b[50];
printf("Enter the string...\n");
gets(a);
printf("Enter 2nd string...\n");
gets(b);
while(a[i]!='\0')
i++;
while(b[j]!='\0')
{
a[i]=b[j];
i++;
j++;
}
a[i]='\0';
puts(a);
getch();
}