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
 
void pushNodeBeforeHead(Node **headRef, int value){
	//create new node
	Node *temp = createNode(value);
	
	/* Special case when this is first node to be insert,
	head node points to itself */ 
	if(!(*headRef)) {
		*headRef = temp;
 	}
 	else
 	{
 		//add next of new node to point to head
 		temp->next = *headRef;
 		
 	 	//point prev of last head to new node
 		(*headRef)->prev = temp;
 
 		//Change headRef to point to new head.
 		*headRef = temp;
 	}
}
 

/* Driver program to run above code */
int main(){
	Node * L1 = NULL;
 
    pushNodeBeforeHead(&L1,1);
    pushNodeBeforeHead(&L1,10);
    pushNodeBeforeHead(&L1,12);
    pushNodeBeforeHead(&L1,6);
    pushNodeBeforeHead(&L1,7);
    pushNodeBeforeHead(&L1,2);
 
    printList(L1);
    printListReverse(L1);
 
    return 0;
}
