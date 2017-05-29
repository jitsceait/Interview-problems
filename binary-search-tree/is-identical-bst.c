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
    if(!node) return createNode(value);
    
    if (node->value > value)
        node->left = addNode(node->left, value);
    else
        node->right = addNode(node->right, value);
    
    return node;
}

int isIdenticalBST( Node * firstTree, Node *secondTree){
    if( ! (firstTree || secondTree ) ) //both of them are empty
        return true;
    
    if( !( firstTree && secondTree ) ) // one of them is empty
        return false;
    
    return ( firstTree->value == secondTree->value )
        && isIdenticalBST( firstTree->left, secondTree->left )
        && isIdenticalBST( firstTree->right, secondTree->right );
}

/* Driver program for the function written above */
int main(){
    Node *firstRoot = NULL;
	
    //Creating a binary tree
    firstRoot = addNode(firstRoot, 30);
    firstRoot = addNode(firstRoot, 20);
    firstRoot = addNode(firstRoot, 15);
    firstRoot = addNode(firstRoot, 25);
    firstRoot = addNode(firstRoot, 40);
    firstRoot = addNode(firstRoot, 38);
    firstRoot = addNode(firstRoot, 45);
    
    printf("Inorder traversal of tree is : ");
    inoderTraversal(firstRoot);
	
    printf("\n");
    
    Node *secondRoot = NULL;
    
    //Creating a binary tree
    secondRoot = addNode(secondRoot, 30);
    secondRoot = addNode(secondRoot, 20);
    secondRoot = addNode(secondRoot, 15);
    secondRoot = addNode(secondRoot, 25);
    secondRoot = addNode(secondRoot, 40);
    secondRoot = addNode(secondRoot, 38);
    secondRoot = addNode(secondRoot, 45);
    
    printf("Inorder traversal of tree is : ");
    inoderTraversal(secondRoot);
    printf("\n");
    
    printf( "Two trees are identical : %s" , 
           isIdenticalBST( firstRoot, secondRoot ) ? "True" :"false");

    return 0;
}
