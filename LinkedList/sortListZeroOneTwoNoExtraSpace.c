#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
void sortListZeroOneTwoNoExtraSpace(Node *head){
	if(!head) return;
	
	int count[3] = {0,0,0};
	Node *current = head;
	while(current){
		count[current->data]++;
		current = current->next;
	}
	current = head;
	for(int i=0; i<3; i++){
		while(count[i]){
	        current->data = i;
			count[i]--;
			current = current->next;
		}
	}
	
	return;
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
        push(&L1,2);
        push(&L1,1);
        push(&L1,2);
        push(&L1,2);
        push(&L1,1);
        push(&L1,1);
        
 		printList(L1);
        sortListZeroOneTwoNoExtraSpace(L1); 
        printList(L1);
 
        return 0;
}


