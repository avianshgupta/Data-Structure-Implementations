#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SearchTree{
	char element[20];
	struct SearchTree *left,*right;
};

typedef struct SearchTree Tree;

void inorder(Tree *t){
	if(t != NULL){
		inorder(t->left);
		printf("%s\n",t->element);
		inorder(t->right);
	} 
}


Tree *findmin(Tree *t){
	if(t==NULL)
		return NULL;
	else if(t->left==NULL)
		return t;
	else
		return findmin(t->left);
}
Tree *find(char x[],Tree *t){
    if (t==NULL)
        return NULL;
    if (strcmp(x,t->element)<0)
        return find(x, t->left);
    else if (strcmp(x,t->element)>0)
        return find(x,t->right);
    else
        return t;
}

int findLevel(char x[],Tree *t){
    static int level = 0;
    if (t==NULL)
        return -1;
    if (strcmp(x,t->element)<0){
        level++;
        return findLevel(x, t->left);
    }
    else if (strcmp(x,t->element)>0){
        level++;
        return findLevel(x,t->right);
    }
    else{
        return level;
    }
}

void findGrandparent(char name[],Tree *t){
    int level = findLevel(name,t);
    if(level == 0 || level == 1){
        printf("No grandparent");
        return;
    }
    //printf("l = %d\n",level);
    int i=0;
    while(i != (level - 2)){
        if(strcmp(name,t->element)<0){
            i++;
            //printf("i=%d\n",i);
            t = t->left;
        }
        else if(strcmp(name,t->element)>0){
            i++;
            //printf("i=%d\n",i);
            t = t->right;
        }
    }
    printf("%s\n",t->element);
}
void findSibling(char name[],Tree *t){
    int level = findLevel(name,t);
    if(level == 0){
        printf("No Sibling");
        return;
    }
    int i = 0;
    while(i != (level - 1)){
        if(strcmp(name,t->element)<0){
            i++;
            t = t->left;
        }
        else if(strcmp(name,t->element)>0){
            i++;
            t = t->right;
        }
    }
    if(t->left->element==NULL || t->right->element==NULL){
        printf("No Sibling");
        return;
    }
    (strcmp(name,t->left->element)==0)?printf("%s\n",t->right->element):printf("%s\n",t->left->element);
}

int findGrandChildren(char name[],Tree *t,char *gchild[]){
    Tree *tmp = t;
    tmp = find(name,tmp);
    int ind = 0;
    if(tmp->left != NULL){
        if(tmp->left->left != NULL){
            gchild[ind] = (char *)malloc(strlen(tmp->left->left->element)*sizeof(char));
            strcpy(gchild[ind++],tmp->left->left->element);
        }
        if(tmp->left->right != NULL){
            gchild[ind] = (char *)malloc(strlen(tmp->left->right->element)*sizeof(char));
            strcpy(gchild[ind++],tmp->left->right->element);
        }
    }
    if(tmp->right != NULL){
        if(tmp->right->left != NULL){
            gchild[ind] = (char *)malloc(strlen(tmp->right->left->element)*sizeof(char));
            strcpy(gchild[ind++],tmp->right->left->element);
        }
        if(tmp->right->right != NULL){
            gchild[ind] = (char *)malloc(strlen(tmp->right->right->element)*sizeof(char));
            strcpy(gchild[ind++],tmp->right->right->element);
        }
    }
    return ind;
}
Tree *insert(char x[], Tree *t){
	if(t==NULL){
		t=(Tree *)malloc(sizeof(Tree));
		if(t==NULL)
			printf("Out of Space!1");
		else{	
			strcpy(t->element,x);
			t->left=t->right=NULL;
		}
	}
	else if(strcmp(x,t->element)<0)
		t->left=insert(x,t->left);
	else if(strcmp(x,t->element)>0)
		t->right=insert(x,t->right);
	return t;
}

Tree *delete(char x[], Tree *t){
	Tree *tmpcell;
	if(t==NULL)
		printf("Element not found");
	else if(strcmp(x,t->element)<0)
		t->left=delete(x,t->left);
	else if(strcmp(x,t->element)>0)
		t->right=delete(x,t->right);
	else if(t->left && t->right){
		tmpcell=findmin(t->right);
		strcpy(t->element,tmpcell->element);
		t->right=delete(t->element,t->right);
	}
	else{
		tmpcell=t;
		if(t->left==NULL)
			t=t->right;
		else if(t->right==NULL)
			t=t->left;
		free(tmpcell);
		}
	return t;
}
char name[20];
int main(){
	Tree *bst;
    char *gchild[4];
	char *str[12] = {"Kumar","Anusha","Ram","Charan","Mohan","Karthika","Chitra","Lakshmi","Abishek","Swetha","Tarun","Sanjana"};
	for(int i=0;i<12;i++)
		bst = insert(str[i],bst);
	printf("Alphabetical:\n");
	inorder(bst);
    //bst = delete("Ram",bst);
    //printf("Ram delated: \n");
    //inorder(bst);

    //printf("Level order:\n");
    //printLevelOrder(bst);
    printf("Enter the name: ");
    scanf("%s", name);
    //printf("level = %d\n",findLevel(name,bst));
    //findGrandparent(name,bst);
    //findSibling(name,bst);
    int ind = findGrandChildren(name,bst,gchild);
    for(int i=0;i<ind;i++)
        printf("%s  ",gchild[i]);
}