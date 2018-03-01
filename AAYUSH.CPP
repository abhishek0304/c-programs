//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class crim_rec
{
char name[20], sex, fathr_name[20], addrs[25], offense[20], blood[5], dob[9];
int crim_code, reward;
void disp(); //Function Displays The Data
public:
void get(); //Function To Get Data From User
void wtf(); //Function Writes The Data To File
void rff(); //Function Reads The Data From File
void search(); //Function Search The Record
void del(); //Function Deletes The Record
void mod(); //Function Modifies The Record
}c;
//***************************************************************
//    	Function To Get Data From File
//****************************************************************
void crim_rec::get()
{
clrscr();
cout<<"Enter Name Of Criminal : ";
gets(name);
cout<<"Sex (M/F) : ";
cin>>sex;
cout<<"Enter Date Of Birth : ";
gets(dob);
cout<<"Enter Blood Group : ";
gets(blood);
cout<<"Enter Father's Name : ";
gets(fathr_name);
cout<<"Enter Address : ";
gets(addrs);
cout<<"Enter Crime Commited : ";
gets(offense);
cout<<"Enter Reward On Criminal : ";
cin>>reward;
}
//***************************************************************
//    	Function To Display Record From File
//****************************************************************

void crim_rec::disp()
{
clrscr();
cout<<"The Record Of Criminal:";
cout<<"\nName Of Criminal: "<<name;
cout<<"\nSex: "<<sex;
cout<<"\nDOB: "<<dob;
cout<<"\nBlood Group: "<<blood;
cout<<"\nFather's Name: "<<fathr_name;
cout<<"\nAddress: "<<addrs;
cout<<"\nCrime: "<<offense;
cout<<"\nReward: "<<reward;
}
//***************************************************************
//    	Function To Write To File
//****************************************************************
void crim_rec::wtf()
{
clrscr();
ofstream ofile;
ofile.open("CBI.dat", ios::app);
get();
ofile.write((char*)&c, sizeof(c));
ofile.close();
}

//***************************************************************
//    	Function To Read Record From File
//****************************************************************
void crim_rec::rff()
{
clrscr();
ifstream ifile;
ifile.open("CBI.dat");
ifile.seekg(0, ios::beg);
ifile.read((char*)&c, sizeof(c));
while(ifile)
    {
	disp();
	ifile.read ((char*)&c, sizeof(c));
    }
ifile.close();
}
//***************************************************************
//    	Function Searches Record Of File
//****************************************************************
void crim_rec::search()
{
clrscr();
int flag=1;
char m[200];
ifstream ifile;
ifile.open("CBI.dat",ios::in|ios::out||ios::binary);
cout<<"\nEnter Name Of Criminal Which Has To Be Searched : ";
gets(m);
ifile.seekg (0, ios::beg);
ifile.read((char*)&c, sizeof(c));
while(!ifile.eof())
    {
	ifile.read((char*)&c, sizeof(c));
	if (strcmpi(m,name)==0)
	   {
	disp();
	flag=0;
	break;
	   }
	if(ifile.eof())
	break;
    }
if(flag==1)
cout<<"Record Not Found ";
ifile.close();
}


//***************************************************************
//    	Function To Delete Record Of File
//****************************************************************
void crim_rec::del()
{
clrscr();
char b[200];
int flag=0;
fstream fin,temp;
fin.open("CBI.dat", ios::in|ios::binary);
temp.open("new.dat", ios::out|ios::binary);
cout<<"\nEnter The Name Of The Criminal Whose Records You Want To Delete : ";
gets(b);
while(!fin.eof())
    {
	fin.read((char*)&c,sizeof(c));
	if(fin.eof())
	break;
	if (strcmp(b,name)==0)
	   {
	flag=1;
	cout<<"Record Deleted ";
	    }
	else
	{
	temp.write((char*)&c, sizeof(c));
	}
    }
if(flag==0)
cout<<"Record Not Found ";
fin.close();
temp.close();
remove ("CBI.dat");
rename("new.dat", "CBI.dat");
}
//***************************************************************
//    	Function To Modify Record Of File
//****************************************************************
void crim_rec::mod()
{
clrscr();
char d[20];
int p;
cout<<"\nEnter Name Of Criminal Whose Record You Want To Modify : ";
gets(d);
fstream f;
f.open("CBI.dat", ios::in|ios::out);
f.seekg(0, ios::beg);
f.read((char*)&c, sizeof(c));
int a=f.tellg();
while(! f.eof())
    {
	if (!strcmpi(d, name))
	{
	puts("Press 1 to Change Name");
	puts("Press 2 to Change Sex");
	puts("Press 3 to Change Date Of Birth");
	puts("Press 4 to Change Blood Group");
	puts("Press 5 to Change Father's Name");
	puts("Press 6 to Change Address");
	puts("Press 7 to Change Crime Committed");
	puts("Press 8 to Change Reward On Criminal");
	cin>>p;
	switch(p)
	    {
	case 1:cout<<"\n Enter The New Name : ";
		gets(name);
		break;
	case 2:cout<<"\n Enter The New Gender : ";
		cin>>sex;
		break;
	case 3:cout<<"\n Enter The New D.O.B : ";
		gets(dob);
		break;
	case 4:cout<<"\n Enter The New Blood Group : ";
		gets(blood);
		break;
	case 5:cout<<"\n Enter The New Father's Name : ";
		gets(fathr_name);
		break;
	case 6:cout<<"\n Enter The New Address : ";
		gets(addrs);
		break;
	case 7:cout<<"\n Enter The New Offense : ";
		gets(offense);
		break;
	case 8:cout<<"\n Enter The New Reward : ";
		cin>>reward;
		break;
	    }
	f.seekg(a-sizeof(c), ios::beg);
	f.write((char*)&c, sizeof(c));
	}
	f.read((char*)&c, sizeof(c));
	a=f.tellg();
    }
f.close();
}
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main ()
{
clrscr();
int ch;
char choice='y';
do
    {
clrscr();
gotoxy(16,1);
cout<<" ********************************************";
gotoxy(16,2);
cout<<" *      Central Bureau of Investigation     *";
gotoxy(16,3);
cout<<" ********************************************";
gotoxy(16,4);
cout<<" *  1. View criminal details                *";
gotoxy(16,5);
cout<<" *  2. Add new criminal details             *";
gotoxy(16,6);
cout<<" *  3. Search a criminal record             *";
gotoxy(16,7);
cout<<" *  4. Delete a criminal record             *";
gotoxy(16,8);
cout<<" *  5. Modify a criminal record             *";
gotoxy(16,9);
cout<<" *  6. Exit                                 *";
gotoxy(16,10);
cout<<" ********************************************";
gotoxy(16,12);
cout<<" Enter your choice: ";
cin>>ch;
switch(ch)
    {
case 1:c.rff();
	break;
case 2:  c.wtf();
	break;
case 3:	c.search();
	break;
case 4:    c.del();
	break;
case 5:   c.mod();
	break;
case 6:cout<<"Press Any Key To Exit ";
	getch();
	exit(0);
default:
	{  cout<<endl<<"Wrong Choice Entered!";    }
	break;
    }
cout<<"\nDo You Wish To Continue? (Y/N)  ";
cin>>choice;
}while(choice=='Y'|| choice=='y');
cout<<"\nGood Bye";
getch();
}
