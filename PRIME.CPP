#include<stdio.h>
#include<conio.h>
void main()
{
int n,i=1,c=0;
printf("\nEnter any no.\n");
scanf("%d",&n);
while(i<=(n/2))
{
if(n%i==0)
c++;
i++;
}
if(c>=2)
printf("\n not a prime no.");
else
printf("\n a prime no.");
getch();
}