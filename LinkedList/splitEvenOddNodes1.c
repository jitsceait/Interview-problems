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
 
void splitEvenOddNodes(Node *head, Node **evenList,Node **oddList){
	//create start of list a;
	Node *a = NULL;
	//create start of list a;
	Node *b = NULL;
 
	Node **lastPtrRefEven = &a;
	Node **lastPtrRefOdd = &b;
 
	Node *current  = head;
	while(current){
		//even node
		if(current->data%2 == 0){
			//Moving current node to even list
			moveNodeEnd(lastPtrRefEven, &current);
			lastPtrRefEven = &((*lastPtrRefEven)->next);
		}
		//Odd node
		else{
			//Moving current node to odd list
			moveNodeEnd(lastPtrRefOdd,&current);
			lastPtrRefOdd = &((*lastPtrRefOdd)->next);
		}
	}
	*evenList = a;
	*oddList = b;
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
 
 		Node *a = NULL;
		Node *b = NULL;
 
		splitEvenOddNodes(L1, &a,&b);
 
		printList(a);
		printList(b);
 
        return 0;
}
