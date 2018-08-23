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

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

Node *findLastNode(Node *head){
	Node *current = head;
	while(current && current->next){
		current = current->next;
	}
	return current;
}
Node* partition(Node *low, Node *high)
{
    // set pivot as highest element
    int x  = high->data;

    //Current low points to previous of low of this part of array. 
    Node *currentLow = low->prev;
 
    for (Node *current = low; current != high; current = current->next)
    {
    	//Move in the array till current node data is less than the pivot
        if (current->data <= x)
        {
            //set the current low appropriately
            currentLow = (currentLow == NULL)? low : currentLow->next;
            swap(&(currentLow->data), &(current->data));
        }
    }
    //Now swap the next node of current low with pivot
    currentLow = (currentLow == NULL)? low : currentLow->next;
    swap(&(currentLow->data), &(high->data));
    
    //return current low as partitioning point.
    return currentLow;
}
 
/* A recursive implementation of quicksort for linked list */
void quickSortUtil(Node* low, Node *high)
{
    if (high != NULL && low != high && low != high->next)
    {
        Node *p = partition(low, high);
        quickSortUtil(low, p->prev);
        quickSortUtil(p->next, high);
    }
}
 
// The main function to sort a linked list. It mainly calls _quickSort()
void quickSort(Node *head)
{
    // Find last node of list
    Node *h = findLastNode(head);
    
    quickSortUtil(head, h);
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
 
    quickSort(L1);
    printList(L1);
    
    return 0;
}
