#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

struct queue{
    Node *element;
    struct queue *next;
};
typedef struct queue Queue;


void enqueue(Queue **queue, Node *node){
	Queue *q  = NULL;
	Queue *head  = *queue;
	
	if(!(*queue)){
		q =(Queue *)malloc(sizeof(Queue));
		q->element = node;
		q->next = NULL;
		*queue = q;
	}
	else{
		q = *queue;
		while(q->next)
			q = q->next;
		
		Queue *temp =(Queue *)malloc(sizeof(Queue));
		q->next = temp;
		temp->element = node;
		temp->next = NULL;
		*queue = head;
	}
}

int isEmpty( Queue *q){
	if(!q) return 1;
	
	return 0;
}
Node *front(Queue *queue){
	if(queue)
		return queue->element;
}

void dequeue(Queue **queue){
	Queue *q = *queue;
	
	Queue *nodeToDelete = q;
	q = nodeToDelete->next;
	nodeToDelete = NULL;
	free(nodeToDelete);
	
	*queue = q;
}

Node * createNode(int value){
    Node * newNode =  (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    
    return newNode;
}
Node * addNode(Node *node, int value){
    if(!node){
        return createNode(value);
    }
    else{
        if (node->value > value){
            node->left = addNode(node->left, value);
        }
        else{
            node->right = addNode(node->right, value);
        }
    }
    return node;
}

void printTreeLevel(Node * node){

 Queue *q =  NULL;
 enqueue(&q, node);
 
 while(!isEmpty(q)){
 	Node *currentNode = front(q);
 	
 	printf("%d ", currentNode->value);
    
    if(currentNode->left)
     	enqueue(&q, currentNode->left);
    if(currentNode->right)
    	enqueue(&q, currentNode->right);
	
	dequeue(&q);
 }
}
/* Driver program for the function written above */
int main(){
    Node *root = NULL;
	
	//Creating a binary tree
    root = addNode(root,30);
    root = addNode(root,20);
    root = addNode(root,15);
    root = addNode(root,25);
    root = addNode(root,40);
    root = addNode(root,37);
    root = addNode(root,45);
 
    printTreeLevel(root);       
    return 0;
}