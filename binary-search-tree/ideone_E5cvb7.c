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

#define true 1
#define false 0

int isIdenticalBST(Node *node1, Node *node2){
	if(!node1 && !node2) return true;
	
	if(!node1 || !node2) return false;
	
	return (node1->value==node2->value 
			&& isIdenticalBST(node1->left, node2->left)
			&& isIdenticalBST(node1->right, node2->right));
}

int isSubtree(Node *node1, Node * node2){
	if(!node1) return false;
	if(!node2) return true;
	
	if (isIdenticalBST(node1, node2)) return true;
	
	return isSubtree(node1->left, node2) || isSubtree(node1->right, node2);
}

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
	
	Node *root2 = NULL;
	root2 = addNode(root2, 40);
	root2 = addNode(root2, 35);
	root2 = addNode(root2, 39);
	root2 = addNode(root2, 45);
	int height = 0;
	printf( "Is tree subtree : %s", 
			isSubtree( root, root2 ) ? "Yes" : "No" );
	
	return 0;
}
