#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;
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
 int ch,n;
 do
  {
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter data\n");
  scanf("%d",&n);
  temp->data=n;
  if(head==NULL)
    {
    temp->next=temp;
    head=temp;
    }
    else
    {
    struct node *ptr;
    ptr=head;
    while(ptr->next!=head)
    ptr=ptr->next;
    ptr->next=temp;
    temp->next=head;
    }
    printf("do you want to enter more data\nif yes\press 1");
    scanf("%d",&ch);
  }while(ch==1);
}

void display()
{
  struct node *ptr;
  ptr=head;
  do
  {
  printf("%d\t",ptr->data);
  ptr=ptr->next;
  }while(ptr->next!=head);
}