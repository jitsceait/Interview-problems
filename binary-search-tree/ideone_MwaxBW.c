#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

#define MAX(a,b)  a>b ?a:b

int height(Node *root){
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return 1;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return MAX(lheight, rheight) + 1;
}

void printTreeLevel(Node *root){
    int i = 0;
    int h = height(root);

    for(i=1; i<=h; i++){
        printf("Level %d :", i);
        printTreeLevelRec(root, i);
        printf("\n");
    }
}

void printTreeLevelRec(Node * node, int desired){
    if(!node)
        return;
    if (desired == 1)
        printf("%d ", node->value);

    printTreeLevelRec(node->left, desired-1);
    printTreeLevelRec(node->right, desired-1);
}

Node * createNode(int value){
    Node * newNode =  (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->right = NULL;
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
 
    printTreeLevel(root);       
    return 0;
}
