#include <stdio.h>
#include <string.h>
#define SIZE 5
#include "fun_proto.h"
#include "fun_def.h"

int main(){
	Student std[10];
	for(int i=0;i<SIZE;i++){
		printf("Enter the registration number and name of student: ");
		scanf("%d %s",&std[i].regno,std[i].name);
		printf("Enter the marks: ");
		for(int j=0;j<5;j++)
			scanf("%d", &std[i].marks[j]);
	}
	int size=SIZE;
	 printf("OPERATIONS\n1.Insert at front\n2.Insert at end\n3.Insert after Regester number\n4.Search\n5.Display All\n6.Delete\n7.Display previous ans next record\n");
	int again=1;
    do{
		Student data;
		char Name[20];
		int choice,id,ind;
    	printf("\nEntet your choice: ");
    	scanf("%d", &choice);
        switch (choice){
            case 1:	printf("Enter the registration number and name of student: ");
					scanf("%d %s",&data.regno,data.name);
					printf("Enter the marks: ");
					for(int j=0;j<5;j++)
						scanf("%d", &data.marks[j]);
					insert_first(std,size,data);
                    size = size + 1;
                	break;
            case 2:	printf("Enter the registration number and name of student: ");
					scanf("%d %s",&data.regno,data.name);
					printf("Enter the marks: ");
					for(int j=0;j<5;j++)
						scanf("%d", &data.marks[j]);
					insert_last(std,size,data);
                	size = size +1;
               		break;
            case 3: printf("Enter the register number after which you want to insert a new record: ");
                    scanf("%d",&id);
					printf("Enter the registration number and name of student: ");
					scanf("%d %s",&data.regno,data.name);
					printf("Enter the marks: ");
					for(int j=0;j<5;j++)
						scanf("%d", &data.marks[j]);
                    insert(std,id,size,data);
                    size = size+1;
                    break;
            case 4:	printf("Enter the name: ");
                    scanf("%s",Name);
                    search_name(std,size,Name);
                    break;
            case 5:	display(std,size);
                	break;
            case 6: printf("Enter the regester number: ");
                    scanf("%d",&id);
                    delete(std,size,id);
                    size = size -1;
                    break;
            case 7:	printf("Enter the regester number: ");
                    scanf("%d",&id);
                    displayPN(std,size,id);
                    break;
            default:printf("Enter a valid choice!!");
					break;
        }
        printf("Enter '0' to stop or any other number to continue\n");
        scanf("%d",&again);
    }while(again!=0);
}
/*OUTPUT
Enter the registration number and name of student: 28 Peter
Enter the marks: 1 1 1 1 1
Enter the registration number and name of student: 31 John
Enter the marks: 2 2 2 2 2
Enter the registration number and name of student: 40 Tyler
Enter the marks: 3 3 3 3 3
Enter the registration number and name of student: 30 Coby
Enter the marks: 4 4 4 4 4
Enter the registration number and name of student: 1 Marques
Enter the marks: 5 5 5 5 5
OPERATIONS
1.Insert at front
2.Insert at end
3.Insert after Regester number
4.Search
5.Display All
6.Delete
7.Display previous ans next record

Entet your choice: 1
Enter the registration number and name of student: 21 Henry
Enter the marks: 6 6 6 6 6
Enter '0' to stop or any other number to continue
7

Entet your choice: 5
21      Henry   6 6 6 6 6
28      Peter   1 1 1 1 1
31      John    2 2 2 2 2
40      Tyler   3 3 3 3 3
30      Coby    4 4 4 4 4
1       Marques 5 5 5 5 5
Enter '0' to stop or any other number to continue
9

Entet your choice: 2
Enter the registration number and name of student: 881 David
Enter the marks: 7 7 7 7 7
Enter '0' to stop or any other number to continue
8

Entet your choice: 5
21      Henry   6 6 6 6 6
28      Peter   1 1 1 1 1
31      John    2 2 2 2 2
40      Tyler   3 3 3 3 3
30      Coby    4 4 4 4 4
1       Marques 5 5 5 5 5
881     David   7 7 7 7 7
Enter '0' to stop or any other number to continue
9

Entet your choice: 3
Enter the register number after which you want to insert a new record: 40
Enter the registration number and name of student: 27 Matt
Enter the marks: 8 8 8 8 8
Enter '0' to stop or any other number to continue
9

Entet your choice: 5
21      Henry   6 6 6 6 6
28      Peter   1 1 1 1 1
31      John    2 2 2 2 2
40      Tyler   3 3 3 3 3
27      Matt    8 8 8 8 8
30      Coby    4 4 4 4 4
1       Marques 5 5 5 5 5
881     David   7 7 7 7 7
Enter '0' to stop or any other number to continue
9

Entet your choice: 4
Enter the name: Tyler
3       Tyler   3 3 3 3 3
Enter '0' to stop or any other number to continue
9

Entet your choice: 6
Enter the regester number: 40
Enter '0' to stop or any other number to continue
9

Entet your choice: 5
21      Henry   6 6 6 6 6
28      Peter   1 1 1 1 1
31      John    2 2 2 2 2
27      Matt    8 8 8 8 8
30      Coby    4 4 4 4 4
1       Marques 5 5 5 5 5
881     David   7 7 7 7 7
Enter '0' to stop or any other number to continue
9

Entet your choice: 7
Enter the regester number: 30
27      Matt    8 8 8 8 8
1       Marques 881 881 881 881 881
Enter '0' to stop or any other number to continue
0
 */