


#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


class menu
{
	public :
		  void main_menu();

	private :
		  void edit_menu();
};


class food
{
	public :
		  void  add_item();
		  void  delete_item();
		  void  modify_item();
		  void  list_of_item();
		  void  purchase();

	 private :
		  char  itemname[30];
		  int   itemcode;

		  float itemprice;

		  void  delete_record(int);
		  void  modify_record(int);
		  void  display_record(int);
		  void  sort();
		  int   last_code();
		  int   item_found(int);
		  int   recordno(int);
};

class account
{
	public :
		void bill_list();
		void prepare_bill(int);
		int  last_billno();
		void add_bill(int, int t_itemcode, char *t_itemname,
				float t_qty,float t_price);

	 private :
		int   code, billno, length;
		int   dd, mm, yy;
		float  price, quantity;
		char  name[30];
};



void menu :: main_menu()
{
	clrscr();
	char ch;

	while (1)
	 {
		clrscr();
		gotoxy (12,6);
		textcolor(15);
		cout<<"FAST  FOOD  OUTLET  MANAGEMENT  SYSYTEM ";
		textcolor(15);
		gotoxy(11,7);
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(32,9);
		cout<<"1: PURCHASE FOOD ITEM";
		gotoxy(32,10);
		cout<<"2: SEE MENU";
		gotoxy(32,11);
		cout<<"3: EDIT FOOD ITEMS";
		gotoxy(32,12);
		cout<<"4: TOTAL BILL";
		gotoxy(32,13);
		cout<<"0: QUIT";
		gotoxy(32,14);
		cout<<"Enter Choice : ";
		cin>>ch;

		if (ch == 27)
			return;

		else if (ch == '1')
		{
			food f;
			f.purchase();
		}

		else if (ch == '2')
		{
			food f;
			f.list_of_item();
		}

		else if (ch == '3')
			edit_menu();

		else if (ch == '4')
		{
			account a;
			a.bill_list();
		}

		else if (ch == '0')
			break;
	 }
}

void menu :: edit_menu()
{
	char ch;
	clrscr();

	while (1)
	{
		for (int i=5;i<=21;i++)
		{
			gotoxy(21,i);
			cout<<"                                        ";
		}
		gotoxy(32,6);
		cout<<"EDIT  MENU";
		gotoxy(32,7);
		cout<<"~~~~~~~~~~~~~~~~";
		gotoxy(32,10);
		cout<<"1: ADD RECORD";
		gotoxy(32,12);
		cout<<"2: MODIFY RECORD";
		gotoxy(32,14);
		cout<<"3: DELETE RECORD";
		gotoxy(32,16);
		cout<<"0: EXIT";
		gotoxy(32,19);
		cout<<"Enter Choice : ";
		cin>>ch;

		if(ch == 27)
			return;

		else if (ch == '1')
		{
			food f;
			f.add_item();
			break;
		}

		else if (ch == '2')
		{
			food f;
			f.modify_item();
			break;
		}

		else if (ch == '3')
		{
			food f;
			f.delete_item();
			break;
		}

		else if (ch == '0')
			break;
	}
}
void food :: add_item()
{
	int tcode, valid;
	char ch,  t_itemprice[10];
	tcode = last_code();
	tcode++;
	do
	{
		clrscr();
		gotoxy(71,2);
		cout<<"<0>=Exit";
		gotoxy(27,3);
		cout<<"ADD FOOD ITEM TO THE MENU";
		gotoxy(26,4);
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(5,6);
		cout<<"Item Code  : "<<tcode;
		gotoxy(5,8);
		cout<<"Item Name  : ";
		gotoxy(5,10);
		cout<<"Item Price : ";

		do
		{
			valid = 1;
			gotoxy(1,8);
			clreol();
			gotoxy(1,24);
			clreol();
			gotoxy(1,25);
			clreol();
			gotoxy(3,25);
			cout<<"ENTER FOOD ITEM NAME TO ADD IN THE MENU";
			gotoxy(5,8);
			cout<<"Item Name  : ";
			gets(itemname);
			strupr(itemname);

			if(itemname[0] == '0')
				return;

			if((strlen(itemname) < 1) || (strlen(itemname) > 20))
			{
				valid = 0;
				gotoxy(3,24);
				cout<<"\7 Range = 1..20";
				getch();
			}

		} while(!valid);

		do
		{
			valid = 1;
			gotoxy(1,10);
			clreol();
			gotoxy(1,24);
			clreol();
			gotoxy(1,25);
			clreol();
			gotoxy(3,25);
			cout<<"ENTER FOOD ITEM PRICE TO ADD IN THE MENU";
			gotoxy(5,10);
			cout<<"Item Cost  : ";
			gets(t_itemprice);
			itemprice = atof(t_itemprice);

			if(t_itemprice[0] == '0')
				return;

			if (itemprice < 1 || itemprice > 800)
			{
				valid = 0;
				gotoxy(3,24);
				cout<<"\7 Range = 1..800";
				getch();
			}

		} while(!valid);

		do
		{
			gotoxy(1,15);
			clreol();
			gotoxy(1,24);
			clreol();
			gotoxy(1,25);
			clreol();
			gotoxy(5,15);
			cout<<"Do you want to save this record (y/n) :";
			ch=getche();
			ch = toupper(ch);

			if(ch == '0')
				return;
		} while(ch != 'N' && ch != 'Y');

		if(ch == 'Y')
		{
			itemcode = tcode;
			fstream file;
			file.open("FOOD.DAT",ios::binary |ios::out | ios::app);
			file.write((char *) this, sizeof(food));
			file.close();
			tcode++;
		}

		do
		{
			gotoxy(1,17);
			clreol();
			gotoxy(1,24);
			clreol();
			gotoxy(1,25);
			clreol();
			gotoxy(5,17);
			cout<<"Do you want to add more records (y/n) : ";
			ch=getche();
			ch = toupper(ch);

			if(ch == '0')
				return;
		} while(ch != 'N' && ch != 'Y');

	} while(ch == 'Y');
}

