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

void replaceWithSumOfGreaterNodesUtil(Node * root, int *sum){
    if(!root) return;
    
    replaceWithSumOfGreaterNodesUtil(root->right, sum);
	
    //At this point sum contains sum of all nodes greater than node
    int temp = root->value;
    root->value = *sum;
    *sum = *sum + temp;
	
     replaceWithSumOfGreaterNodesUtil(root->left, sum);
}

void replaceWithSumOfGreaterNodes(Node * root){
     int sum = 0;
     replaceWithSumOfGreaterNodesUtil(root, &sum);
}

void inorder(Node * root){
     if(!root) return;
	
     inorder(root->left);
     printf("%d ", root->value);
     inorder(root->right);
}

Node *createNode(int value){
     Node * newNode =  (Node *)malloc(sizeof(Node));
     
     newNode->value = value;
     newNode->right= NULL;
     newNode->left = NULL;
	
     return newNode;
}

Node *addNode(Node *node, int value){
    if(!node)
	    return createNode(value);

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
    root = addNode(root, 37);
    root = addNode(root, 45);
	
    printf("\n Inorder before modification");
    inorder(root);
	
    replaceWithSumOfGreaterNodes(root);
	
    printf("\n Inorder after modification");
    inorder(root);
	
    return 0;
}
