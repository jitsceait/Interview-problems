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
    struct node *element;
    struct queue *next;
};
typedef struct queue Queue;

void enqueue(Queue **queue, Node *node){
	Queue *q  = NULL;
	Queue *head  = *queue;
	
	if(*queue == NULL){
		//This is the first node in the queue
		q =(Queue *)malloc(sizeof(Queue));
		q->element = node;
		q->next = NULL;
		*queue = q;
	}
	else{
		q = *queue;
		//Get to the last node, can be optimized by keeping the last pointer.
		while(q->next)
			q = q->next;
		
		Queue *temp =(Queue *)malloc(sizeof(Queue));
		q->next = temp;
		temp->element = node;
		temp->next = NULL;
		*queue = head;
	}
}
int isEmpty( Queue *queue){
	if(queue != NULL)
		return 0;
		
	return 1;
}
Node * front(Queue *queue){
	if(!isEmpty(queue))
		return queue->element;
		
	return NULL;
}

void dequeue(Queue **queue){
	Queue *q = *queue;
	
	Queue *temp = q;
	q = temp->next;
	temp = NULL;
	free(temp);
	*queue = q;
}
 
Node * createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	return newNode;
}

Node * addNode(Node *node, int value){
	if(node == NULL){
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

void treeToList(Node *root, Node **headPointer){
	
	Queue *queue = NULL;
	Node * last = NULL;
	
	//If tree is null to start with, return
	if(!root)
		return ;
		
	//If there is a node, enqueue the first node
	enqueue(&queue, root);
	
	//Now, till the time there is a node in queue, repeat
	while(!isEmpty(queue)){
		/* Take the first element and put both left and right child on queue */
		Node * currentNode = front(queue);
		printf("Dequeue : %d\n", currentNode->value );
		if(currentNode->left)
			enqueue(&queue, currentNode->left);
		if(currentNode->right)
			enqueue(&queue, currentNode->right);
	
		//If last node is not null, it's right must point to current node.
		if(last)
			last->right = currentNode;
        else{
        	*headPointer = currentNode; 
        }
        
        //Current node's left should point to last node we processed. 
        currentNode->left = last;
        //Update the last node to current Node.
        last = currentNode;
        
        //Take the node out of queue.
        dequeue(&queue);
	}

} 
/* Driver program for the function written above */
int main(){
        Node *root = NULL;
        Node * head = NULL;
       //Creating a binary tree
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);
        
        treeToList(root,&head);
        
        Node *current = head;
        while(current){
        	printf("%d ", current->value);
        	current = current->right;
        }
        
        return 0;
}
