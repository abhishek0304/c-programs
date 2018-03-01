#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
void reverse()
{
int i,j,t,count=0;
char st[90];
cout<<"Enter string : ";
gets(st);
for(i=0;st[i]!=0;i++)
count++;
if(count%2==0)
{
for(i=0,j=count-1;i<count/2;i++,j--)
{
t=st[i];
st[i]=st[j];
st[j]=t;
}
}
else
{
for(i=0,j=count-1;i<(count/2)+1;i++,j--)
{
t=st[i];
st[i]=st[j];
st[j]=t;
}
}
cout<<st<<"\n";
}

void copystring()
{
int i;
char st1[90],st2[90];
cout<<"Enter string(1st) to be copied : ";
gets(st1);
for(i=0;st2[i]!='\0';i++)
{
st2[i]=' ';
}
cout<<"Empty(2nd) string is : "<<st2<<"\n";
for(i=0;st1[i]!='\0';i++)
{
st2[i]=st1[i];
}
st2[i]='\0';
cout<<"Now string(2nd) is : "<<st2<<"\n";
}

void concatenate()
{
char s1[30],s2[30],s3[60];
int i,j;
cout<<"Enter first string : ";
gets(s1);
cout<<"Enter second string :";
gets(s2);
for(i=0;s1[i]!='\0';i++)
{
s3[i]=s1[i];
}
for(j=0;s2[j]!='\0';j++)
{
s3[i+j]=s2[j];
}
s3[i+j]='\0';
cout<<"The concatenated string is: "<<s3<<"\n";
}

void countalpha()
{
clrscr();
int i,count=0;
char st[100];
cout<<"Enter string : ";
gets(st);
for(i=0;st[i]!='\0';i++)
{
if((st[i]>='A'&& st[i]<='Z') || (st[i]>='a'&& st[i]<='z'))
count++;
}
cout<<"No. of alphabets in string : "<<count<<"\n";
}
void main()
{
clrscr();
int n;
char ans='y';
cout<<"1.Reverse a string "<<"\n";
cout<<"2.Copy the string into an empty string "<<"\n";
cout<<"3.Concatenate two strings"<<"\n";
cout<<"4.Count the no. of alphabets in a string "<<"\n";
while(ans=='y')
{
cout<<"Enter your choice to perform the following functions on a string without using language supported built-in string functions : ";
cin>>n;
switch(n)
{
case 1:
	reverse();
	break;
case 2: copystring();
	break;
case 3: concatenate();
	break;
case 4: countalpha();
	break;
default: cout<<"Invalid choice";
}
cout<<"Do you want to continue(y/n) ? : ";
cin>>ans;
}
cout<<"Exiting...";
delay(1000);
exit(0);
getch();
}