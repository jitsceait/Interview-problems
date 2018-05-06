#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_NODE 7
#define NUM_WORDS 10
#define NUM_CHAR 4 
#define true 1
#define false 0

#define INFINITE 1000

typedef struct node{
    int value;
    int wt;
    struct node *next;
}Node;

Node *graph[NUM_NODE + 1];
int visited[NUM_NODE + 1];

int findNextNode(int indegree[]){
	for( int i=0; i<= NUM_NODE; i++){
		if(indegree[i] == 0 && visited[i] == 0){
			return i;
		}
	}
	return -1;
}
void topologicalSort(Node * graph[]){

    int indegree[NUM_NODE+1];
    int i;

    Node * current = NULL;
    Node * next = NULL;
    for(i=1; i<=NUM_NODE; i++){
        indegree[i] =0;
    }
    /* Find indegree of each node. go through all edges.
    complexity : O(E) */
    
    for(i=1; i<=NUM_NODE; i++){
        current = graph[i];
        if(current){
            next = current->next;
            while(next){
                indegree[next->value]++;
                next = next->next;
            }
        }
    }

    /* We will traverse each node */
    for(i=1; i<=NUM_NODE; i++){
        /* find a node with zero indegree */
        int node  = findNextNode(indegree);
        /* If there is no node with zero indegree, 
        topological sort not possible */
        if(node != -1){
            printf("%d ", node);
            visited[node] = 1;
            /* decrease in degree of each node adjacent 
            to node wih zero indegree */
            current = graph[node];
            if(current){
                next = current->next;
                while(next){
                    indegree[next->value]--;
                    next = next->next;
                }
            }
        }
        else{
            printf("\n Topological sort no possible");
        }
    }
    return ;
}

Node * createNode(int j, int wt){

    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode){
        newNode->value = j;
        newNode->next = NULL;
        newNode->wt = wt;
    }
    else{
        printf("\n Node cannot be allocated");
    }
    return newNode;
}

void addEdge(int i, int j, int wt){

    Node * currentNode = graph[i];
    if(!currentNode){
        graph[i] = createNode(j, wt);
    }
    else{
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(j, wt);
    }
}


int main(){

    for(int i=1; i<=NUM_NODE; i++){
        graph[i] = createNode(i,0);
    }

    addEdge(1,2,4);
    addEdge(1,3,8);
    addEdge(2,3,9);
    addEdge(2,4,9);
    addEdge(3,4,2);
    addEdge(2,5,10);
    addEdge(3,6,1);
    addEdge(4,5,7);
    addEdge(4,6,9);
    addEdge(5,6,6);
    addEdge(6,7,2);

    topologicalSort(graph);

    return 0;
}
