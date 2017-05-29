#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define MAX(a,b)  a>b ?a:b

struct node{
        int value;
        struct node *left;
        struct node *right;
};
typedef struct node Node;

int height(Node *root){
    if(root == NULL)
        return 0;
 
    if(!root->left && !root->right)
        return 1;
 
    int lheight = height(root->left);
    int rheight = height(root->right);
 
    return 1+ (MAX(lheight, rheight));
}

void zigzagTraversalRecursive(Node * node, int desired, int ltr){
  if(node == NULL) return;

   if (desired == 1)
      printf("%d  ", node->value);
      /* Based on the flag call the recursive function accordingly */
      if(ltr){
        zigzagTraversalRecursive(node->left, desired-1, ltr);
        zigzagTraversalRecursive(node->right, desired-1, ltr);
       }
       else{
          zigzagTraversalRecursive(node->right, desired-1, ltr);
          zigzagTraversalRecursive(node->left, desired-1, ltr);
       }
}

void spiralLevelOrderTraversal(Node *root){
    int h = height(root);
    int i;
    int ltr = 1;
    for(i=1; i<=h; i++){
      printf("\n Level %d :", i);
      /* initially passing it to left to right */
      zigzagTraversalRecursive(root, i, ltr);
      /* For next iteration (level), it will be reversed */
      ltr = !ltr;
      printf("\n");
    }
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
        Node * last = NULL;
        Node *ptrToHead = NULL;
        //Creating a binary tree
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);
        
        spiralLevelOrderTraversal(root);
        return 0;
}
