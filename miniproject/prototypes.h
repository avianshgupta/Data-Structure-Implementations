struct mystack
{
    int sol;
    struct mystack *next;
}*top=NULL;
void push(int data);
void ansstack();
typedef struct mynode
{
    int data;
    struct mynode *next;
}node;
typedef struct myquque
{
    int data;
    struct myqueue *next;
}queue;
typedef struct mytree
{
	int data;
	struct mytree *left;
	struct mytree *right;
}tree;
queue *qf1=NULL,*qr1=NULL;
tree* newnode(int data);
void enqueue(int data);
node* emptylist();
void insert(node *h,int data);
void insertb(node *h,int data);
void pop();
float fact(int n);
FILE *quiz1,*quiz2,*quiz3,*quiz4,*sol1;