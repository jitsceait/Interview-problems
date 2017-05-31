#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node * findMaximum(Node * root){
	if( !root ) return root;
	while( root->right ){
		root = root->right;
	}
	return root;
}

Node * findMinimum(Node * root){
	if( !root ) return root;
	while( root->left ){
		root = root->left;
	}
	return root;
}

int isBST(Node * node){

  	if(!node)
  		return true;
    
    if( ! ( node->left || node->right ) ) return true;   
  	int isLeft  = isBST(node->left);
  	int isRight = isBST(node->right);

  	if(isLeft && isRight){
  		/* Since we already know that left sub tree and
 		right sub tree are Binary search tree, finding min and max in them would be easy */
   	
   		Node *max  =  NULL;
   		Node *min  =  NULL;
   		if( node->left )
   			max = findMaximum(node->left);
   		if( node->right )
   			min = findMinimum(node->right);

   		//Case 1 : only left sub tree is there
    	if(max && !min)
        	return node->value > max->value;
   		//Case 2 : Only right sub tree is there
    	if(!max && min)
       		return node->value < min->value;
   		//Case 3 : Both left and right sub tree are there
    	return (node->value > max->value && node->value < min->value);
   }
   return false;
}

Node * createNode(int value){
  Node *newNode =  (Node *)malloc(sizeof(Node));
  
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
     if (node->value < value){
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
  
  printf("%s", isBST(root ) ? "Yes" : "No" );
  
  return 0;
}
