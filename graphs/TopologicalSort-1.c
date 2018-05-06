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

typedef struct Queue{
	Node *front;
	Node *rear;
}Queue;
 
int isEmpty(Queue *q){
	if(!(q->front || q->rear) ) return true;
 
	return false;
}
 
void enqueue(Queue *q, int value){
 
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->value = value;
 
	if(isEmpty(q)){
		q->front = newNode;
		q->rear  = newNode;
	}
	else{
		if(q->rear){
			q->rear->next = newNode;
			q->rear 	  = newNode;
		}
		else{
			printf("\n Error ");
		}
	}
}
 
int dequeue(Queue *q){
	if(!isEmpty(q)){
		int data = q->front->value;
		Node * currentFront = q->front;
		if(q->front == q->rear){
			q->rear = NULL;
			q->front = NULL;
		}
		else{
			q->front = currentFront->next;
		}
		free(currentFront);
		return data;
	}
}
void initializeQueue(Queue **q){
	*q = (Queue *)malloc(sizeof(Queue));
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

void topologicalSort(Node * graph[]){

    int indegree[NUM_NODE+1];
    int i;

    Queue *q = NULL;

    initializeQueue(&q);

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

    for(i=1; i<=NUM_NODE; i++){
        if(indegree[i] == 0){
            enqueue(q, i);
            indegree[i]--;
            break;
        }
    }

    while(!isEmpty(q)){
        int node  = dequeue(q);
        printf("%d ", node);
        /* decrease in degree of each node adjacent to node wih zero indegree */
        current = graph[node];
        if(current){
            next = current->next;
            while(next){
                indegree[next->value]--;
                if(indegree[next->value] == 0){
                    /* If indegree of any node becomes zero, enqueue it in queue. */
                    enqueue(q,next->value);
                    indegree[next->value]--;
                }
                next = next->next;
            }
        }
    }

    for(i=1; i<=NUM_NODE; i++){
        if(indegree[i] > 0){
            printf("\n Topological sort not possible");
        }
    }
    return;
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
