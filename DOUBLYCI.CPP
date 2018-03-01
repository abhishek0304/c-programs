#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
int data;
struct node *next;
struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void create();
void display();
void main()
{
clrscr();
create();
display();
getch();
}

void create()
{
int ch;
struct node *ptr,*temp;
do
{
  printf("enter data:");
scanf("%d",&temp->data);
  if(head==NULL)
  {
  temp=(struct node*)malloc(sizeof(struct node));
  temp->prev=tail;
  temp->next=head;
  head=temp;
  }
  else
  {
  temp=(struct node*)malloc(sizeof(struct node));
  ptr=head;
  while(ptr->next!=head)
    {
    ptr=ptr->next;
    }
    temp->prev=ptr->next;
    ptr->next=temp->prev;
    temp->next=head->prev;
    head->prev=temp->next;
    tail=temp;
  }
  printf("Do you want to enter more data??\n If yes then press 1");
  scanf("%d",&ch);
}while(ch==1);
}


void display()
{
struct node *ptr;
ptr=head;
while(ptr!=head)
  {
  printf("%d\t",ptr->data);
  ptr=ptr->next;
  }
  printf("%d",ptr->data);
}