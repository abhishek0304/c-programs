#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<fstream.h>
#include<dos.h>
class menu
{
private:
	void edit();

public:
	 void mainmenu();
};

class travel
{
private: char st1[40],st2[40],st3[40];
	 int fare,code;

public:  void getdata()
	 {
	 cout<<"Enter the Destination code";
	 cin>>code;
	 cout<<"Enter the Current Destination";
	 gets(st1);
	 cout<<"Enter the Desired Destination";
	 gets(st2);
	 cout<<"Enter the Mode of Transpot";
	 gets(st3);
	 }
	 void modify()
	 {
	 int s;
	 char st4[40],st5[40],st6[40];
	 cout<<"Enter the New Destination Code";
	 cin>>s;
	 cout<<"Enter the New Current Destination";
	 gets(st4);
	 cout<<"Enter the New Desrired Destination";
	 gets(st5);
	 cout<<"Enter the New Mode of Transpot";
	 gets(st6);
	 if(s!=-1)
	 {
	 code=s;
	 }
	 if(strcmp(st1,".")!=0)
	 strcpy(st1,st4);
	 if(strcmp(st2,".")!=0)
	 strcpy(st2,st5);
	 if(strcmp(st3,".")!=0)
	 strcpy(st3,st6);
	 }
	 int getcode()
	 {
	 return(code);
	 }
	 char* getname1()
	 {
	 return(st1);
	 }
	 char* getname2()
	 {
	 return(st2);
	 }
	 char* getname3()
	 {
	 return(st3);
	 }
	 void seemenu();
	 void addrecord();
	 void modifyrecord();
	 void deleterecord();
};

void menu::mainmenu()
{
clrscr();
char ch;
travel T;
menu M;
clrscr();
while(1)
{
gotoxy(12,6);
textcolor(15);
cout<<"TRAVOLIC PVT.LTD";
textcolor(15);
gotoxy(11,7);
cout<<"------------------";
gotoxy(32,9);
cout<<"1.DESIRED DESTINATIONS";
gotoxy(32,10);
cout<<"2.DESTINATIONS";
gotoxy(32,11);
cout<<"3.EDIT DESTINATIONS";
gotoxy(32,12);
cout<<"4.TOTAL FARE";
gotoxy(32,13);
cout<<"5.QUIT";
gotoxy(32,14);
cout<<"ENTER CHOICE : ";
cin>>ch;
if(ch=='1')
{
}
else if(ch=='2')
{
T.seemenu();
}
else if(ch=='3')
{
edit();
}
else if(ch=='4')
{
}
else
{
gotoxy(32,16);
cout<<"Exiting";
delay(500);
cout<<".";
delay(500);
cout<<".";
delay(500);
cout<<".";
delay(500);
exit(0);
}
}
}
void menu::edit()
{

	 char  ch;
	 travel T;
	 clrscr();
	 while(1)
	 {
	 for(int i=0;i<21;i++)
	 {
	    gotoxy(21,i);
	    cout<<"                                     ";
	    }
	 gotoxy(32,6);
	 cout<<"EDIT MENU";
	 gotoxy(32,7);
	 cout<<"~~~~~~~~~~~";
	 gotoxy(32,10);
	 cout<<"1.ADD RECORD";
	 gotoxy(32,12);
	 cout<<"2.MODIFY RECORD";
	 gotoxy(32,14);
	 cout<<"3.DELETE RECORD";
	 gotoxy(32,16);
	 cout<<"4.Exit";
	 gotoxy(32,19);
	 cout<<"ENTER CHOICE : ";
	 cin>>ch;

	 if(ch=='1')
	 {
	 T.addrecord();
	 }
	 else if(ch=='2')
	 {
	 T.modifyrecord();
	 }
	 else if(ch=='3')
	 {
	 T.deleterecord();
	 }
	 else if(ch=='4')

	 break;
	 }
	 clrscr();
	 }




