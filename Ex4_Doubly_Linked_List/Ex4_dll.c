#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_proto.h"
#include "fun_def.h"

int main(){
	Node *hd,*tail,*pos;
	int ind,len;
	int *ptr_ind;
	ptr_ind=&ind;
	char Name[30],nName[30],*arr[20];
	hd=CreateEmptyList();
	tail=hd->next;
	while(tail->next!=NULL)
		tail = tail->next;
	printf("OPERATIONS\n1: Insert at Beginning.\n2: Insert at last.\n3: Insert after a name.\n4: Search a name.\n5: Delete\n6: Display All\n7: Diaplay in alphabetical order.\n");
	int choice;
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	do{
		switch(choice){
			case 1: printf("Enter the name to be inserted: ");
					scanf("%s", Name);
					add_beg(hd,Name);
					break;

			case 2: printf("Enter the name to be inserted: ");
					scanf("%s", Name);
					add_end(tail,Name);
					break;

			case 3: printf("Enter the name after which you want to insert: ");
					scanf("%s", Name);
					pos = position(Name,hd,ptr_ind);
					if(pos==NULL){
						printf("Name not Found!!\nPlease enter correct name.");
					}
					else{
						printf("Enter the name to be inserted: ");
						scanf("%s", nName);
						insert(nName,pos);
					}
					break;

			case 4: printf("Enter the name to be searched: ");
					scanf("%s", Name);
					pos = position(Name,hd,ptr_ind);
					if(pos==NULL)
						printf("Name not Found!!\nPlease enter correct name.");
					else
						printf("Position of %s is %d", Name,ind);
					break;

			case 5: printf("Enter the name of the student to be deleted: ");
					scanf("%s", Name);
					pos = position(Name,hd,ptr_ind);
					if(pos==NULL)
						printf("Name not Found!!\nPlease enter correct name.");
					else
						delete(pos);
					break;

			case 6: display(hd);
					break;

			case 7: len = alpha_ord_display(hd,arr);
					for(int i = 0 ; i < len ; i++)
						printf("%s\n", arr[i]);
					break;
		}
		printf("\nOPERATIONS\n1: Insert at Beginning.\n2: Insert at last.\n3: Insert after a name.\n4: Search a name.\n5: Delete\n6: Display All\n7: Display in alphabetical order.\n");
		printf("\nEnter your choice(To stop enter -1): ");
		scanf("%d", &choice);
	}while(choice != -1);
}

/*OUTPUT
OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice: 1
Enter the name to be inserted: Marques

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 2
Enter the name to be inserted: Jake

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 1
Enter the name to be inserted: Coby

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 3
Enter the name after which you want to insert: Coby
Enter the name to be inserted: Tyler

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 2
Enter the name to be inserted: Garret

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 6
Coby
Tyler
Marques
Jake
Garret


OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 4
Enter the name to be searched: Jake
Position of Jake is 4
OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 4
Enter the name to be searched: John
Name not Found!!
Please enter correct name.
OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 5
Enter the name of the student to be deleted: John
Name not Found!!
Please enter correct name.
OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 6
Coby
Tyler
Marques
Jake
Garret


OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 5
Enter the name of the student to be deleted: Jake

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 6
Coby
Tyler
Marques
Garret


OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 3
Enter the name after which you want to insert: John
Name not Found!!
Please enter correct name.
OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 6
Coby
Tyler
Marques
Garret


OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 3
Enter the name after which you want to insert: Marques
Enter the name to be inserted: Jake

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): 7

Coby
Garret
Jake
Marques
Tyler

OPERATIONS
1: Insert at Beginning.
2: Insert at last.
3: Insert after a name.
4: Search a name.
5: Delete
6: Display All
7: Display in alphabetical order.

Enter your choice(To stop enter -1): -1 */