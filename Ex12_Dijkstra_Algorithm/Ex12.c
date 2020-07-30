#include <stdio.h>
#include <stdlib.h>
#define infinity 1000
#define false 0
#define true 1


struct adjlistnode{
    int neighbour;
    int wt;
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

struct adjlistnode* newAdjListNode(int dest,int wt){ 
    struct adjlistnode* newNode = (struct adjlistnode*)malloc(sizeof(struct adjlistnode)); 
    newNode->neighbour = dest;
    newNode->wt = wt; 
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

void addEdge(Node* graph,int src,int wt,int dest,int type){ 
    if(type == 2){ 
        struct adjlistnode *newNode = newAdjListNode(dest-1,wt); 
        newNode->next = graph->arr[src-1].head; 
        graph->arr[src-1].head = newNode;
    } 
    else if(type == 1){
        struct adjlistnode *newNode = newAdjListNode(dest-1,wt); 
        newNode->next = graph->arr[src-1].head; 
        graph->arr[src-1].head = newNode;
        newNode = newAdjListNode(src-1,wt); 
        newNode->next = graph->arr[dest-1].head; 
        graph->arr[dest-1].head = newNode;
    }

}
void printGraph(Node* graph){ 
    int v; 
    for (v = 0; v < graph->vertex; v++){ 
        struct adjlistnode* temp = graph->arr[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v+1); 
        while (temp){ 
            printf("-> (%d,%d)",temp->neighbour+1,temp->wt); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
}

int getWeight(Node *graph,int src,int dest){
    struct adjlistnode *temp = graph->arr[src].head;
    if(temp->neighbour == dest){
        return temp->wt;
    }
    while(temp != NULL){
        if(temp->neighbour == dest){
            return temp->wt;
        }
        temp = temp->next;
    }
}
int findvertex(int size,int visited[],int distance[]){
    int minwt[size],ind=0;;
    for(int i=0;i<size;i++){
        if(visited[i] == false)
            minwt[ind++] = i;
    }
    int min = minwt[0];
    for(int i=1;i<ind;i++){
        if(distance[minwt[i]]<distance[min])
            min = minwt[i];
    }
    return min;
}
void dijkstra(Node *graph,int src,int visited[],int distance[],int pos[]){
    for(int i = 0;i<graph->vertex;i++){
        visited[i] = false;
        distance[i] = infinity;
        pos[i] = 0;
    }
    distance[src] = 0;
    pos[src] = -1;
    for(int i=0;i<graph->vertex;i++){
        int u = findvertex(graph->vertex,visited,distance);
        visited[u] = true;
        struct adjlistnode *temp = graph->arr[u].head;
        while(temp != NULL){
            if(visited[temp->neighbour] == false && (distance[temp->neighbour] > distance[u] + getWeight(graph,u,temp->neighbour))){
                distance[temp->neighbour] = distance[u] + getWeight(graph,u,temp->neighbour);
                pos[temp->neighbour] = u;
            }
            temp = temp->next;
        } 
    }

}

void printdijkstratable(int size,int visited[],int distance[],int pos[]){
    printf("V\tK\tD\tP\n");
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t%d\n",(i+1),visited[i],distance[i],pos[i]+1);
    }
}

int getPath(Node *graph,int pos[],int src,int dest,int path[]){
    int len = 1;
    pos[src]=0;
    int temp = dest;
    path[0] = dest;
    while(pos[temp]!=src){
        temp = pos[temp];
        path[len++] = temp; 
    }
    path[len++] = src;
    return len;
}
void printPath(int path[],int len){
    for(int i=len-1;i>=0;i--){
        if(i == 0)
            printf("%d\n",path[i]+1);
        else
            printf("%d-->",path[i]+1);
    }
}
int main(){
    Node *graph1 = createGraph(7);
    Node *graph2 = createGraph(6);
    int visited[7],distance[7],pos[7];
    int type,choice;
    printf("GRAPH TYPE\n1: Undirected\t2: Directed\nEnter your choice: ");
    scanf("%d", &type);
    switch(type){
        case 1: addEdge(graph2,1,5,2,1);
                addEdge(graph2,1,6,4,1); 
                addEdge(graph2,1,10,5,1); 
                addEdge(graph2,2,1,3,1); 
                addEdge(graph2,2,2,5,1); 
                addEdge(graph2,2,7,6,1);
                addEdge(graph2,3,8,6,1); 
                addEdge(graph2,4,3,5,1);
                addEdge(graph2,5,4,6,1);
                printf("Graph created successfully\n");
                printGraph(graph2);
                dijkstra(graph2,0,visited,distance,pos);
                printdijkstratable(graph2->vertex,visited,distance,pos);
                for(int i=1;i<graph2->vertex;i++){
                    int path[graph2->vertex],len;
                    printf("Path of V1 to V%d:\n",i+1);
                    len = getPath(graph2,pos,0,i,path);
                    printPath(path,len);
                    printf("Distance: %d\n\n",distance[i]);
                }
                break;
        case 2: addEdge(graph1,1,2,2,2);
                addEdge(graph1,1,1,4,2);
                addEdge(graph1,2,3,4,2);
                addEdge(graph1,2,10,5,2);
                addEdge(graph1,3,4,1,2);
                addEdge(graph1,3,5,6,2);
                addEdge(graph1,4,2,3,2);
                addEdge(graph1,4,2,5,2);
                addEdge(graph1,4,8,6,2);    
                addEdge(graph1,4,4,7,2);
                addEdge(graph1,5,6,7,2);
                addEdge(graph1,7,1,6,2);
                printf("\nGraph created successfully\n\n");
                printGraph(graph1);
                dijkstra(graph1,0,visited,distance,pos);
                printdijkstratable(graph1->vertex,visited,distance,pos);
               for(int i=1;i<graph1->vertex;i++){
                    int path[graph1->vertex],len;
                    printf("Path of V1 to V%d:\n",i+1);
                    len = getPath(graph1,pos,0,i,path);
                    printPath(path,len);
                    printf("Distance: %d\n\n",distance[i]);
                }
                break;
    }
}