#include<stdio.h>
#include<stdlib.h>
typedef struct mynode
               {
                   int constt;
                   int exp;
                   struct mynode *next;
               }node;
node* emptylist();
void insert(node *h,int constt,int exp);
void insertb(node *h,int constt,int exp);
node* add(node *h1,node *h2);
int main()
{
    char per;
    int choice;
    node *head1,*head2,*final,*t;
    head1=emptylist();
    head2=emptylist();
    final=emptylist();
    insertb(head1,3,12);
    insert(head1,8,8);
    insert(head1,-22,4);
    insert(head1,3,1);
    insert(head1,-7,0);
    insertb(head2,7,14);
    insert(head2,-10,9);
    insert(head2,-8,8);
    insert(head2,6,5);
    insert(head2,-9,1);
    do{
    printf("Enter 1 for polynomial addition\n2 for multiplication\n3 for display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:final=add(head1,head2);
               break;
        case 3:
               printf("format Constt x exp\n");
               for(t=head1->next;t!=NULL;t=t->next)
               {
                   printf("%dx%d ",t->constt,t->exp);
               }
               printf("\n");
               for(t=head2->next;t!=NULL;t=t->next)
               {
                   printf("%dx%d ",t->constt,t->exp);
               }
               printf("\n");
               for(t=final->next;t!=NULL;t=t->next)
               {
                   printf("%dx%d ",t->constt,t->exp);
               }
               break;
    }
    printf("Would u like to continue press y for yes ");
    scanf(" %c",&per);
    }
    while(per=='y');

}
node* emptylist()
{
    node *h;
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    return h;
}
void insertb(node *h,int constt,int exp)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    p->constt=constt;
    p->exp=exp;
    p->next=h->next;
    h->next=p;
}
void insert(node *h,int constt,int exp)
{
    node *p,*t;
    p=(node *)malloc(sizeof(node));
    p->constt=constt;
    p->exp=exp;
    t=h->next;
    while(t->next!=NULL)
        t=t->next;
    p->next=t->next;
    t->next=p;
}
