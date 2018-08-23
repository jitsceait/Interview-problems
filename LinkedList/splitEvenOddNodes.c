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
 
    Node * current = head;
    
    //Find the tail of list
    while(current && current->next){
    	current = current->next;
    }
    
    Node *initialEnd = current;
    Node **lastPtrRefOdd = &(initialEnd->next);
    
    //Move all nodes before first even node to end
    current = head;
    while(current && current->data%2 != 0){
    	moveNodeEnd(lastPtrRefOdd, &current);
    	lastPtrRefOdd = &((*lastPtrRefOdd)->next);
    }
    
    Node * prev;
    while(current && current != initialEnd){
    	//Even node
    	if(current->data%2 == 0){
    		//first even node
    		if(*evenList == NULL){
    			*evenList = current;
    		}
    		prev = current;
    		current = current->next;
    	}
    	else{
    		//Odd node
    		moveNodeEnd(lastPtrRefOdd, &current);
    		lastPtrRefOdd = &((*lastPtrRefOdd)->next);
    		prev->next = current ; //notice current is already advanced.
    	}
    }
    
    //Save the next node, it will be start of odd list
    *oddList = initialEnd->next;
    initialEnd->next = NULL;
    
    if(initialEnd->data%2 != 0){
    	moveNodeEnd(lastPtrRefOdd, &initialEnd);
    	lastPtrRefOdd = &((*lastPtrRefOdd)->next);
    }
}
 
/* Driver program to run above code */
int main(){
        Node * L1 = NULL;
 
        push(&L1,12);
        push(&L1,10);
        push(&L1,1);
        push(&L1,6);
        push(&L1,5);
        push(&L1,2);
 
 		printList(L1);
 
 		Node *a = NULL;
		Node *b = NULL;
 
		splitEvenOddNodes(L1, &a,&b);
 
		printList(a);
		printList(b);
 
        return 0;
}
