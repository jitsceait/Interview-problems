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

void insertSort(Node **headRef){
	Node *result = NULL;
	Node *current  = *headRef;
	Node *next = NULL;
	
	while(current){
		//save next
		next  = current->next;
		sortedInsert(&result, current);
		current = next;
	}
	*headRef = result;
}
 
 
void printList(Node * head){
    while(head){
        printf("%d->" , head->data );
        head = head->next;
    }
 
    printf("NULL");
    printf("\n");
}

void push(Node **headRef, int value){
	Node *temp = createNode(value);
	temp->next = *headRef;
	*headRef = temp;
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
    insertSort(&L1);
    
    printList(L1);
    
    return 0;
}
