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
 
/* Function to insert a node at the beginging of the linked list */
void moveNodeEnd(Node** lastPtrRef, Node **sourceRef)
{
    /* New node is allocated */
    Node * newNode = *sourceRef;
 
    *sourceRef = newNode->next;
 
    newNode->next = NULL;
    /* link the old list off the new node */
    *lastPtrRef = newNode;
}
 
void rotateLinkedList(Node **head, int K){
	Node *KthNode = NULL;
	Node *current = *head;
	
	if(!(*head)) return NULL;
	
	for(int i=1; i<K && current; i++){
		current = current->next;
	}
	
	if(current){
		KthNode = current;
		
		while(current->next){
			current = current->next;
		}
		//Current now points to last node
		//Link last node to head node
		current->next = *head;
		
		*head = KthNode->next;
		KthNode->next = NULL;
	}
}
 
/* Driver program to run above code */
int main(){
        Node * L1 = NULL;
 
        push(&L1,12);
        push(&L1,10);
        push(&L1,8);
        push(&L1,6);
        push(&L1,4);
        push(&L1,2);
 
 		printList(L1);

		rotateLinkedList(&L1, 2);
 
		printList(L1);
 
        return 0;
}