void food :: delete_item()
{
	clrscr();
	char t_code[5], ch;
	int t, tcode;
	gotoxy(3,25);
	cout<<"Press <ENTER> to see the list";
	gotoxy(5,3);
	cout<<"Enter Item Code of the FOOD item to be deleted : ";
	gets(t_code);
	t = atoi(t_code);
	tcode = t;

	if (t_code[0] == '0')
		return;

	if (tcode == 0)
	{
		list_of_item();
		gotoxy(1,25);
		clreol();
		gotoxy(3,25);
		cout<<"Press <ENTER> to Exit";
		gotoxy(5,24);
		cout<<"Enter Item Code of FOOD item to be deleted  ";
		gets(t_code);
		t = atoi(t_code);
		tcode = t;

		if (tcode == 0)
			return;
	}

	clrscr();

	if(!item_found(tcode))
	{
		gotoxy(5,5);
		cout<<"\7Record not found";
		getch();
		return;
	}

	display_record(tcode);

	do
	{
		gotoxy(1,8);
		clreol();
		gotoxy(5,8);
		cout<<"Do you want to delete this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
	} while(ch != 'N' && ch != 'Y');

	if (ch == 'N')
		return;
	delete_record(tcode);
	gotoxy(5,15);
	cout<<"\7Record Deleted";
	getch();
}

void food :: modify_item()
{
	clrscr();
	char t_code[5], ch;
	int t, tcode;
	gotoxy(3,25);
	cout<<"Press <ENTER> to see the list";
	gotoxy(5,3);
	cout<<"Enter Item Code of the item to be Modify : ";
	gets(t_code);
	t = atoi(t_code);
	tcode = t;

	if(t_code[0] == '0')
		return;

	if(tcode == 0)
	{
		list_of_item();
		gotoxy(1,25);
		clreol();
		gotoxy(3,25);
		cout<<"Press <ENTER> to Exit";
		gotoxy(5,24);
		cout<<"Enter Item Code of the item to be modify : ";
		gets(t_code);
		t = atoi(t_code);
		tcode = t;

		if(tcode == 0)
			return;
	}

	clrscr();

	if(!item_found(tcode))
	{
		gotoxy(5,5);
		cout<<"\7Record not found";
		getch();
		return;
	}

	display_record(tcode);

	do
	{
		gotoxy(5,8);
		cout<<"Do you want to Modify this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
	} while(ch != 'N' && ch != 'Y');

	if(ch == 'N')
		return;

	modify_record(tcode);
}

