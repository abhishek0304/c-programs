#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
struct node *prev;
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
 { int ch;

do
{ struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter data");
  scanf("%d",&temp->data);

 if(head==NULL)
    {


    temp->prev=NULL;
    temp->next=NULL;
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
      temp->prev=ptr;
      temp->next=NULL;





    }
printf("do you want to enter more data\\n if yes press 1");
scanf("%d",&ch);

}while(ch==1);
}


void display()
{
struct node *ptr;

ptr=head;
while(ptr!=NULL)
 { printf("\t%d ",ptr->data);
   ptr=ptr->next;
 }
}
