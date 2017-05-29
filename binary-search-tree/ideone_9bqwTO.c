#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

void findSecondMaximum( Node * root, int *count, int K ){
	if( !root ) return;
	
	findSecondMaximum(root->right, count, K);
	
	if( ++(*count) == K ){
		printf("\n %dth element in tree : %d", K, root->value);
		return;
	}
	if( *count < K ){
		//Processing left subtree only if count is still less than K
		findSecondMaximum(root->left, count, K);
	}
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
	if(!node){
		return createNode(value);
	}
	if (node->value > value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value );
		
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
	root = addNode(root, 45);
	printf("\nInorder traversal of tree is : ");
	inoderTraversal(root);
	printf("\n");
	int count = 0;
	int K = 2;
	findSecondMaximum(root, &count, K);
	
	return 0;
}
