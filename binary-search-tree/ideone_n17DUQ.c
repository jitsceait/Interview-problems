#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
	int isRightThread;
};
typedef struct node Node;

#define false 0
#define true 1
#define NUM_NODES 50

typedef struct Queue {
	int front;
	int rear;
	Node * items[NUM_NODES];
} Queue;

void initializeQueue( Queue **queue ){
	Queue *q = (Queue *) malloc( sizeof( Queue) );
	if(q){
		q->front 	= 0;
		q->rear 	= 0;
	}
	*queue = q;
}

int isEmpty( Queue *q){
	if(q->front == q->rear ){
		return true;
	}
	return false;
}

void enqueue( Queue *q, Node * node){
	if(q){
		q->items[(q->rear)++] = node;
	}
}

Node * dequeue( Queue *q){
	if(!isEmpty(q)){
		return q->items[(q->front)++];
	}
	return NULL;
}
Node * front( Queue *q){
	if(!isEmpty(q)){
		return q->items[(q->front)];
	}
	return NULL;
}
void feedQueue( Node * root, Queue *q ){
	if(!root) return;
	
	feedQueue(root->left, q);
	enqueue(q, root);
	feedQueue(root->right, q);
}

void createThreads( Node * root, Queue *q){
	if(!root) return;
	
	if(root->left) createThreads (root->left, q);
	
	dequeue(q);
	
	if(root->right) createThreads (root->right, q);
	else{
		root->right = front(q);
		root->isRightThread = true;
	}
}

void createThreadedTree(Node * root){
	Queue *q = NULL;
	initializeQueue(&q);
	
	feedQueue(root, q);
	
	createThreads(root, q);
}

void inoderTraversal(Node * root){
	if(!root)
		return;
	
	inoderTraversal(root->left);
	printf("%d ", root->value);
	inoderTraversal(root->right);
}
Node *createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	newNode->isRightThread = false;
	
	return newNode;
}
Node *addNode(Node *node, int value){
	if(!node){
		return createNode(value);
	}
	if (node->value > value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value );
		
	return node;
}

/* Driver program for the function written above */
int main(){
	Node *root = NULL;
	//Creating a binary tree
	root = addNode(root, 30);
	root = addNode(root, 20);
	root = addNode(root, 15);
	root = addNode(root, 25);
	root = addNode(root, 40);
	root = addNode(root, 38);
	root = addNode(root, 45);
	createThreadedTree(root);
	
	return 0;
}
