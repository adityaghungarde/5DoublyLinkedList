#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
  int prn,marks;
  char name[20];
  struct node *prev,*next;

};

struct node* inrec(struct node * head)
{ 
int stud;
char naw[20];
struct node *temp,*q;
q=head;

  printf("enter prn_no :");
  scanf("%d",&head->prn);
  printf("enter name :");
  scanf("%s",naw);
  strcpy(head->name,naw);
  printf("enter IE_MARKS :");
  scanf("%d",&head->marks);
head->prev=NULL;
head->next=NULL;
printf("for how many students u have to enter the data\n");
scanf("%d",&stud);
printf("enter the data:\n");
for(int i=0;i<stud;i++)
{
  temp=(struct node *)malloc(sizeof(struct node));
  printf("enter prn_no :");
  scanf("%d",&temp->prn);
  printf("enter name :");
  scanf("%s",temp->name);
  printf("enter IE_MARKS :");
  scanf("%d",&temp->marks);

  temp->next=NULL;
  temp->prev=head;
  head->next=temp;
  head=head->next;
}
return q;
  }

void display(struct node *head)
{ struct node *p;
p=head;
   while(p!=NULL)
  {
    printf("prn_no:%d\n",p->prn);
    printf("name:%s\n",p->name);
    printf("IE_MARKS:%d\n\n\n",p->marks);
    p=p->next;
  }

}
void del(struct node *head)
{ int po;
printf("enter prn number to delete the record\n");
scanf("%d",&po);


struct node *p,*q;
p=head;
q=head->next;





while(p->prn!=po)
{
  p=p->next;
  q=q->next;
}
p->prev->next=p->next;
q->prev=p->prev;
free(p);

}
void dels(struct node *head)
{
  struct node *p=head;
  head=head->next;
  //head->next->prev=NULL;
  head->prev=NULL;
  free(p);
  printf("deleted succesfully\n");
}
void dell(struct node *head)
{
  struct node *p=head;
  while(p!=NULL&&p->next!=NULL)
  {
    p=p->next;

  }
  p->prev->next=NULL;
  free(p);

}

int main(void) {
  int a;
  struct node *head;
  head=(struct node *)malloc(sizeof(struct node));

 
do
{
  printf("1)insert a record\n2)delete a prn no between first and last \n3)delete a prn no present at starting\n4)display list\n5)exit\n6)deleting a prn no at end\n");
  printf("\nenter ur choice \n");
  scanf("%d",&a);
  switch(a)
  {
    case 1:
    head=inrec(head);
    break;
    case 2:
    del(head);
    break;
    case 3:
    dels(head);
    break;
    case 4:
    display(head);
    break;
    case 6:
    dell(head);
    break;
   
    


  }

}while(a!=5);

}
