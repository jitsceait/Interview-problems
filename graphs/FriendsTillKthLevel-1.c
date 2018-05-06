#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define NUM_NODE 6
#define SENTINEL -1

typedef struct node{
        int value;
        struct node *next;
}Node;

Node *graph[NUM_NODE+1];
int visited[NUM_NODE+1];

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

void findFriendsTillKthLevel(int person, int K){
	
	Queue *q = NULL;
	
	initializeQueue(&q);
	enqueue(q, person);
	enqueue(q, SENTINEL);
	
	int degree = 0;
	printf(" Person : ");
	while(!isEmpty(q) && degree <= K){
		int index = dequeue(q);
		if(index != SENTINEL){
			visited[index] = true;
		    printf("%d ",  index);
			Node *currentNode = graph[index]->next;
			while(currentNode){
				if(visited[currentNode->value] == false){
					visited[currentNode->value] = true;
					enqueue(q, currentNode->value);
				}
				currentNode = currentNode->next;
			}
		}
		else if(!isEmpty(q) ){
			enqueue(q, SENTINEL);
			degree++;
			printf("\n Level %d : ", degree);
		}
	}
	while(!isEmpty(q)){
		dequeue(q);
	}
	
	return degree;
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
	
	for(int i=1; i<=NUM_NODE; i++){
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
	
	for(int i=1; i<=NUM_NODE; i++){
		visited[i] = false;
	}
	
	findFriendsTillKthLevel(1,2);
	
	return 0;
}
