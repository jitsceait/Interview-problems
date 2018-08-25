#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
  int data;
  struct Node * next;
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
		printf("%d->", head->data);
		head = head->next;
	}
	printf("Null");
}

void deleteNAfterMNodes(Node *head, int n, int m){
	//If head is null return
	if(!head) return ;
	Node *current = head;
	while(current){
		//skip m nodes
		for(int i=0; i<m-1 && current; i++){
			current = current->next;
		}
		//There are nodes to delete
		if(current){
			Node *temp = current->next;
			Node *next;
			//Delete n nodes
			for(int i=0; i<n && temp; i++){
				next = temp->next;
				free(temp);
				temp = next;
			}
			//link the last node of m nodes to next node of n deleted nodes
			current->next = temp;
			//advance current pointer
			current = temp;
		}
	}
}
Node * deleteNAfterMNodesRecursive(Node *head, int n, int m, int skipNodes){
	//If head is null return
	if(!head) return NULL;
	Node *current  = head;
	if(skipNodes){
		//skip m nodes
		for(int i=0; i<m-1 && current; i++){
			current = current->next;
		}
		if(current){
			current->next = deleteNAfterMNodesRecursive(current,n,m,!skipNodes);
		}
		return head;
	}
	else{
		Node *temp = current->next;
		Node *next;
		//Delete n nodes
		for(int i=0; i<n && temp; i++){
			next = temp->next;
			free(temp);
			temp = next;
		}
		current->next = deleteNAfterMNodesRecursive(temp,n,m,!skipNodes);
		return temp;
	}
}


int main(){
	Node *head = NULL;
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	push(&head,1);
	push(&head,2);
	push(&head,4);
	int n = 2;
	int m = 3;
	printList(head);
	
	deleteNAfterMNodesRecursive(head,n,m,1);
	
	printList(head);
	return 0;
}
