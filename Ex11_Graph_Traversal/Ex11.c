#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front = NULL,*rear=NULL;

int isEmpty(){
    return front == NULL; 
}

void enqueue(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear -> next = newNode;
        rear = newNode;
    }
}
int getFront(){
    return front->data;
}
void dequeue(){
    if(front == NULL)
        printf("\nQueue is Empty!!!\n");
    else{
        struct Node *temp = front;
        front = front -> next;
        free(temp);
    }
}

struct adjlistnode{
    int neighbour;
    struct adjlistnode *next;
};

struct adjlist{
    struct adjlistnode *head;
};

typedef struct adjlist AdjList;

struct graph{
    int vertex;
    int *visited;
    AdjList *arr;
};

typedef struct graph Node;

struct adjlistnode* newAdjListNode(int dest){ 
    struct adjlistnode* newNode = (struct adjlistnode*)malloc(sizeof(struct adjlistnode)); 
    newNode->neighbour = dest; 
    newNode->next = NULL; 
    return newNode; 
}

Node* createGraph(int V){ 
    Node* graph = (Node*)malloc(sizeof(Node)); 
    graph->vertex = V; 
    graph->arr = (struct adjlist*) malloc(V * sizeof(struct adjlist)); 
    graph->visited = (int *)malloc(V*sizeof(int));
    for (int i = 0; i < V; ++i){ 
        graph->arr[i].head = NULL;
        graph->visited[i] = 0;
    } 
    return graph; 
} 

void addEdge(Node* graph,int src,int dest,int type){ 
    if(type == 1){ 
        struct adjlistnode *newNode = newAdjListNode(dest); 
        newNode->next = graph->arr[src].head; 
        graph->arr[src].head = newNode;
    } 
    else if(type == 2){
        struct adjlistnode *newNode = newAdjListNode(dest); 
        newNode->next = graph->arr[src].head; 
        graph->arr[src].head = newNode;
        newNode = newAdjListNode(src); 
        newNode->next = graph->arr[dest].head; 
        graph->arr[dest].head = newNode;
    }

}

void printGraph(Node* graph){ 
    int v; 
    for (v = 0; v < graph->vertex; v++){ 
        struct adjlistnode* temp = graph->arr[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v+1); 
        while (temp){ 
            printf("-> %d", temp->neighbour); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
}

void DFS(Node *graph,int ind){
    graph->visited[ind] = 1;
    struct adjlistnode *temp = graph->arr[ind].head;
    printf("-> %d",ind);
    while(temp){
        if(graph->visited[temp->neighbour]==0)
            DFS(graph,temp->neighbour);
        temp = temp->next;
    }
}

void BFS(Node *graph,int ind){
    graph->visited[ind] = 1;
    struct adjlistnode *temp;
    enqueue(ind);
    while(!isEmpty()){
        ind = getFront();
        printf("-> %d",ind);
        dequeue();
        temp = graph->arr[ind].head;
        while(temp!=NULL){
            if(graph->visited[temp->neighbour] == 0){
                graph->visited[temp->neighbour] = 1;
                enqueue(temp->neighbour);
            }
            temp = temp->next;
        }
        
    }
}
int main(){
    char ver[5]={'A','B','C','D','E'};
    //printf("Enter the vertices: ");
    //scanf("%d", &ver);
    int src,dest;
    Node *graph = createGraph(5);
    char ch = 'y';
    int type;
    printf("GRAPH TYPE\n1: Directed\t2: Undirected\nEnter your choice: ");
    scanf("%d", &type);
    for(int i=0;i<5;i++)
        printf("%d : %c\n",(i),ver[i]);
    while(ch == 'y'||ch == 'Y'){
        printf("Enter the source: ");
        scanf("%d",&src);
        printf("Enter the destination: ");
        scanf("%d",&dest);
        addEdge(graph,src,dest,type);
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &ch);
    }
    printGraph(graph);
    //DFS(graph,0);
    printf("\n");
    BFS(graph,0);
    printf("\n");
}