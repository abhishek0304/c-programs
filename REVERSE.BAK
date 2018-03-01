#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
clrscr();
int i,j,t,count=0;
char st[90];
cout<<"Enter string : ";
gets(st);
for(i=0;st[i]!=0;i++)
count++;
if(count%2==0)
{
for(i=0,j=count-1;i<count/2;i++,j--)
{
t=st[i];
st[i]=st[j];
st[j]=t;
}
}
else
{
for(i=0,j=count-1;i<(count/2)+1;i++,j--)
{
t=st[i];
st[i]=st[j];
st[j]=t;
}
}
cout<<st;
getch();
}


