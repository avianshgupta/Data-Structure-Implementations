void push(int data)
{
   struct mystack *temp;
   temp=(struct mystack *)malloc(sizeof(struct mystack));
   if(temp==NULL)
       printf("Out of space\n");
   temp->sol=data;
   temp->next=top;
   top=temp;
}
void ansstack(){
    sol1 = fopen("sol1.txt","r");
    if(sol1 == NULL){
        printf("ERROR...Cannot open sol1.txt...\n");
        exit(-1);
    }
    int ch1;
    do{
        fseek(sol1,-1,SEEK_CUR);
        while((ch1 = getc(sol1))!='\n'){
            push(ch1);
            fseek(sol1,1,SEEK_CUR);
        }
    }while((ch1 = getc(sol1)) != EOF);
}

void pop()
{
   if(top==NULL)
   {
       printf("Stack is Empty\n");
   }
   else
   {
       struct mystack *temp=top;
       top=temp->next;
       free(temp);
   }
}
node* emptylist()
{
    node *h;
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    return h;
}
void insertb(node *h,int data)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->next=h->next;
    h->next=p;
}
void insert(node *h,int data)
{
    node *p,*t;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    t=h->next;
    while(t->next!=NULL)
        t=t->next;
    p->next=t->next;
    t->next=p;
}
void enqueue(int data)
{
    queue *node;
    node=(queue *)malloc(sizeof(queue));
    node->data=data;
    node->next=NULL;
    if(qf1==NULL)
      qf1=qr1=node;
    else
    {
      qr1->next=node;
      qr1=node;
    }
}
float fact(int n)
{
  long long num=1;
  for(int count=1;count<=n;count++)
    num=num*count;
  return num;
}
tree* newnode(int data) 
{ 
  tree* node = (tree*)malloc(sizeof(tree));  
  node->data = data;  
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 