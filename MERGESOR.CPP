#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int l, int r);
void mergethem(int a[],int l, int m, int r);
void main()
{
  int a[10],i;
  printf("Enter the unsorted array\n");
  for(i=0;i<10;i++)
  scanf("%d",&a[i]);
  mergesort(a,0,9);
  printf("The unsorted array is: \n");
  for(i=0;i<9;i++)
  printf("%d  ",a[i]);
}



void mergesort(int a[],int l, int r)
{int mid;
   if(l<r)
   {
   mid=(l+r)/2;
   mergesort(a,l,mid);
   mergesort(a,mid+1,r);
   mergethem(a,l,mid,r);
   }
}



void mergethem(int a[],int l,int m,int r)
{
    int i,j,p;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];

    for(i=0;i<n1;i++)
    L[i]=a[l+i];
    for(j=0;j<n2;j++)
    R[j]=a[m+j+1];
    i=0;
    j=0;
    p=l;


    while(i<n1&&j<n2)
    {
      if(L[i]<R[j])
      {
	a[p]=L[i];
	p++;
	i++;
      }
      else
      {
      a[p]=R[j];
      p++;
      j++;
      }
    }


    while(i<n1)
    {
      a[p]=L[i];
      p++;
      i++;
    }
      while(j<n2)
      {
      a[p]=R[j];
      p++;
      j++;
      }

}