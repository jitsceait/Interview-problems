#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
Node * mergeSort(Node *a, Node *b, int flag){
    Node *result = NULL;
    if(a ==  NULL)
        return b;
    else if(b == NULL)
        return a;
 
    /* For the first node, we would set the result to either a or b */
      if(flag){
         result = a;
        /* Result's next will point to smaller one in lists 
           starting at a->next  and b */
         result->next = mergeSort(a->next,b, !flag);
      }
      else {
        result = b;
       /*Result's next will point to smaller one in lists 
         starting at a and b->next */
        result->next = mergeSort(a,b->next,!flag);
      }
      return result;
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
        push(&L1,7);
        push(&L1,6);
        push(&L1,4);
        push(&L1,3);
        /* creating list 2 */
        push(&L2,10);
        push(&L2,8);
        push(&L2,1);
        
 		printList(L1);
 		printList(L2);
        L1 = mergeSort(L1,L2,1); 
        printList(L1);
 
        return 0;
}
