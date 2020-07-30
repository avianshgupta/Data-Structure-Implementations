struct Stack{
    int data; 
    struct Stack *next;
};

typedef struct Stack Node;

Node *top = NULL;

void push(char value){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if(top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("\nStack is Empty!!!\n");
    }
    else{
        Node *temp = top;
        //printf("\nDeleted element: %d", temp->data);
        top = temp->next;
        free(temp);
    }
}
char peek(){
if(top == NULL)
    printf("\nStack is Empty!!!\n");
else
    return top->data;
}

void display(){
    if(top == NULL){
        printf("\nStack is Empty!!!\n");
    }
    else{
        Node *temp = top;
        while(temp->next != NULL){
            printf("%c--->",temp->data);
            temp = temp -> next;
        }
        printf("%c--->NULL",temp->data);
    }
}

void infixTopostfix(char infix[],char *postfix){
    int len = strlen(infix);
    int ind=0;
    for(int i = 0 ; i < len ; i++){
        if(isdigit(infix[i]) || isalpha(infix[i])){
            postfix[ind]=infix[i];
            ind++;
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]=='/' || infix[i]=='*' || infix[i]=='+' || infix[i]=='-'){
            if((top != NULL) && ((top->data=='/' && infix[i]=='/') || (top->data=='*' && infix[i]=='*') || (top->data=='/' && infix[i]=='*') || (top->data=='*' && infix[i]=='/') || (top->data=='+' && infix[i]=='+') || (top->data=='-' && infix[i]=='-') || (top->data=='-' && infix[i]=='+') || (top->data=='+' && infix[i]=='-') || (top->data=='/' && infix[i]=='+') || (top->data=='/' && infix[i]=='-') || (top->data=='*' && infix[i]=='+') || (top->data=='*' && infix[i]=='-'))){
                do{
                    postfix[ind] = top->data;
                    ind++;
                    pop();
                }while((top != NULL) && (top->data!='(' || isdigit(infix[i])  || isalpha(infix[i])));
                push(infix[i]);
            }
            else if((top != NULL) && ((top->data=='+' && infix[i]=='/') || (top->data=='+' && infix[i]=='*') || (top->data=='-' && infix[i]=='/') || (top->data=='-' && infix[i]=='*'))){
                push(infix[i]);
            }
            else{
                push(infix[i]);
            }
        }
        else if(infix[i]==')'){
            do{
                postfix[ind] = top->data;
                ind++;
                pop();
            }while(top != NULL && top->data != '(');
            pop();
        }
        /*display();
        printf("\n");*/
    }
    while(top != NULL){
        postfix[ind] = top->data;
        ind++;
        pop();
    }
}
int postfixEvaluation(char postfix[]){
    int ind=0;
    while(postfix[ind] != '\0'){
        if(isdigit(postfix[ind])){
            push(postfix[ind] - '0');
            ind++;
            //printf("i1\n");
        }
        else{
            int rho = top->data;
            pop();
            int lho = top->data;
            pop();
            //printf("%d %d %c\n",lho,rho,postfix[ind]);
            switch(postfix[ind]){
                case '+': push(lho + rho);
                          break;
                case '-': push(lho - rho);
                          break;
                case '/': push(lho / rho);
                          break;
                case '*': push(lho * rho);
                          break;
            }
            ind++;
            //printf("i2\n");
        }
        //printf("tos=%d\n",top->data);
    }
    return top->data;
}

bool balanced_parenthesis(char exp[]){
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]== '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if((peek() =='(' && exp[i] == ')') || (peek() =='[' && exp[i] == ']') || (peek() =='{' && exp[i] == '}'))
                pop();
            else
                return false;
        }
    }
    if(top == NULL)
        return true;
    else
        return false;
}