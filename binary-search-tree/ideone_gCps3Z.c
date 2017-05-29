#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

int leastCommonAncestor(Node *root, int val1, int val2){

 	if(!root)
       return -1;

 	if(root->value == val1 || root->value == val2)
    	return root->value;

 	/* Case 3 : If one value is less and other greater than current node
             Found the LCS return */
 	if((root->value > val1 && root->value <= val2) ||
  		(root->value <= val1 && root->value >val2)){
        return root->value;
 	}
 	/*Case 1 : If Both values are less than current node, look in left
           subtree */
 	else if(root->value < val1 && root->value <val2){
        return leastCommonAncestor(root->right, val1, val2);
 	}
  	/*Case 2 : If Both values are greater than current node, look in right
           subtree */
 	else if(root->value > val1 && root->value > val2){
        return leastCommonAncestor(root->left, val1, val2);
 	}
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
  
  printf("\n least common ancestor: %d ",leastCommonAncestor(root, 15, 25));
  
  return 0;
}
