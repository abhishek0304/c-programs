#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
class emp
 {
int eno;
public :
void getdata()
 {
cout<<"Enter eno : ";
cin>>eno;
 }
void putdata()
 {
cout<<eno;
 }
int getempno()
{
return(eno);
}
};
emp E;

/*Searching*/
void searchempno()
{
int flag=0,no;
ifstream fin;
fin.open("emp.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"file not found";
getch();
exit(0);
}
cout<<"Enter the no. to be searched"<<"\n";
cin>>no;
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
if(E.getempno()==no)
{
E.putdata();
cout<<"\n";
flag=1;
break;
}
}
if(flag==0)
cout<<"Record not found";
fin.close();
}

/*Deletion*/

void deleteempno()
{
fstream fin,temp;
fin.open("emp.dat",ios::in|ios::binary);
temp.open("temp.dat",ios::out|ios::binary);
if(!fin||!temp)
{
exit(0);
}
char ans;
int flag=0,no;
cout<<"Enter the no. to be deleted : ";
cin>>no;
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
if(E.getempno()==no)
{
E.putdata();
cout<<"\n";
flag=1;
cout<<"Record deleted"<<"\n";
}
else
temp.write((char*)&E,sizeof(E));
}
if(flag==0)
cout<<"Record not found";
fin.close();
temp.close();
remove("emp.dat");
rename("temp.dat","emp.dat");
getch();
}

void display()
{
ifstream  fin;
fin.open("emp.dat",ios::in|ios::binary);
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
E.putdata();
cout<<"\n";
}
fin.close();
getch();
}

/*Main*/
void main()
{
clrscr();
ofstream fout;
fout.open("emp.dat",ios::binary|ios::out);
if(!fout)
{
cout<<"file not found ";
getch();
exit(0);
}
char ans='y';
while(ans=='y'||ans=='Y')
{
E.getdata();
fout.write((char*)&E,sizeof(E));
cout<<"Do you wish to continue"<<"\n";
cin>>ans;
}
fout.close();
char ch='y';
int choice;
while(ch=='y'||ch=='Y')
{
cout<<"Menu"<<"\n";
cout<<"1.Searching"<<"\n";
cout<<"2.Deletion"<<"\n";
cout<<"Enter ur choice : "<<"\n";
cin>>choice;
switch(choice)
{
case 1: searchempno();
break;
case 2: {
	deleteempno();
	display();
	break;
	}
default: cout<<"Invalid choice";
break;
}
cout<<"Do you wish to conitnue ? "<<"\n";
cin>>ch;
}
getch();
}
