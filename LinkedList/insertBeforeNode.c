#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} Node;
 
Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  if(temp){
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
  }
  return temp;
}
 
void printList(Node * head){
	Node * current = head;
    while(current){
        printf("%d->" , current->data );
        current = current->next;
    }
 
    printf("NULL");
    printf("\n");
}

void printListReverse(Node * head){
	Node * current = head;
    while(current->next){
        current = current->next;
    }
 
    while(current){
    	printf("%d->", current->data);
        current = current->prev;
    }
 
    printf("NULL");
    printf("\n");
}

void pushNodeAtEnd(Node **headRef, int value){
	//create new node
	Node *newNode = createNode(value);
 
	/* Special case when this is first node to be insert,
	head node points to itself */ 
	if(!(*headRef)) {
		*headRef = newNode;
 	}
 	else
 	{
 		//move to end of list
 		Node *current = *headRef;
 
 		while(current->next){
 			current = current->next;
 		}
 		//current node is now last node
 
 		current->next = newNode;
 
 	 	//point prev of new node to last node
 		newNode->prev = current;
 	}
}
 
void insertBeforeNode(Node **headRef, Node *givenNode, int value){
	//create new node
	Node *newNode = createNode(value);
	
	//save previous node
	Node *nextNode = givenNode->next;
	
 	//Make next of givenNode point to new node
 	givenNode->next = newNode;
 	
 	//Make previous of nextNode to point new node
 	if(nextNode)
 		nextNode->prev = newNode;
 	
 	//Make previous of new node point to givenNode
 	newNode->prev = givenNode;
 	
 	//Make previous of new node to point to prevNode
 	newNode->next  = nextNode;

}
 
/* Driver program to run above code */
int main(){
	Node * L1 = NULL;
 
    pushNodeAtEnd(&L1,1);
    pushNodeAtEnd(&L1,10);
    pushNodeAtEnd(&L1,12);
    pushNodeAtEnd(&L1,6);
    
    Node *givenNode = L1;
    
    pushNodeAtEnd(&L1,7);
    pushNodeAtEnd(&L1,2);
 
    printList(L1);
    printListReverse(L1);
    
    insertBeforeNode(&L1,givenNode,17);
    printf("\nAfter Insertion after node : %d\n", givenNode->data);
    printList(L1);
    printListReverse(L1);
    return 0;
}
