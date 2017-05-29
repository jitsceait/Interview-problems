#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

void printRightView(Node * node, int currLevel, int *maxLevel){

	if(node == NULL) return;

	if(currLevel >  *maxLevel){
		printf("%d  ", node->value);
		*maxLevel = currLevel;
	}
	printRightView(node->right, currLevel+1, maxLevel);
	printRightView(node->left, currLevel+1, maxLevel);
}
/* driver program */
Node * createNode(int value){
	Node *temp =  (Node *)malloc(sizeof(Node));
	temp->value = value;
	temp->right= NULL;
	temp->left = NULL;
	return temp;
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

int main(){

    Node *root = NULL;
    //Creating a binary tree
    root = addNode(root,6);
    root = addNode(root,3);
    root = addNode(root,2);
    root = addNode(root,1);
    root = addNode(root,7);
    root = addNode(root,5);
    root = addNode(root,9);
    
    int max = -1;
    printRightView(root, 0, &max);

    return 0;
}
