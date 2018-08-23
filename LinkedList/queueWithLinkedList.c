#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  if(temp){
    temp->data = val;
    temp->next = NULL;
  }
  return temp;
}

void enqueue(Node **lastPtrRef, Node *node){
	//Just add node at the end.
	(*lastPtrRef) = node;
}

Node *dequeue(Node **headRef){
	
	if(!(*headRef)) {
		printf("\n Queue is empty");
		return NULL;
	}
	Node *returnNode = *headRef;
	*headRef = (*headRef)->next;
	
	return returnNode;
	
}
void printList(Node * head){
    while(head){
        printf("%d->" , head->data );
        head = head->next;
    }
 
    printf("NULL");
    printf("\n");
}
 
 
/* Driver program to run above code */
int main(){
        Node * L1 = NULL;
        Node **lastPtrRef = &L1;
        
        enqueue(lastPtrRef, createNode(3));
        lastPtrRef = &((*lastPtrRef)->next);
        enqueue(lastPtrRef, createNode(2));
        lastPtrRef = &((*lastPtrRef)->next);
        enqueue(lastPtrRef, createNode(1));
        lastPtrRef = &((*lastPtrRef)->next);
        
        printList(L1);
        
        dequeue(&L1);
        printList(L1);
        return 0;
}
