#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
Node * mergeAtAlternatePositions(Node *a, Node *b){
    Node *aCurr = a;
    Node *bCurr = b;
    
    while(aCurr && bCurr){
    	Node *aNext = aCurr->next;
    	Node *bNext = bCurr->next;
    	
    	//Point next pointer of list a to node in list b
    	bCurr->next = aCurr->next;
    	//Point next pointer of list b to node in list a
    	aCurr->next = bCurr;
    	
    	//Now advance pointers to next nodes
    	aCurr = aNext;
    	bCurr = bNext;
    }
    return a;
}
 
Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  if(temp){
    temp->data = val;
    temp->next = NULL;
  }
  return temp;
}
/* This function inserts node at the head of linked list */
void push(Node **headRef, int data){
	Node * newNode  = createNode(data);
	newNode->next = *headRef;
	*headRef  = newNode;
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
        Node * L2 = NULL;
        /* creating list 1 */
        push(&L1,7);
        push(&L1,6);
        push(&L1,4);
        push(&L1,3);
        /* creating list 2 */
        push(&L2,10);
        push(&L2,8);
        push(&L2,1);
        
 		printList(L1);
 		printList(L2);
        L1 = mergeAtAlternatePositions(L1,L2); 
        printList(L1);
 
        return 0;
}