void travel::addrecord()
{
clrscr();
travel T;
ofstream fout;
fout.open("ar.dat",ios::out|ios::binary);
if(!fout)
{
cout<<"File not found";
getch();
exit(0);
}
char ans='y';
while(ans=='y' || ans=='Y')
{
getdata();
fout.write((char*)&T,sizeof(T));
cout<<"Do you wish to Continue";
cin>>ans;
}
fout.close();
clrscr();
}
void travel::modifyrecord()
{
clrscr();
int no,pos=0;
travel T;
fstream f;
f.open("ar.dat",ios::in|ios::binary|ios::out);
if(!f)
{
cout<<"Record not found";
getch();
exit(0);
}
pos=0;
cout<<"Enter Destination code to be modified";
cin>>no;
while(f)
{
pos=f.tellg();
f.read((char*)&T,sizeof(T));
if(f.eof())
break;
if(getcode()==no)
{

modify();
f.seekg(pos,ios::beg);
f.write((char*)&T,sizeof(T));
cout<<"Record Modified";
break;
}
}
f.close();
clrscr();
}
void  travel::seemenu()
{
clrscr();
travel T;
fstream file;
file.open("ar.dat",ios::binary|ios::in);
file.seekg(0);
int row = 6 , found = 0,pageno;
gotoxy(30,2);
cout<<"SEE MENU ";
gotoxy(29,3);
cout<<"~~~ ~~~~~";
gotoxy(3,4);
cout<<"Destination Code      Current Destination         Desired Destination           Mode of transport ";
gotoxy(2,5);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

while(file.read((char *)&T,sizeof(T)))
{
		found = 1;
		gotoxy(5,row);
		cout<<code;
		gotoxy(14,row);
		cout<<st1;
		gotoxy(37,row);
		cout<<st2;
		gotoxy(57,row);
		cout<<st3;

		if(row == 22)
		{
			row = 5;
			gotoxy(66,1);
			cout<<"Page no. : "<<pageno;
			gotoxy(66,2);
			cout<<"===============";
			pageno++;
			gotoxy(1,25);
			cout<<"Press any key to continue...";
			getche();
			clrscr();
			gotoxy(30,2);
			cout<<"DESTINATIONS";
			gotoxy(3,4);
			cout<<"ITEM CODE ITEM NAME  ITEM PRICE";
			gotoxy(2,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
			row++;
	}

	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	gotoxy(66,1);
	cout<<"Page no. :"<<pageno;
	gotoxy(66,2);
	cout<<"===============";
	gotoxy(1,25);
	cout<<"Press any key to continue..";
	getche();
	file.close();
	clrscr();
	}


void travel::deleterecord()
{
clrscr();
fstream fin,temp;
fin.open("ar.dat",ios::in|ios::binary);
temp.open("temp.dat",ios::out|ios::binary);
if(!fin||!temp)
{
cout<<"Record not found";
getch();
exit(0);
}
travel T;
int flag=0,n;
char ans;
cout<<"Enter the Destination code to be deleted";
cin>>n;
while(fin)
{
fin.read((char*)&T,sizeof(T));
if(fin.eof())
break;
if(getcode()==n)
{
flag=1;
cout<<"Do you Wish to Continue y-yes and n-no";
cin>>ans;
if(ans=='n' || ans=='N')
temp.write((char*)&T,sizeof(T));
else
cout<<"Record Deleted"<<"\n";
}
}
temp.write((char*)&T,sizeof(T));
if(flag==0)
cout<<"Record not found";
fin.close();
temp.close();
remove("ar.dat");
rename("temp.dat","ar.dat");
}
void ouuty()
{
clrscr();
int i,j;
for(i=0;i<1;i++)
{
gotoxy(26,7);
cout<<"WELCOME TO TRAVOLIC PVT.LTD";
gotoxy(25,8);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
gotoxy(24,12);
cout<<"BY: AAYUSH CHAND AND RISHABH SINGH"<<"\n";
gotoxy(25,13);
cout<<"   ------ -----     ------- -----";
cout<<"\t\t\t\t\t\t\t\tXII-B"<<"\n";
getchar();
}
}

void main()
{
clrscr();
ouuty();
menu M;
M.mainmenu();
getch();
}

