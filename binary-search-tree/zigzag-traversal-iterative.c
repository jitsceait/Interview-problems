#include <stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

#define STACK_SIZE 10
 
typedef struct stack{
        int top;
        Node *items[STACK_SIZE];
}stack;
 
void push(stack *ms, Node *item){
   if(ms->top < STACK_SIZE-1){
       ms->items[++(ms->top)] = item;
   }
   else {
       printf("Stack is full\n");
   }
}
 
Node * pop (stack *ms){
   if(ms->top > -1 ){
       return ms->items[(ms->top)--];
   } 
   else{
       printf("Stack is empty\n");
   }
}
Node * peek(stack ms){
  if(ms.top < 0){
      printf("Stack empty\n");
      return 0;
   }
   return ms.items[ms.top];
}
int isEmpty(stack ms){
   if(ms.top < 0) return 1;
   else return 0;
}

void zigzagTraversal(Node * root){
	stack s1, s2;
	s1.top = -1;
	s2.top = -1;
	
	if(root == NULL ) return;
	
	push(&s1, root);
	
	while(!isEmpty(s1) || !isEmpty(s2)){
		printf("\n");
		while(!isEmpty(s1)){
			Node *currentNode = pop(&s1);
			printf("%d " , currentNode->value);
			if(currentNode->right)
				push(&s2, currentNode->right);
			if(currentNode->left)
				push(&s2, currentNode->left);
        }
        printf("\n");
        while(!isEmpty(s2)){
        	Node *currentNode = pop(&s2);
        	printf("%d " , currentNode->value);
        	if(currentNode->left)
        		push(&s1, currentNode->left);
        	if(currentNode->right)
        		push(&s1, currentNode->right);
        }
    }
}
 
Node * createNode(int value){
    Node * temp =  (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->right= NULL;
    temp->left = NULL;
    return temp;
}
Node * addNode(Node *node, int value){
    if(node == NULL){
    	return createNode(value);
    }
    else{
    	if (node->value > value){
    		node->left = addNode(node->left, value);
    	}
    	else{
    		node->right = addNode(node->right, value);
    	}
    }
    return node;
}
 
/* Driver program for the function written above */
int main(){
        Node *root = NULL;
        //Creating a binary tree
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);
        zigzagTraversal(root);
        return 0;
}
