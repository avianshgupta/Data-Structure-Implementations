typedef struct myquque{
    char jno[3];
    int bursttime;
    struct myqueue *next;
}queue;

queue *qf1=NULL,*qr1=NULL,*qf2=NULL,*qr2=NULL;

void enqueue(int wt1,int wt2,char jno[],int bt){
    queue *node;
    node=(queue *)malloc(sizeof(queue));
    strcpy(node->jno,jno);
    node->bursttime=bt;
    node->next=NULL;
    if(wt1<=wt2){
        if(qf1==NULL)
            qf1=qr1=node;
        else{
            qr1->next=node;
            qr1=node;
        }
    }
    else{
        if(qf2==NULL)
            qf2=qr2=node;
        else{
            qr2->next=node;
            qr2=node;
        }
    }
}

void display(){
    if(qf1==NULL)
        printf("Queue 1 is empty\n");
    else{
        queue *temp=qf1;
        printf("\t\tQueue 1(Job No, Burst Time)\n");
        while(temp!=NULL){
            printf("(%s, %d)\n",temp->jno,temp->bursttime);
            temp=temp->next;
        }

    }
    printf("\n------------------------------------------------------\n");
    if(qf2==NULL)
        printf("Queue 2 is empty\n");
    else{
        queue *temp=qf2;
        printf("\t\tQueue 2(Job No, Burst Time)\n");
        while(temp!=NULL){
            printf("(%s, %d)\n",temp->jno,temp->bursttime);
            temp=temp->next;
        }
    }
    printf("\n------------------------------------------------------\n");
}