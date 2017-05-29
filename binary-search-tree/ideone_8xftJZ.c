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

int height(Node *root){
	if(!root)
		return 0;
	
	if(!root->left && !root->right)
		return 1;

    int lheight = height(root->left);
    int rheight = height(root->right);
    
    return (lheight > rheight ? lheight+1 : rheight +1);
}

void connectLevelRec(Node * node, int desired, Node **lastNode){
    if(node == NULL)
        return;
        
    //Node at the given level
    if (desired == 1){
        //Update the next pointer of node 
        node->next = *lastNode;
        //change the last node 
        *lastNode = node;
    }
    // search for the node again at same level
    connectLevelRec(node->right, desired-1, lastNode);
    connectLevelRec(node->left,  desired-1, lastNode);
}

void printTreeLevel(Node *root){
    int h = height(root);
    int i;
    
    for(i=1; i<=h+1; i++){
       Node *lastNode = NULL;
       connectLevelRec(root, i, &lastNode);
    }
    
    Node *current = root;
    
    /*Printing has bugs, it just to check if nodes are being
    added correctly */
    while(current){
        Node *temp = current;
        while(temp){
            printf("%d ", temp->value);
            temp= temp->next;
        }
        printf("\n");
        current = current->left;
    }
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
	
	printTreeLevel(root);
	
	return 0;
}