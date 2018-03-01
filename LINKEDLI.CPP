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
void insertbeg();
void main()
{
clrscr();
create();
display();
insertbeg();
display();
getch();
}

void create()
 { int ch;
 struct node *temp;
do
{
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter data");
  scanf("%d",&temp->data);
  temp->next=NULL;
 if(head==NULL)
    {
    head=temp;
    }
 else
    {
    struct node *ptr;
    ptr=head;
    while(ptr->next!=NULL)
      {
      ptr=ptr->next;
      }
      ptr->next=temp;

    }
printf("do you want to enter more data\\n if yes press 1");
scanf("%d",&ch);

}while(ch==1);
}


void display()
{
struct node *ptr;
if (head==NULL)
{
printf("list is empty");
}
else
{
ptr=head;
while(ptr!=NULL)
 { printf("%d ",ptr->data);
   ptr=ptr->next;
 }
}
}


void insertbeg()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",temp->data);
temp->next=head;
head=temp;
}



