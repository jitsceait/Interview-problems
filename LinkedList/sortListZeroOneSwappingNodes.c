#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
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
	
	return result;
}

void sortListZeroOneSwappingNodes(Node **head){
	if(!*head) return;
	
	Node *tempHead = *head;
	Node *current = *head;
	
	while(current && current->next){
		current  = current->next;
	}
	
	Node *finalEnd = current;
	Node *twoTail = current;
	current = *head;
	int firstOne = 1;
	Node *prev = NULL;
	
	while(current != finalEnd){
	 	Node *next = current->next;
	 	if(current->data == 0){
			//If the node is 0, then put it at ths start.
	 		//If it is first node, then skip it.
			if(current != *head){
	 		 	current->next = *head;
	 			*head = current;
	 		 }
	 		current = next;
	 	}
	 	else if (current->data == 1){
			//If this is first node with data one and it is not one.
			 if(firstOne && current != tempHead){
			 	firstOne = !firstOne;
			 	tempHead->next = current;
			 }
	 		//skip node;
	 		if(prev){
	 			prev->next = current;
	 		}
	 		prev = current;
	 		current = next;
	 	}
	 	else{
	 		//Add at the end of the list
			 twoTail->next = current;
			 twoTail = current;
			 current->next = NULL;
	 		 current = next;
	 	}
	 }
	 
	 //Handle last node
	 if(finalEnd->data == 0){
	 		current->next = *head;
	 		*head = current;
	 }
	 if(finalEnd->data == 1){
	 		prev->next = finalEnd;
	 }
	 //If it one or two, nothing to do.
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
        sortListZeroOneSwappingNodes(&L1); 
        printList(L1);
 
        return 0;
}


