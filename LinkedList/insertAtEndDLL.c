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
 
//Add node to sorted list
void sortedInsert(Node **headRef, Node *newNode){
 
	//Start with refercing to head.
	Node **current = headRef;
 
	//Till we find that data of next node is greater than value
	//here current is reference to next node.
	while(*current && (*current)->data < newNode->data){
		current = &((*current)->next);
	}
 
	//New node's next should point to next node. 
	newNode->next = *current;
 
	//As current is reference to next node, that has to be set to new node.
	*current = newNode;
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
 
/* Driver program to run above code */
int main(){
	Node * L1 = NULL;
 
    pushNodeAtEnd(&L1,1);
    pushNodeAtEnd(&L1,10);
    pushNodeAtEnd(&L1,12);
    pushNodeAtEnd(&L1,6);
    pushNodeAtEnd(&L1,7);
    pushNodeAtEnd(&L1,2);
 
    printList(L1);
    printListReverse(L1);
 
    return 0;
}


