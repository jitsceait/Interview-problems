#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

void inorder( Node * currentNode){
	
	if(!currentNode) return;
	
	inorder(currentNode->left);
	printf("%d ", currentNode->value);
	inorder(currentNode->right);
}

Node * pruneNodes(Node *currentNode, int min, int max){
	
	if(!currentNode) return currentNode;
	
	currentNode->left =  pruneNodes(currentNode->left, min, max);
	currentNode->right = pruneNodes(currentNode->right, min, max);
	if(currentNode->value < min){
		Node * rightTree = currentNode->right;
		free(currentNode);
		
		return rightTree;
	}
	if (currentNode->value > max){
		Node *leftTree = currentNode->left;
		free(currentNode);
		
		return leftTree;
	}
	return currentNode;
}
Node * createNode(int value){
	
	Node * newNode =  (Node *)malloc(sizeof(Node));
	
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	
	return newNode;
}
Node * addNode(Node *node, int value){
	
	if(!node){
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
        
        inorder(root);
        root = pruneNodes(root, 50,60); 
        printf("\n");
        if(root)
        	inorder(root);
        return 0;
}
