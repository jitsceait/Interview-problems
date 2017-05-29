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
#define MAX(a,b)  (a < b ? b : a)

Node *createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	
	return newNode;
}
Node *addNode(Node *node, int value){
	if(!node){
		return createNode(value);
	}
	if (node->value > value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value);
		
	return node;
}

int isHeightBalanced( Node * root, int *height ){
	if(!root){
		*height = 0;
		return true;	
	} 
	
	int lheight = 0, rheight = 0;
	int lBalanced = isHeightBalanced( root->left, &lheight );
	int rBalanced = isHeightBalanced( root->right, & rheight );
	
	//Update the height
	*height = 1 + MAX ( lheight, rheight);
	
	//Check if difference between two height is more than 1
	if (abs( lheight-rheight) > 1 ) return false;
	
	return lBalanced && rBalanced;
		  
}
/* Driver program for the function written above */
int main(){
	Node *root = NULL;
	//Creating a binary tree
	root = addNode(root, 30);
	root = addNode(root, 20);
	root = addNode(root, 15);
	root = addNode(root, 25);
	root = addNode(root, 40);
	root = addNode(root, 38);
	root = addNode(root, 39);
	root = addNode(root, 45);
	
	int height = 0;
	printf( "Is tree height balanced : %s", 
			isHeightBalanced( root, &height ) ? "Yes" : "No" );
	
	return 0;
}
