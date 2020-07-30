#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 99999999
#include "priorityheap.h"

int main(){
	int maxele;
	printf("Enter the max number of element in the heap: ");
	scanf("%d", &maxele);
	heap *pqueue;
	pqueue = init(maxele);
	heapdatatype data;
	int choice;
	printf("PRIORITY QUEUE OPERATIONS\n1: Insert\n2: Delete\n3: Display\n");
	printf("\nEnter your choice: ");
    scanf("%d",&choice);
	do{
		switch(choice){
			case 1: printf("\nEnter the employee's name: ");
					scanf("%s", data.name);
					printf("Enter the employee's id: ");
					scanf("%d", &data.id);
					printf("Enter the employee's salary: ");
					scanf("%d", &data.rt);
					insert(data,pqueue);
					break;
			case 2: deletemin(pqueue);
					break;
			case 3: display(pqueue->size,pqueue);
					break;
			default: printf("\nEnter a valid choice!!\n\n");
		}
			printf("PRIORITY QUEUE OPERATIONS\n1: Insert\n2: Delete\n3: Display\n");
            printf("\nEnter your choice: ");
			scanf("%d",&choice);
	}while(choice != -1);
}

/*OUTPUT
Enter the max number of element in the heap: 6
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 1

Enter the employee's name: John
Enter the employee's id: 67
Enter the employee's salary: 55000
-----------------------------------------
Name: John
Id: 67
Salary: 55000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 1

Enter the employee's name: Peter
Enter the employee's id: 21
Enter the employee's salary: 12000
-----------------------------------------
Name: John
Id: 67
Salary: 55000

Name: Peter
Id: 21
Salary: 12000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 1

Enter the employee's name: Tyler
Enter the employee's id: 10
Enter the employee's salary: 120000
-----------------------------------------
Name: Tyler
Id: 10
Salary: 120000

Name: Peter
Id: 21
Salary: 12000

Name: John
Id: 67
Salary: 55000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 1

Enter the employee's name: Jack
Enter the employee's id: 38
Enter the employee's salary: 89
-----------------------------------------
Name: Tyler
Id: 10
Salary: 120000

Name: Peter
Id: 21
Salary: 12000

Name: John
Id: 67
Salary: 55000

Name: Jack
Id: 38
Salary: 89

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice:
1

Enter the employee's name: Cody
Enter the employee's id: 23
Enter the employee's salary: 89000
-----------------------------------------
Name: Tyler
Id: 10
Salary: 120000

Name: Cody
Id: 23
Salary: 89000

Name: John
Id: 67
Salary: 55000

Name: Jack
Id: 38
Salary: 89

Name: Peter
Id: 21
Salary: 12000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 1

Enter the employee's name: Marques
Enter the employee's id: 33
Enter the employee's salary: 92000
-----------------------------------------
Name: Tyler
Id: 10
Salary: 120000

Name: Cody
Id: 23
Salary: 89000

Name: Marques
Id: 33
Salary: 92000

Name: Jack
Id: 38
Salary: 89

Name: Peter
Id: 21
Salary: 12000

Name: John
Id: 67
Salary: 55000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 2
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 3
-----------------------------------------
Name: Marques
Id: 33
Salary: 92000

Name: Cody
Id: 23
Salary: 89000

Name: John
Id: 67
Salary: 55000

Name: Jack
Id: 38
Salary: 89

Name: Peter
Id: 21
Salary: 12000

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 2
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: 3
-----------------------------------------
Name: Cody
Id: 23
Salary: 89000

Name: Peter
Id: 21
Salary: 12000

Name: John
Id: 67
Salary: 55000

Name: Jack
Id: 38
Salary: 89

-----------------------------------------
PRIORITY QUEUE OPERATIONS
1: Insert
2: Delete
3: Display

Enter your choice: -1
*/