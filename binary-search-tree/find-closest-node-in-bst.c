#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

#define true 1
#define false 0

void findClosestNode(Node *root, int value, int *min){
	if(!root)
		return;
		
	int diff = root->value - value;
	
	if(abs(*min) > abs(diff)){
		*min = diff;
	}
	/* Case 2 : Look for in left subtree */
	
	if(root->value > value)
		findClosestNode(root->left, value, min);
	else
	/* Case 3 : Look for in right subtree */ 
		findClosestNode(root->right, value, min);
}

void inoderTraversal(Node * root){
	if(!root)
		return;
	
	inoderTraversal(root->left);
	printf("%d ", root->value);
	inoderTraversal(root->right);
}
Node *createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	
	return newNode;
}

Node *addNode(Node *node, int value){
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
	int min = 99999;
	int value  = 27;
	//Creating a binary tree
	root = addNode(root,30);
	root = addNode(root,20);
	root = addNode(root,15);
	root = addNode(root,25);
	root = addNode(root,40);
	root = addNode(root,37);
	root = addNode(root,45);
	
	inoderTraversal(root);	
	findClosestNode( root, value, &min);
	
	printf("\nClosest node for %d is : %d", value, value + min );
	return 0;
}
