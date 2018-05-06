#include<stdio.h>
#include<stdlib.h>

#define NUM_NODE 6
#define true 1
#define false 0
 
typedef struct node{
    int value;
    struct node *next;
}Node;
 
Node *graph[NUM_NODE + 1];
int visited[NUM_NODE + 1];

int find(int rep[], int value){
	if(rep[value] == -1 || rep[value] == value)
		return value;
	else find(rep, rep[value]);
}

void unionSet(int rep[], int x, int y){
	int xroot = find(rep, x);
	int yroot = find(rep, y);
	
	rep[xroot] = yroot;
}

void makeSet(int rep[]){
	for(int i=1; i<= NUM_NODE; i++){
		rep[i] = -1;
    }
}

int connectedComponent(Node * graph[]){

    int rep[NUM_NODE + 1] ;
    int count = 1;

    makeSet(rep);
    for(int i=1; i<= NUM_NODE; i++){
        Node * u =  graph[i];
        if(u){
            Node *v = u->next;
            
            while(v){
                int x = find(rep, u->value);
                int y = find(rep, v->value);
                
                unionSet(rep, x,y);
                v = v->next;
              
            }
        }
    }
    
    for(int i=1; i<= NUM_NODE; i++){
       	if(rep[i] == -1 ){
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
	addEdge(5,4);
	
	for(int i=1; i<=NUM_NODE; i++){
        visited[i] = true;
    }
   
   	int count = connectedComponent(graph);
	printf("\n Number of connected components in graph : %d", count);
	
	return 0;
}
