#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,j,max,a[100],elt;
clrscr();
printf("\nEnter the no. of elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
printf("%d",a[i]);
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{elt=a[j];
a[j]=a[j+1];
a[j+1]=elt;}
}}
printf("\nThe sorted array is:");
for(i=0;i<n;i++)
printf("    %d",a[i]);
getch();
}