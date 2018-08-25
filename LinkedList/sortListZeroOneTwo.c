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
void sortListZeroOneTwo(Node *head, Node**result){
	if(!head) return;
	
	int count[3] = {0,0,0};
	Node *current = head;
	while(current){
		count[current->data]++;
		current = current->next;
	}
	
	for(int i=2; i>=0; i--){
		while(count[i]){
			push(result, i);
			count[i]--;
		}
	}
	return;
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
        sortListZeroOneTwo(L1, &L2); 
        printList(L2);
 
        return 0;
}
