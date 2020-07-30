#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
	char jobNo[2];
	int bstime;
	struct Queue *next;
};

typedef struct Queue Node;
Node *front = NULL;
Node *rear = NULL;

void enqueue(char jno[],int bt){
	Node *newNode;
	newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode->jobNo,jno);
	newNode->bstime = bt;
	newNode->next = NULL;
	if(front == NULL)
		front = rear = newNode;
	else{
		rear -> next = newNode;
		rear = newNode;
	}
}

void dequeue(){
	if(front == NULL)
		printf("\nQueue is Empty!!!\n");
	else{
		Node *temp = front;
		front = front -> next;
		printf("\nDeleted element: (%s %d)\n", temp->jobNo,temp->bstime);
		free(temp);
	}
}

void display(){
	if(front == NULL)
		printf("\nQueue is Empty!!!\n");
	else{
		Node *temp = front;
		while(temp->next != NULL){
		printf("(%s %d)--->",temp->jobNo,temp->bstime);
		temp = temp -> next;
		}
		printf("(%s %d)--->",temp->jobNo,temp->bstime);
	}
} 