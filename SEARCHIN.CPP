#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
class emp
{
private:
	 int no;
	 char name[100];
	 int salary;
public:
	void getdata()
	{
	cout<<"Enter the Employ number,name and Salary ";
	cin>>no;
	gets(name);
	cin>>salary;
	}
	void putdata()
	{
	cout<<no<<"\n";
	cout<<name<<"\n";
	cout<<salary<<"\n";
	}
	void modify()
	{
	int s;
	char nm[20];
	cout<<"Enter new Name";
	gets(nm);
	cout<<"Enter new Salary";
	cin>>s;
	if(strcmp(nm,".")!=0)
	strcpy(name,nm);
	if(s!=-1)
	salary=s;
	}
	int getempno()
	{
	return(no);
	}
	int getsal()
	{
	return(salary);
	}
	char* getname()
	{
	return(name);
	}
};
void searchempno()
{
  emp E;
 ifstream fin;
 fin.open("Emp.dat",ios::in|ios::binary);
 if(!fin)
 {
 cout<<"File not found";
 getch();
 exit(0);
 }
 int flag=0,no;
 cout<<"Enter the Number to be Searched";
 cin>>no;
 while(fin)
  {
 fin.read((char*)&E,sizeof(E));
 if(fin.eof())
 break;
 if(E.getempno()==no)
 {
 E.putdata();
 flag=1;
 break;
  }
   }
 if(flag==0)
 cout<<"Record not found";

 fin.close();
 }

void searchname()
{
char st[100];
int flag=0;
ifstream fin;
emp E;
fin.open("Emp.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"Record not found";
getch();
exit(0);
}
cout<<"Enter name to be Searched";
gets(st);
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
if(strcmp(E.getname(),st)==0)
{
E.putdata();
flag=1;
break;
}
}
if(flag==0)
cout<<"Record not Found"<<"\n";
fin.close();
}

void searchsal()
{
int sal,flag=0;
emp E;
ifstream fin;
fin.open("Emp.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"Record not found"<<"\n";
getch();
exit(0);
}
cout<<"Enter the Employ Salary to be searched-";
cin>>sal;
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
if(E.getsal()==sal)
{
E.putdata();
flag=1;
break;
}
}
if(flag==0)
cout<<"Record not found"<<"\n";
fin.close();
}
void deleteemp()
{
fstream fin,temp;
fin.open("Emp.dat",ios::in|ios::binary);
temp.open("temp.dat",ios::out|ios::binary);
if(!fin||!temp)
{
cout<<"Record not found";
getch();
exit(0);
}
emp E;
int flag=0,n;
char ans;
cout<<"Enter the Employ Number to be deleted";
cin>>n;
while(fin)
{
fin.read((char*)&E,sizeof(E));
if(fin.eof())
break;
if(E.getempno()==n)
{
E.putdata();
flag=1;
cout<<"Do you Wish to Continue y-yes and n-no";
cin>>ans;
if(ans=='n' || ans=='N')
temp.write((char*)&E,sizeof(E));
else
cout<<"Record Deleted"<<"\n";
E.putdata();
}
}
temp.write((char*)&E,sizeof(E));
if(flag==0)
cout<<"Record not found";
fin.close();
temp.close();
remove("Emp.dat");
rename("temp.dat","emp.dat");
}
void modification()
{
int no,pos=0;
emp E;
fstream f;
f.open("Emp.dat",ios::in|ios::binary|ios::out);
if(!f)
{
cout<<"Record not found";
getch();
exit(0);
}
pos=0;
cout<<"Enter Employ Number to be modified";
cin>>no;
while(f)
{
pos=f.tellg();
f.read((char*)&E,sizeof(E));
if(f.eof())
break;
if(E.getempno()==no)
{
E.putdata();
E.modify();
f.seekg(pos,ios::beg);
f.write((char*)&E,sizeof(E));
cout<<"Record Modified";
break;
}
}
f.close();
}
void main()
{
clrscr();
emp E;
int choice;
ofstream fout;
fout.open("Emp.dat",ios::out|ios::binary);
if(!fout)
{
cout<<"File not found";
getch();
exit(0);
}
char ans='y';
while(ans=='y' || ans=='Y')
{
E.getdata();
fout.write((char*)&E,sizeof(E));
cout<<"Do you wish to Continue";
cin>>ans;
}
fout.close();
while(1)
{
cout<<"Menu"<<"\n";
cout<<"1.Search the Employ number"<<"\n";
cout<<"2.Search the Employ name"<<"\n";
cout<<"3.Search the Employ salary"<<"\n";
cout<<"4.Delete the Employ NUmber"<<"\n";
cout<<"5.Modify the Employ Number"<<"\n";
cout<<"6.Exit"<<"\n";
cout<<"Enter the choice-";
cin>>choice;
switch(choice)
{
case 1:searchempno();
       break;
case 2:searchname();
       break;
case 3:searchsal();
       break;
case 4:deleteemp();
       break;
case 5:modification();
       break;
case 6:cout<<"Exiting from the program";
       getch();
       exit(0);
       break;
default:cout<<"Invalid Option";
	break;
}
}
getch();
}
