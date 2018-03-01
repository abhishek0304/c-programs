#include<stdio.h>
#include<conio.h>
void quicksort(int a[],int p,int q);
int partition(int a[],int p,int q);
void main()
{
  int a[10],i;
  clrscr();
  printf("enter the unsorted array");
  for(i=0;i<=9;i++)
  scanf("%d",&a[i]);
  quicksort(a,0,9);
  printf("sorted array\\n");
  for(i=0;i<=9;i++)
  printf("%d ",a[i]);
  getch();
}

void quicksort(int a[],int p, int q)
{  int m;
  if(p<=q)


  {
  m=partition(a,p,q);
  quicksort(a,p,m-1);
  quicksort(a,m+1,q);
  }
}




int partition(int a[],int p, int q)
{
   int pivot,temp,tempz,i,j;
   pivot=a[p];
   i=p;
   for(j=i+1;j<=q;j++)
   {
      if(a[j]<=pivot)
      {
       i=i+1;
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
      }
   }
   tempz=a[p];
   a[p]=a[i];
   a[i]=tempz;
   return i;
}
