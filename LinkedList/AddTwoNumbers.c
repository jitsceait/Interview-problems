#include<stdlib.h>
#include<stdio.h>

typedef struct node{
	int data;
	struct node *next;
} Node;


int length( Node * head ){
	int len = 0;
	Node * current  = head;
	while(current){
		len++;
		current = current->next;
	}
	return len;
}

Node * createNode(int value){
	
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;

}
/* Addition of a node to linked list */
void push(Node **head, int value){
	
	Node *newNode = createNode (value);
	if(!(*head) ){
		*head = newNode;
	}
	else{
		newNode->next = (*head);
		*head = newNode;
	}
}
/* This function is actually helper function which does all house keeping like 
calculating lengths of lists,calling recursive implementation, creating extra 
node for carry in MSD,and adding any remaining nodes left in longer list. */

/* result is pointer to pointer to the head of resulting node */ 
void addTwoNumbers(Node *L1, Node *L2, int *carry, Node  **result){
	int len1 = length( L1 );
	int len2 = length( L2 );
	int diff = 0;
	
	if(len1 < len2){
		Node * current = L1;
		L1 = L2;
		L2 = current;
    }
    diff = abs(len1-len2);
    Node * current = L1;
    
    while(diff--)
    	current = current->next;
    	
    /* Call the recursive implementation */
    addListRecursively(current, L2, carry, result);
    
    diff = abs(len1-len2);
    
    /* Add remaining nodes in longer list */
    addRemainingDigits(L1, carry, result, diff);
    
    if(*carry){
    	push(result, *carry);
    }
    return;
}
void addListRecursively(Node *L1, Node *L2, int *carry, Node **result){

        int sum;
        if(!L1)
            return;

        addListRecursively(L1->next, L2->next, carry, result);

        /*We have reached the last node of both lists, add them */
        sum = L1->data + L2->data + (*carry);
       
        int value = sum%10;
		*carry = sum/10;
        push(result, value);
       
        return;
}
void addRemainingDigits(Node *L1, int *carry, Node **result, int diff){
	int sum =0;
	
	if(!L1 || !diff)
		return;
	addRemainingDigits(L1->next, carry, result, diff-1);
	
	sum = L1->data + (*carry);
	int value = sum%10;
	*carry = sum/10;
    
    push(result, value);
    
    return;
}

void printList( Node * head ){
	Node * current = head;
	while(current){
		printf("%d ->", current->data);
		current = current->next;
	}
	printf("NULL");
}
/* Driver program to run above code */
int main(){
        Node * L1 = NULL;
        Node * L2 = NULL;
        Node * result = NULL;
        int carry = 0 ;
        /* creating list 1 */
        push(&L1,3);
        push(&L1,4);
        push(&L1,6);
        push(&L1,7);
        /* creating list 2 */
        push(&L2,8);
        push(&L2,9);
        push(&L2,7);
      
        printList(L1);
        printf("\n");
        printList(L2);
        
        addTwoNumbers(L1,L2, &carry, &result);
        printf("\n");
        printList(result);
        return 0;
}
