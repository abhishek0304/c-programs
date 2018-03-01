#include<stdio.h>
#include<conio.h>
void main()
{
int a[100];
int n,elt,i,pos;
clrscr();
printf("No. of elements in the array=");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the element you want to insert=");
scanf("%d",&elt);
printf("In which postion you want to insert=");
scanf("%d",&pos);
for(i=n;i>pos;i--)
{a[i]=a[i-1];
a[pos]=elt;}
for(i=0;i<=n;i++)
printf(" %d ",a[i]);
getch();
}
