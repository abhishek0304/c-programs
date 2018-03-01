#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{
while(1)
{
clrscr();
char ch;
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
if (ch == 27)
return;

		else if (ch == '1')
		{
		   cout<<"A";
		    getch();
		}

		else if (ch == '2')
		{
		cout<<"b";
		 getch();
		}

		else if (ch == '3')
		{
			cout<<"c";
			 getch();
			 }
		else if (ch == '4')
		{
		    cout<<"d";
		    getch();
		}

		else if (ch == '0')
		return;
}
getch();
}