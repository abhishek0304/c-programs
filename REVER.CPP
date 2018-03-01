#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
clrscr();
int n=0,i,j,k;
char st[90];
cout<<"Enter string";
gets(st);
for(i=0;i<'/0';i++)
n++;
for(i=0,j=n-1;i<'/0';i++,j++)
{
st[i]=st[j];
st[j]=st[k];
st[k]=st[i];
}
cout<<"reversed: "<<st;
getch();
}