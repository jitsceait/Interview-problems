#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
    struct node *next; //new pointer
};
typedef struct node Node;

Node * createNode(int value){
	
    Node * newNode =  (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->next = NULL;
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

#define MAX(a,b)  (a>b) ?(a):(b)

void connect(Node* p) {
	
  if (!p) return;
  
  if (p->left)
  	p->left->next = p->right;
  
  if (p->right)
    p->right->next = (p->next) ? p->next->left : NULL;
    
  connect(p->left);
  connect(p->right);
}

//Driver program
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
	
	connect(root);
	
	return 0;
}