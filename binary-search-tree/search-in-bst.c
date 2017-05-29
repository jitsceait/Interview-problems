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
    if(!root) return;
	
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
    if(!node)
	    return createNode(value);
    else{
	    if (node->value > value)
            node->left = addNode(node->left, value);
        else
            node->right = addNode(node->right, value);
	}
    
	return node;
}

Node * search( Node * root, int searchedKey){
    if(!root) return root;
	
    if( root->value == searchedKey)
        return root;
	else if ( root->value > searchedKey) {
        //search in left subtree
		return search( root->left, searchedKey);
	}
    else{
        //search in right subtree
	    return search( root->right, searchedKey);
    }
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
	
    Node * searchedNode = search( root, 15);
    if(searchedNode)
		printf("\n Node found ");
	else
	    printf("\n Node not found ");
	
    return 0;
}
