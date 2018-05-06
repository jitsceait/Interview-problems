#include<stdio.h>
#include<stdlib.h>

#define NUM_NODE 6
#define TRUE 1
#define FALSE 0
typedef struct node{
    int value;
    struct node *next;

}Node;

Node *graph[NUM_NODE];

Node * createNode(int j){

    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode){
        newNode->value = j;
        newNode->next = NULL;
    }
    else{
        printf("\n Node cannot be allocated");
    }
    return newNode;
}
void addEdge(int i, int j){

    Node * currentNode = graph[i];
    if(!currentNode){
        graph[i] = createNode(j);
    }
    else{
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(j);
    }
    currentNode = graph[j];
    if(!currentNode){
        graph[j] = createNode(i);
    }
    else{
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(i);
    }
}

int visited[NUM_NODE + 1];

void dfs(Node * current){
    if(!current) return;
    
    visited[current->value] = TRUE;
    Node *temp = current->next;
    
    while(temp){
        if(visited[temp->value] != TRUE){
            dfs(graph[temp->value]);
        }
        temp = temp->next;
    }
}
int isStrongComponent(Node * graph[], int degree[]){
	int i = 0;
    for(i=1; i<=NUM_NODE; i++){
        if(degree[i] != 0)
            break;
    }
    if(i == NUM_NODE) return TRUE;

    dfs(graph[0]);

    for(int i=1; i<=NUM_NODE; i++){
        if(degree[i] !=0 && visited[i]== FALSE)
            return FALSE;
    }
    return TRUE;
}

int EulerPathExists(Node * graph[]){
    int degree[NUM_NODE+1];
    int count =0;

    for(int i=1; i<=NUM_NODE; i++){
        degree[i] =0;
    }
    for(int i=1; i<=NUM_NODE; i++){
        count =0;
        Node * current  = graph[i];
        while(current){
            current = current->next;
            count++;
        }
        degree[i] = count;
    }
    int connected  = isStrongComponent(graph, degree);
    count = 0;
    for(int i=1; i<=NUM_NODE; i++){
        if(degree[i]%2){
            count++;
        }
    }
    if(count !=0 && count !=2 && !connected) return FALSE;

    return TRUE;
}
int main(){
	
   addEdge(1,4);
   addEdge(2,1);
   addEdge(2,6);
   addEdge(4,3);
   addEdge(3,6);
   addEdge(3,5);
   addEdge(5,6);

    int isEulerPath = EulerPathExists(graph);

    if(isEulerPath)
        printf("\n Graph contains Euler Path");
    else
        printf("\n Graph does not contain Euler Path");
    return 0;
}
