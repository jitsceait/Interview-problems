#include<stdio.h>
#include<stdlib.h>
 
#define NUM_NODE 7
#define true 1
#define false 0
 
typedef struct node{
    int value;
    int wt;
    struct node *next;
}Node;
 
Node *graph[NUM_NODE + 1];
int visited[NUM_NODE + 1];
 
int onStack[NUM_NODE + 1];
 
#define NUM_NODDE 6
#define true 1
#define false 0
 
int visited[NUM_NODE + 1];
 
void dfs(Node * current){
    if(!current) return;
    visited[current->value] = true;
    Node *temp = current->next;
    while(temp){
        if(visited[temp->value] != true){
            dfs(graph[temp->value]);
        }
        temp = temp->next;
    }
}
 
int connected_component(Node * graph[]){
    int i, count =0;
    Node * current = NULL;
    for(i=0; i< NUM_NODE; i++){
        current  = graph[i];
        if(current && visited[current->value] == false){
            dfs(current);
            count++;
        }
    }
    return count;
}
 
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
}
//Driver program
int main(){
 
	for(int i=1; i<=NUM_NODE; i++){
		graph[i] = createNode(i);
	}
 
	addEdge(1,2);
	addEdge(1,5);
	addEdge(2,3);
	addEdge(2,4);
	addEdge(4,1);
	addEdge(3,4);
	addEdge(4,6);
	addEdge(5,4);
	addEdge(5,6);
 
	for(int i=1; i<=NUM_NODE; i++){
        visited[i] = false;
    }
 
    int count = connected_component(graph);
    printf("\n Number of connected component : %d", count);
 
	return 0;
}
