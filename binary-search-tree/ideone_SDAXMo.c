#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node * createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	
	return newNode;
}
Node * addNode(Node *node, int value){
	
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

Node * findMinimum(Node *root){
    if(!root)
        return NULL;

    while(root->left){
        root = root->left;
    }
    return root;
}

Node * deleteNode(Node *root, int key){
    if(!root)
        return root;
        
    if( root->value > key ){
    	//Delete node is on the left subtree
    	root->left = deleteNode( root->left, key);
    }
    else if ( root->value < key ){
    	//Delete node is on the left subtree
    	root->right = deleteNode( root->right, key);
    }

    if(root->value == key){
    
    	if ( !(root->left) ){
    		//If there is only one child or there is no child
    		//Get the right child, it may be NULL too.
    		Node *currentNode = root->right;
    		free(root);
    		return currentNode;
    	}
    	else if ( !( root->right ) ){
    		//If there is a left child. Check if there is no right child.
    		//If there is no right child, return the left child.
    		Node *currentNode = root->left;
    		free(root);
    		return currentNode;
    	}
    	//Case when both children are there.
    	//Get the minimum in right subtree and returnt that.
    	Node * currentNode = findMinimum(root->right);
    	//Copy the node value
    	root->value = currentNode->value;
    	
    	root->right = deleteNode(root->right, currentNode->value);
    }
    return  root;
}



void inorder(Node * root){
	if(!root) return ;
	
	inorder(root->left);
	printf("%d ", root->value);
	inorder( root->right);
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
        deleteNode(root, 25);
        printf("\n");
        inorder(root);
        return 0;
}
