struct eltype{
	char *english;
	char *tamil;
	char *hindi;
};

typedef struct eltype elementtype;

struct avlnode{
	elementtype *element;
	struct avlnode *left;
	struct avlnode *right;
	int height;
};

typedef struct avlnode Tree;
void inorder(Tree *t){
	if(t != NULL){
		inorder(t->left);
		printf("%s\t%s\t%s\n",t->element->english,t->element->tamil,t->element->hindi);
		inorder(t->right);
	} 
}

int max(int a , int b){
	if(a > b)
		return a;
	return b;
}

static int height (Tree *p){
	if(p==NULL)
		return -1;
	else
		return p->height;
}

Tree *find(char x[],Tree *t){
    if (t==NULL)
        return NULL;
    if (strcmp(x,t->element->english)<0){
        return find(x, t->left);
	}
    else if (strcmp(x,t->element->english)>0){
        return find(x,t->right);
	}
    else{
		if(strcmp(x,t->element->english)==0)
        	return t;
		else
			return NULL;
	}
}

static Tree *singlerotatewithleft(Tree *k2){
	Tree *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),k2-> height)+1;
	return k1;
}

static Tree *singlerotatewithright(Tree *k2){
	Tree *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=max(height(k2->right),height(k2->left))+1;
	k1->height=max(height(k1->right),k2-> height)+1;
	return k1;
}

static Tree *doublerotatewithleft(Tree *k3){ //rotate between k1 and k2
	k3->left=singlerotatewithright(k3->left);
	//rotate between k3 and k2
	return singlerotatewithleft(k3);
}

static Tree *doublerotatewithright(Tree *k3){ //rotate between k1 and k2
	k3->right=singlerotatewithleft(k3->right);
	//rotate between k3 and k2
	return singlerotatewithright(k3);
}


Tree *insert(elementtype *x, Tree *t){
	//printf("%s %s %s\n",x->english,x->tamil,x->hindi);
    //printf("%s\t%s\t%s\n",t->element->english,t->element->tamil,t->element->hindi);
    if(t==NULL){
		t=(Tree *)malloc(sizeof(Tree));
		if(t==NULL)
			printf("Out of Space");
		else{
			t->element = (elementtype *)malloc(sizeof(elementtype));
			t->element->english = (char *)malloc(strlen(x->english)*sizeof(char));
			t->element->hindi = (char *)malloc(strlen(x->hindi)*sizeof(char));
			t->element->tamil = (char *)malloc(strlen(x->tamil)*sizeof(char));
			//t->element=x;
			strcpy(t->element->english,x->english);
			strcpy(t->element->hindi,x->hindi);
			strcpy(t->element->tamil,x->tamil);
			t->height=0;
			t->left=t->right=NULL;
            //printf("1\n");
			inorder(t);
		}
	}
	else if(strcmp(x->english,t->element->english)<0){
		//printf("2\n");
        t->left=insert(x,t->left);
		if(height(t->left) - height(t->right) == 2){
			if(strcmp(x->english,t->left->element->english)<0){
				printf("---------------------\nL Rotation\n---------------------\n");
				t=singlerotatewithleft(t);
			}
			else{
				printf("---------------------\nRL Rotation\n---------------------\n");
				t=doublerotatewithleft(t);
			}
		}
	}
	else if(strcmp(x->english,t->element->english)>0){
        //printf("3\n");
		t->right=insert(x,t->right);
		if(height(t->right) - height(t->left) == 2){
			if(strcmp(x->english,t->right->element->english)>0){
				printf("---------------------\nR Rotation\n---------------------\n");
				t=singlerotatewithright(t);
			}
			else{
				printf("---------------------\nLR Rotation\n---------------------\n");
				t=doublerotatewithright(t);
			}
		}
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}