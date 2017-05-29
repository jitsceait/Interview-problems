#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

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
Node *addNode(Node *node, int value, int K){
	if(!node){
		return createNode(value);
	}
	if ( node->value + K > value && node->value - K < value ){
		return node;
	}
	if (node->value > value)
		node->left = addNode(node->left, value, K);
	else
		node->right = addNode(node->right, value, K);
		
	return node;
}

/* Driver program for the function written above */
int main(){
	Node *root = NULL;
	//Creating a binary tree
	root = addNode(root, 30, 3);
	root = addNode(root, 20, 3);
	root = addNode(root, 15, 3);
	root = addNode(root, 25, 3);
	root = addNode(root, 40, 3);
	root = addNode(root, 38, 3);
	root = addNode(root, 45, 3);
	inoderTraversal(root);
	
	return 0;
}
