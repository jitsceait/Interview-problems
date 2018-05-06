#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define NUM_NODE 6

typedef struct node{
        int value;
        struct node *next;
}Node;

Node *graph[NUM_NODE+1];
int visited[NUM_NODE+1];

void dfs(Node * current){
	
	if(!current) return;
	
	visited[current->value] = true;
	printf("%d ", current->value);
	
	Node * newCurrentNode = current->next;
        while(newCurrentNode){
                if(visited[newCurrentNode->value] != true){
                        dfs(graph[newCurrentNode->value]);
                }
                newCurrentNode = newCurrentNode->next;
        }
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
		while(currentNode->next)
			currentNode = currentNode->next;
		
		currentNode->next = createNode(j);
	}
}
int main(){
	int i,j;
	
	for(i=1; i<=NUM_NODE; i++){
		graph[i] = createNode(i);
	}
	
	addEdge(1,2);
	addEdge(1,5);
	addEdge(2,3);
	addEdge(2,4);
	addEdge(3,4);
	addEdge(4,6);
	addEdge(5,4);
	addEdge(5,6);
	
	for(i=1; i<=NUM_NODE; i++){
		visited[i] = false;
	}
	
	dfs(graph[1]);
	
	return 0;
}
