#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,f=0,a[100],elt;
printf("\nenter the no. of elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
printf(" %d",a[i]);
printf("\nenter the no. you want to search:");
scanf("%d",&elt);
for(i=0;i<n;i++)
{
if(a[i]==elt)
{
f=1;
printf("element found");
break;
}}
if(f==0)
printf("not found");
getch();
}