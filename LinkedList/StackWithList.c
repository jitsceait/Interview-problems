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
 
void push(Node **headRef, Node *node){
	if(!node) return;
	
	node->next = (*headRef);
	*headRef = node;
	
}
 
Node *pop(Node **headRef){
 
	if(!(*headRef)) {
		printf("\n Stack is empty");
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
 
        push(&L1, createNode(3));
        push(&L1, createNode(2));
        push(&L1, createNode(1));
       
        printList(L1);
 
        pop(&L1);
        printList(L1);
        return 0;
}
