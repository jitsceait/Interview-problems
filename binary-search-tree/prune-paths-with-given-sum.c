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

int prunePath(Node *node, int sum ){
	
	if( !node ) return true;
	
	int subSum =  sum - node->value;
	/* To check if left tree or right sub tree contributes to total sum  */
	
	int leftVal = false, rightVal = false;
	
	/*Check if node is leaf node */
	int isLeaf = !( node->left || node->right );
	
	/* If node is leaf node and it is part of path with sum  = given sum 
	return true to parent node so tha parent node is not deleted */
	if(isLeaf && !subSum )
		return true;
		
	/* If node is leaf and it not part of path with sum equals to given sum
    Return false to parent node */
    else if(isLeaf && subSum ){
    	free(node);
    	return false;
    }
    /* If node is not leaf and there is left child  Traverse to left subtree*/
    leftVal = prunePath(node->left, subSum);
    
    /* If node is not leaf and there is right child  Traverse to right subtree*/
    rightVal = prunePath(node->right, subSum);
    
    /* This is crux of algo.
    1. If both left sub tree and right sub tree cannot lead to path with 
    given sum,Delete the node 
    2. If any one sub tree can lead to path with sum equal to given sum, 
    do not delete the node */ 
    if(!(leftVal || rightVal) ){
    	free(node);
    	return false;
    }
    if(leftVal || rightVal ){
    	if(leftVal)
    		node->right = NULL;
    	if(rightVal)
    		node->left = NULL;
    	return true;
    }
    return true ;
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
	//Creating a binary tree
	root = addNode(root,30);
	root = addNode(root,20);
	root = addNode(root,15);
	root = addNode(root,25);
	root = addNode(root,40);
	root = addNode(root,37);
	root = addNode(root,45);
	
	inoderTraversal(root);	
	prunePath(root, 65);
	
	printf( "\n");
	if( root ){
		inoderTraversal(root);	
	}
	return 0;
}
