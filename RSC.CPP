#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
clrscr();
char k,st[90];
int n=0,i,j;
cout<<"Enter string : ";
gets(st);
for(i=0;st[i]!='/0';i++)
{
n++;
}
for(i=0,j=n-1;st[i]!=n;i++,j--)
{
k=st[i];
st[i]=st[j];
st[j]=k;
}
cout<<st;
getch();
}