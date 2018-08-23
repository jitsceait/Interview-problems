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
    while(current->next != head){
        printf("%d->" , current->data );
        current = current->next;
    }
 
    printf("%d", current->data);
    printf("\n");
}
 
void push(Node **headRef, int value){
	//create new node
	Node *temp = createNode(value);
	/* Special case when this is first node to be insert,
	head node points to itself */ 
	if(!(*headRef)) {
		temp->next = temp;
		*headRef = temp;
 	}
 	else
 	{
 		//find the last node
 		Node *current = *headRef;
 		while(current->next != *headRef){
 			current = current->next;
 		}
 		//current now points to last node.
 		
 		//add next of new node to point to head
 		temp->next = *headRef;
 		//Last node now points to new head.
 		current->next = temp;
 		
 		//Change headRef to point to new head.
 		*headRef = temp;
 	}
}
 
void removeNode(Node **headRef, int value){
	Node *current = *headRef;
	if(!current) return;
	Node *prev = NULL;

    //Special case when node to be removed is head
    if(current->data == value){
    	//Find last node
    	Node * temp = current;
    	while(temp->next != current){
    		temp = temp->next;
    	}
    	temp->next =  current->next;
    	*headRef = current->next;
    	free(current);
    }
    else{
		while(current->next != *headRef && current->data != value){
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		free(current);
    }
}
/* Driver program to run above code */
int main(){
	Node * L1 = NULL;
 
    push(&L1,1);
    push(&L1,10);
    push(&L1,12);
    push(&L1,6);
    push(&L1,7);
    push(&L1,2);
 
    printList(L1);
    
    removeNode(&L1, 12);
    printList(L1);
    
    return 0;
}
