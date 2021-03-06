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

void postorderTraversalWithoutRecursion(Node *root){
    stack ms;
    ms.top = -1;
    if(root == NULL) return ;

    Node *currentNode = NULL ;
    push(&ms,root);
    Node *prev = NULL;
    
    while(!isEmpty(ms)){
        currentNode = peek(ms);
        /* case 1. We are nmoving down the tree. */
        if(prev == NULL || prev->left == currentNode || prev->right == currentNode){
			if(currentNode->left)
				push(&ms,currentNode->left);
			else if(currentNode->right)
				push(&ms,currentNode->right);
			else {
                /* If node is leaf node */
                printf("%d ", currentNode->value);
                pop(&ms);
            }
        }
         /* case 2. We are moving up the tree from left child */
        if(currentNode->left == prev){
            if(currentNode->right)
                push(&ms,currentNode->right);
            else {
                printf("%d ", currentNode->value);
                pop(&ms);
            }
         }

        /* case 3. We are moving up the tree from right child */
         if(currentNode->right == prev){
              printf("%d ", currentNode->value);
              pop(&ms);
         }
         prev = currentNode;
      }

}

void postorder (Node * root){
	if ( !root ) return;
 
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->value );
 
}
 
Node * createNode(int value){
    Node * newNode =  (Node *)malloc(sizeof(Node));
	
    newNode->value = value;
    newNode->right= NULL;
    newNode->left = NULL;
	
    return newNode;
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
	
        postorder(root);
        printf("\n");
	
        postorderTraversalWithoutRecursion(root);
        return 0;
}