void food :: list_of_item()
{
	clrscr();
	fstream file;
	file.open("FOOD.DAT", ios::binary |ios::in);
	file.seekg(0);
	int row = 6 , found = 0 , pageno = 1;
	gotoxy(30,2);
	cout<<"LIST OF FOOD ITEMS";
	gotoxy(29,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~";
	gotoxy(3,4);
	cout<<"ITEM CODE    ITEM NAME      ITEM PRICE";
	gotoxy(2,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	while (file.read((char *) this, sizeof(food)))
	{

		found = 1;
		gotoxy(5,row);
		cout<<itemcode;
		gotoxy(14,row);
		cout<<itemname;
		gotoxy(37,row);
		cout<<itemprice;

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
			cout<<"LIST OF FOOD ITEMS";
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
	cout<<"Page no. : "<<pageno;
	gotoxy(66,2);
	cout<<"===============";
	gotoxy(1,25);
	cout<<"Press any key to continue...";
	getche();
	file.close();
}

void food :: purchase()
{
	clrscr();
	account a;
	int t_billno, purchased=0;
	t_billno = a.last_billno();
	t_billno++;
	char t_code[5], ch, t_quantity[5];
	int t, tcode, i=0, valid;
	float qty;
	int t_itemcode;
	float t_qty,  t_price;
	char t_itemname[30];
	struct date d;
	int d1, m1, y1;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;

	do
	{
		clrscr();
		gotoxy(3,25);
		cout<<"Press <ENTER> to see the list";
		gotoxy(5,3);
		cout <<"Enter Item Code of the FOOD item to be Purchase : ";
		gets(t_code);
		t = atoi(t_code);
		tcode = t;

		if(t_code[0] == '0')
		{
			if(purchased)
				a.prepare_bill(t_billno);

			return;
		}

		if(tcode == 0)
		{
			list_of_item();
			gotoxy(1,25);
			clreol();
			gotoxy(3,25);
			cout<<"Press <ENTER> to Exit";
			gotoxy(5,24);
			cout<<"Enter Item Code of the FOOD item to be Purchase :";
			gets(t_code);
			t = atoi(t_code);
			tcode = t;

			if(tcode == 0)
			{
				if(purchased)
					a.prepare_bill(t_billno);

				return;
			}
		}

		clrscr();

		if (!item_found(tcode))
		{
			gotoxy(5,5);
			cout<<"\7Item Code not found";
			getch();

			if(purchased)
				a.prepare_bill(t_billno);

			return;
		}

		gotoxy(60,2);
		cout<<"Date:"<<d1<<"/"<<m1<<"/"<<y1;
		display_record(tcode);

		do
		{
			valid = 1;
			gotoxy(1,8);
			clreol();
			gotoxy(1,24);
			clreol();
			gotoxy(1,25);
			clreol();
			gotoxy(3,25);
			cout<<"ENTER AMOUNT TO BE PURCHASE IN NO.";
			gotoxy(5,8);
			cout<<"Number : ";
			gets(t_quantity);
			qty = atoi(t_quantity);

			if(t_quantity[0] == '0')
			{
				if(purchased)
					a.prepare_bill(t_billno);

				return;
			}

			if(qty < 1 || qty > 800)
			{
				valid = 0;
				gotoxy(3,24);
				cout<<"\7 Range = 1..800";
				getch();
			}
		} while(!valid);

		do
		{
			gotoxy(5,10);
			clreol();
			gotoxy(5,10);
			cout<<"Do you want to cancel this purchase (y/n) : ";
			ch = getche();
			ch = toupper(ch);
		} while (ch != 'N' && ch != 'Y');

		if(ch == 'N')
		{
			purchased = 1;
			fstream file;
			file.open("FOOD.DAT",ios::binary| ios::in);
			file.seekg(0,ios::beg);

			while (file.read((char *) this, sizeof(food)))
			{
				if(itemcode == tcode)
				{
					t_itemcode = itemcode;
					strcpy(t_itemname,itemname);

					t_price = itemprice;
					t_qty = qty;
					a.add_bill(t_billno,t_itemcode,t_itemname,t_qty,t_price);
					i++;
					break;
				}
			}

			file.close();
		}

		do
		{
			gotoxy(5,12);
			clreol();
			gotoxy(5,12);
			cout<<"Do you want to purchase more (y/n) : ";
			ch = getche();
			ch = toupper(ch);
		} while(ch != 'N' && ch != 'Y');

	}while (ch == 'Y');

	a.prepare_bill(t_billno);
}

void food :: delete_record(int tcode)
{
	fstream file;
	file.open("FOOD.DAT", ios::binary|ios::in);
	fstream temp;
	temp.open("temp.dat",ios::binary| ios::out);
	file.seekg(0,ios::beg);

	while (!file.eof())
	{
		file.read((char *) this, sizeof(food));

		if(file.eof())
			break;

		if(itemcode != tcode)
			temp.write((char *) this, sizeof(food));
	}

	file.close();
	temp.close();
	file.open("FOOD.DAT", ios::binary |ios::out);
	temp.open("temp.dat", ios::binary |ios::in);
	temp.seekg(0,ios::beg);

	while(!temp.eof())
	{
		temp.read((char *) this, sizeof(food));

		if(temp.eof())
			break;

		file.write((char *) this, sizeof(food));
	}

	file.close();
	temp.close();
}

void food :: modify_record(int tcode)
{
	int recno;
	recno = recordno(tcode);
	int valid, t_code;
	char ch,  t_itemprice[10], t_itemcode[5];
	gotoxy(71,2);
	cout<<itemcode<<itemname<<itemprice;
	t_code=itemcode;
	cout <<"<0>=Exit";
	gotoxy(5,12);
	cout <<"Item Code  : ";
	gotoxy(5,14);
	cout <<"Item Name  : ";
	gotoxy(5,16);


	cout <<"Item Price : ";

	do
	{
		gotoxy(20,12);
		clreol();
		cout<<"Change (y/n) : ";
		ch = getche();
		ch = toupper(ch);

		if (ch == '0')
			return;

	} while(ch != 'N' && ch != 'Y');

	valid = 0;

	while (ch == 'Y' && !valid)
	{
		valid = 1;
		gotoxy(1,12);
		clreol();
		gotoxy(1,24);
		clreol();
		gotoxy(1,25);
		clreol();
		gotoxy(3,25);
		cout<<"ENTER ITEM CODE TO ADD IN THE MENU";
		gotoxy(5,12);
		cout<<"Item Code  : ";
		gets(t_itemcode);
		t_code = atoi(t_itemcode);

		if(t_code == 0)
			return;

		if(item_found(t_code) && t_code != tcode)
		{
			valid = 0;
			gotoxy(3,24);
			cout<<"\7 CODE ALREADY GIVEN";
			getch();
		}
	}

	do
	{
		gotoxy(20,14);
		clreol();
		cout<<"Change (y/n) : ";
		ch = getche();
		ch = toupper(ch);

		if(ch == '0')
			return;
	} while(ch != 'N' && ch != 'Y');

	valid = 0;

	while (ch == 'Y' && !valid)
	{
		valid = 1;
		gotoxy(1,14);
		clreol();
		gotoxy(1,24);
		clreol();
		gotoxy(1,25);
		clreol();
		gotoxy(3,25);
		cout<<"ENTER ITEM NAME TO ADD IN THE MENU";
		gotoxy(5,14);
		cout<<"Item Name  : ";
		gets(itemname);
		strupr(itemname);

		if(itemname[0] == '0')
			return;

		if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
		{
			valid = 0;
			gotoxy(3,24);
			cout<<"\7 Range = 1..20";
			getch();
		}
	}

	do
	{
		gotoxy(20,16);
		clreol();
		cout<<"Change (y/n) : ";
		ch = getche();
		ch = toupper(ch);

		if (ch == '0')
			return;
	} while (ch != 'N' && ch != 'Y');

	valid = 0;


	while (ch == 'Y' && !valid)
	{
		valid = 1;
		gotoxy(1,16);
		clreol();
		gotoxy(1,24);
		clreol();
		gotoxy(1,25);
		clreol();
		gotoxy(3,25);
		cout<<"ENTER ITEM PRICE TO ADD IN THE MENU";
		gotoxy(5,16);
		cout<<"Item Price  : ";
		gets(t_itemprice);
		itemprice = atof(t_itemprice);

		if(t_itemprice[0] == '0')
			return;

		if(itemprice < 1 || itemprice > 800)
		{
			valid = 0;
			gotoxy(3,24);
			cout<<"\7 Range = 1..800";
			getch();
		}
	}

	do
	{
		gotoxy(1,21);
		clreol();
		gotoxy(1,24);
		clreol();
		gotoxy(1,25);
		clreol();
		gotoxy(5,21);
		cout<<"Do you want to save this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);

		if (ch == '0')
			return;
	} while(ch != 'N' && ch != 'Y');

	if (ch == 'N')
		return;

	itemcode = t_code;
	cout<<itemcode;
	cout<<"\n" <<itemname;
	cout<<itemprice;
	getch();
	fstream file;
	file.open("FOOD.DAT", ios::binary |ios::out | ios::ate);
	int location;
	location = (recno-1) * sizeof(food);
	file.seekp(location);
	file.write((char *) this, sizeof(food));
	file.close();
	sort();
	clrscr();
	gotoxy(5,15);
	cout<<"\7Record Modified";
	getch();
}

void food :: display_record(int tcode)
{
	fstream file;
	file.open("FOOD.DAT",ios::binary| ios::in);
	file.seekg(0,ios::beg);

	while(file.read((char *) this, sizeof(food)))
	{
		if(itemcode == tcode)
		{
			gotoxy(5,3);
			cout<<"Item Code  : "<<itemcode;
			gotoxy(5,4);
			cout<<"Item Name  : "<<itemname;
			gotoxy(5,5);
			cout<<"Item Price  : "<<itemprice;
			break;
		}
	}

	file.close();
}
void food :: sort()
{
	int i=0,j;
	food arr[100];
	food temp;
	fstream file;
	file.open("FOOD.DAT", ios::binary|ios::in);
	file.seekg(0,ios::beg);

	while(file.read((char *) &arr[i], sizeof(food)))
		i++;

	int size;
	size = i;
	file.close();
	for(i=1; i<size; i++)
		for (j=0; j<size-i; j++)
		{
			if (arr[j].itemcode > arr[j+1].itemcode)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

	file.open("FOOD.DAT",ios::binary| ios::out);

	for (i=0; i<size; i++)
		file.write((char *) &arr[i], sizeof(food));

	file.close();
}
int food :: last_code()
{
	fstream file;
	file.open("FOOD.DAT", ios::binary|ios::in);
	file.seekg(0,ios::beg);
	int t=0;

	while (file.read((char *) this, sizeof(food)))
		t = itemcode;

	file.close();
	return t;
}
int food :: item_found(int tcode)
{
	fstream file;
	file.open("FOOD.DAT", ios::binary|ios::in);
	file.seekg(0,ios::beg);
	int found=0;

	while (file.read((char *) this, sizeof(food)))
	{
		if (itemcode == tcode)
		{
			found++;
			break;
		}
	}

	file.close();
	return found;
}
int food :: recordno(int tcode)
{
	fstream file;
	file.open("FOOD.DAT", ios::binary |ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	while (file.read((char *) this, sizeof(food)))
	{
		found++;

		if (itemcode == tcode)
			break;
	}

	file.close();
	return found;
}
void account :: bill_list(void)
{
	clrscr();
	fstream file;
	file.open("BILL.DAT", ios::binary|ios::in);
	file.seekg(0);
	int row=5, found=0, pageno=1, prev_billno=0, flag=0;
	float total=0.0, total_bill=0.0;
	gotoxy(30,2);
	cout<<"LIST OF BILLS";
	gotoxy(29,3);
	cout<<"~~~~~~~~~~~~~~~";
	gotoxy(3,4);
	cout<<"Billno. Date       Item Code Item name              Price   NO.   Total" ;
	gotoxy(3,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;

	while(file.read((char *) this, sizeof(account)))
	{
		row++;
		found = 1;

		if(prev_billno != billno)
		{
			if(flag)
			{
				gotoxy(52,row);
				cout<<"TOTAL BILL: Rs."<<total_bill<<"/=";
				total_bill = 0.0;
				row++;
			}

			gotoxy(4,row);
			cout <<billno;
		}

		flag = 1;
		gotoxy(11,row);
		cout<<dd<<"/"<<mm<<"/"<<yy;
		gotoxy(24,row);
		cout<<code;
		gotoxy(32,row);
		cout<<name;
		gotoxy(52,row);
		cout<<price;
		gotoxy(59,row);
		cout<<quantity;
		total = quantity * price;
		gotoxy(67,row);
		cout<<total;
		total_bill = total_bill + total;

		if(row >= 23)
		{
			row = 5;
			gotoxy(66,1);
			cout<<"Page no. : "<<pageno;
			pageno++;
			gotoxy(1,25);
			cout<<"Press any key to continue...";
			getche();
			clrscr();
			gotoxy(30,2);
			cout<<"LIST OF BILLS";
			gotoxy(3,4);
			cout<<"Billno. Date       Item Code Item name              Price   NO.   Total";
			gotoxy(3,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}

		prev_billno = billno;
	}

	row++;
	gotoxy(52,row);
	cout<<"TOTAL BILL: Rs."<<total_bill<<"/=";

	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}

	gotoxy(66,1);
	cout<<"Page no. : "<<pageno;
	gotoxy(1,25);
	cout<<"Press any key to continue...";
	getche();
	file.close();
}
void account :: prepare_bill(int t_billno)
{
	clrscr();
	struct date d;
	int d1, m1, y1;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	float total=0.0, total_bill=0.0;
	gotoxy(33,3);
	cout<<"CUSTOMER BILL";
	gotoxy(32,4);
	cout<<"~~~~~~~~~~~~~~~";
	gotoxy(55,5);
	cout<<"Date:"<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(8,7);
	cout<<"ITEMS PURCHASED";
	gotoxy(8,8);
	cout<<"~~~~~~~~~~~~~~~";
	gotoxy(8,9);
	cout<<"Item code Item name              Price    NO.    Total";
	gotoxy(8,10);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	int row=11;
	fstream file;
	file.open("BILL.DAT", ios::binary |ios::in);
	file.seekg(0);
	while (file.read((char *) this, sizeof(account)))
	{
		if (billno == t_billno)
		{
			gotoxy(8,5);
			cout<<"BILL NO. # "<<billno;
			gotoxy(8,6);
			cout<<"~~~~~~~~~~~~~~~";
			gotoxy(10,row);
			cout<<code;
			gotoxy(18,row);
			cout<<name;
			gotoxy(39,row);
			cout<<price;
			gotoxy(47,row);
			cout<<quantity;
			total = quantity * price;
			gotoxy(57,row);
			cout<<total;
			total_bill = total_bill + total;
			row++;
		}
	}

	file.close();
	gotoxy(39,row+1);
	cout<<"TOTAL BILL: Rs."<<total_bill<<" /=";
	getch();
}
int account :: last_billno()
{
	fstream file;
	file.open("BILL.DAT",ios::binary | ios::in);
	file.seekg(0,ios::beg);
	int t=0;

	while (file.read((char *) this, sizeof(account)))
		t = billno;

	file.close();
	return t;
}
void account :: add_bill(int t_billno, int t_itemcode, char t_itemname[30], float t_qty,  float t_price)
{
	struct date d;
	int d1, m1, y1;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	dd = d1;
	mm = m1;
	yy = y1;
	code = t_itemcode;
	strcpy(name,t_itemname);

	price = t_price;
	quantity = t_qty;
	billno = t_billno;
	fstream file;
	file.open("BILL.DAT", ios::binary|ios::out | ios::  app );
	file.write((char *) this, sizeof(account));
	file.close();
}
void ouuty()
{
	clrscr();
	int i, j;
	for (i=0; i<1; i++)
	{
		gotoxy(12,7);
		cout<<"  FAST  FOOD  OUTLET   MANAGEMENT  SYSTEM";
		gotoxy(11,8);
		cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(24,12);
		cout<<"   BY: ANJANA SHAH"<<"\n";
      cout<<"\t\t\t\tXII-A"<<"\n";
		getchar();
	}

}

void main()
{
	ouuty();
	clrscr();
	menu m;
	m.main_menu();
}

