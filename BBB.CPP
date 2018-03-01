#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
void main()
{
clrscr();
fstream fout,fin;
fout.open("marks.dat",ios::out);
char ans='y';
int rollno,marks;
while(ans=='y'||ans=='Y')
{
cout<<"Enter rollno : ";
cin>>rollno;
cout<<"Enter marks : ";
cin>>marks;
fout<<rollno<<"\n"<<marks<<"\n";
cout<<"want to enter more records ? ";
cin>>ans;
}
fout.close();
fin.open("marks.dat",ios::in);
fin.seekg(0);
cout<<"\n";
fin>>rollno;
fin>>marks;
cout<<"rollno : "<<rollno<<"\n";
cout<<"marks"<<marks<<"\n";
fin.close();
getch();
}