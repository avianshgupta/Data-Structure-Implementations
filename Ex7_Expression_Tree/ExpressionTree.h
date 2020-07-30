struct ExpTree{
    int data;
    struct ExpTree *left, *right;
};

typedef struct ExpTree Tree;

struct TreeStack{
    Tree *data;
    struct TreeStack *next;
};

typedef struct TreeStack stack;
stack *st;

void pushNode(Tree *value){
    stack *newNode;
    newNode = (stack*)malloc(sizeof(stack));
    newNode->data = (Tree *)malloc(sizeof(Tree));
    newNode->data = value;
    if(st == NULL)
        newNode->next = NULL;
    else
        newNode->next = st;
    st = newNode;
}

void popNode(){
    if(st == NULL){
        printf("\nStack is Empty!!!\n");
    }
    else{
        stack *temp = st;
        st = temp->next;
        free(temp);
    }
}

Tree *topNode(){
    if(st == NULL)
        printf("\nStack is Empty!!!\n");
    else
        return st->data;
}

int isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
} 

Tree *newNode(int v){
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right = NULL;
    temp->data = v;
    return temp;
}

Tree* constructTree(char postfix[]){
    Tree *t, *t1, *t2;
    for (int i=0; i<strlen(postfix); i++){
        if (!isOperator(postfix[i])){
            t = newNode(postfix[i]);
            //printf("%c\n",t->data);
            pushNode(t);
            //printf("st=%c\n",st->data->data);
        } 
        else{ // operator
            t = newNode(postfix[i]);
            t1 = topNode(); // Store top
            popNode(); // Remove top
            t2 = topNode();
            popNode();
            t->right = t1; // make them children
            t->left = t2;
            pushNode(t); // Add this subexpression to stack
        }
    }
    t = topNode();
    popNode();
    return t; 
} 

void preorder(Tree* t){
    if(t!=NULL){
        printf("%c",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(Tree* t){
    if(t!=NULL){
        inorder(t->left);
        printf("%c",t->data);
        inorder(t->right);
    }
}

void postorder(Tree* t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%c",t->data);
    }
}