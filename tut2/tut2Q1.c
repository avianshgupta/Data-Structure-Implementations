#include <stdio.h>
#include <stdlib.h>

struct SearchTree{
	int data;
	struct SearchTree *left,*right;
};

typedef struct SearchTree Tree;

Tree *insert(int x, Tree *t){
	if(t==NULL){
		t=(Tree *)malloc(sizeof(Tree));
		if(t==NULL)
			printf("Out of Space!!");
		else{	
			t->data = x;
			t->left=t->right=NULL;
		}
	}
	else if(x < t->data)
		t->left=insert(x,t->left);
	else if(x > t->data)
		t->right=insert(x,t->right);
	return t;
}
int arr[20];
int i=0;
int inorder(Tree *t){
    if(t != NULL){
        inorder(t->left);
        arr[i++] = t->data;
        inorder(t->right);
    }
    return i;
}
int checkBST(Tree *t){
    int len,arr[20];
    len = inorder(t);
    for(int i=0;i<len;i++){
        if(arr[i]>arr[i+1])
            return 0;
    }
    return 1;
}

int main(){
    Tree *bst=NULL;
    int num,ele;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    printf("Enter the elements: ");
    for(int i=0;i<num;i++){
        scanf("%d", &ele);
        insert(ele,bst);
    }
    if(checkBST(bst)==1)
        printf("Tree is BST\n");
    else
        printf("Tree is not BST");
}