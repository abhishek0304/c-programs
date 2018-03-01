#include<stdio.h>
#include<conio.h>
void selection(int a[],int n);
void main()
{
int a[50],i,n;
clrscr();
printf("Enter the size of array:\n");
scanf("%d",&n);
printf("Enter the elements of array\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
selection(a,n);
getch();
}
void selection(int a[],int n)
{
int i,j,t,min;
for(i=0;i<n;i++)
 {
  for(j=i;j<n;j++)
   {
   if(a[j]<=min)
    {
    min=a[j];

    }
   t=a[i];
   a[i]=a[j];
   a[j]=t;
  }
for(i=0;i<n;i++)
{printf("%d",a[i]);}
}
}