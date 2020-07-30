#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

char name[20];
int main(){
	Tree *bst;
    char *gchild[4];
	char *str[12] = {"Kumar","Anusha","Ram","Charan","Mohan","Karthika","Chitra","Lakshmi","Abishek","Swetha","Tarun","Sanjana"};
	for(int i=0;i<12;i++)
		bst = insert(str[i],bst);
    int choice;
    printf("BST OPERATIONS\n1: Display in Alphabetical order\n2: Find Grandparent\n3: Find Grand children\n4: Find Siblings\n5: Delete and display\n");
    printf("\nEnter Your choice: ");
    scanf("%d", &choice);
    do{
        switch(choice){
            case 1: printf("-----------------------------------------------------------------\n");
                    printf("ALPHABETICAL ORDER\n");
                    inorder(bst);
                    printf("----------------------------------------------------------------\n");
                    break;
            case 2: printf("-----------------------------------------------------------------\n");
                    printf("Enter the person whose grandparent you need to find: ");
                    scanf("%s", name);
                    level = 0;
                    findGrandparent(name,bst);
                    printf("-----------------------------------------------------------------\n");
                    break;
            case 3: printf("-----------------------------------------------------------------\n");
                    printf("Enter the person whose grand children you need to find: ");
                    scanf("%s", name);
                    int ind = findGrandChildren(name,bst,gchild);
                    if(ind != 0){
                        printf("Grand Children of %s: ",name);
                        for(int i=0;i<ind;i++)
                            printf("%s ",gchild[i]);
                        printf("\n");
                    }
                    else{
                        printf("No grand childern");
                    }
                    printf("-----------------------------------------------------------------\n");
                    break;
            case 4: printf("-----------------------------------------------------------------\n");
                    printf("Enter the person whose Siblings you need to find: ");
                    scanf("%s", name);
                    level = 0;
                    findSibling(name,bst);
                    printf("-----------------------------------------------------------------\n");
                    break;
            case 5: printf("-----------------------------------------------------------------\n");
                    printf("Enter the person whom you want to delete: ");
                    scanf("%s", name);
                    bst = delete(name,bst);
                    printf("Resultant Tree:\n");
                    inorder(bst);
                    printf("-----------------------------------------------------------------\n");
                    break;
        }
        printf("BST OPERATIONS\n1: Display in Alphabetical order\n2: Find Grandparent\n3: Find Grand children\n4: Find Siblings\n5: Delete and display\n");
        printf("\nEnter Your choice: ");
        scanf("%d", &choice);
    }while(choice != -1);
}

/*OUTPUT
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 1
-----------------------------------------------------------------
ALPHABETICAL ORDER
Abishek
Anusha
Charan
Chitra
Karthika
Kumar
Lakshmi
Mohan
Ram
Sanjana
Swetha
Tarun
----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 2
-----------------------------------------------------------------
Enter the person whose grandparent you need to find: Lakshmi
The grandparent of Lakshmi is Ram
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 2
-----------------------------------------------------------------
Enter the person whose grandparent you need to find: Karthika
The grandparent of Karthika is Anusha
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 3
-----------------------------------------------------------------
Enter the person whose grand children you need to find: Charan
Grand Children of Charan: Chitra
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 4
-----------------------------------------------------------------
Enter the person whose Siblings you need to find: Swetha
The sibling of Swetha is Mohan
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 4
-----------------------------------------------------------------
Enter the person whose Siblings you need to find: Chitra
No Sibling
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: 5
-----------------------------------------------------------------
Enter the person whom you want to delete: Ram
Resultant Tree:
Abishek
Anusha
Charan
Chitra
Karthika
Kumar
Lakshmi
Mohan
Sanjana
Swetha
Tarun
-----------------------------------------------------------------
BST OPERATIONS
1: Display in Alphabetical order
2: Find Grandparent
3: Find Grand children
4: Find Siblings
5: Delete and display

Enter Your choice: -1
*/