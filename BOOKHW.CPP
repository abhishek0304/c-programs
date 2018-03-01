#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class book
{
private :
 int bookno;
 char booktitle[20];
 float price;
 void totalcost(int n)
  {
  float totalcost;
  totalcost=n*price;
  cout<<"Total cost : "<<totalcost;
  }
public:
void input()
{
cout<<"Enter the book no. : ";
cin>>bookno;
cout<<"Enter the book title : ";
gets(booktitle);
cout<<"Enter the book price : ";
cin>>price;
}
void purchase()
{
int n;
cout<<"Enter the no. of copies you want to purchase : ";
cin>>n;
totalcost(n);
}
};

void main()
{
clrscr();
book B;
B.input();
B.purchase();
getch();
}




