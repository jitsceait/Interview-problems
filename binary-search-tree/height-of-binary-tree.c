#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

#define MAX(a,b)  (a < b ? b : a)

Node *createNode(int value){
    Node * newNode =  (Node *)malloc(sizeof(Node));
	
    newNode->value = value;
    newNode->right= NULL;
    newNode->left = NULL;
	
    return newNode;
}

Node *addNode(Node *node, int value){
    if(!node) return createNode(value);
        
    if (node->value > value)
        node->left = addNode(node->left, value);
    else
        node->right = addNode(node->right, value);
		
    return node;
}

int height( Node *root){
    if( !root ) return 0;
    
    int lheight = height( root->left);
    int rheight = height( root->right);
	
    return 1 + MAX (lheight, rheight );
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
    
    printf( "Height of tree is : %d", height( root));
    
    return 0;
}
