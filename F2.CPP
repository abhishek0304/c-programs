#include<stdio.h>
#include<conio.h>
int swap(int n);
void main()
{
int n,r;
clrscr();
printf("enter any no.\n");
scanf("%d",&n);
r=swap(n);
printf("reverse of %d=%d\n",n,r);
printf("enter a no.\n");
scanf("%d",&n);
r=swap(n);
printf("reverse of %d=%d\n",n,r);
getch();
} int swap(int n)
{int a,s=0;
while(n>0){
a=n%10;
s=s*10+a;
n=n/10;}
return s;
}

