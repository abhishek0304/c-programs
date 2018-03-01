#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int *val,r,c;
cout<<"Enter dimensions : ";
cin>>r>>c;
val=new int[r*c];
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
cin>>val[i*c+j];
}
}
for(i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
cout<<val[i*c+j];
}
}
getch();
}