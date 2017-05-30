#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;


/* This function return the maximum node in tree rooted at node root */
Node *findMaximum(Node *root){
    if(!root)
        return NULL;
 
    while(root->right) root = root->right;
    return root;
}
/* This function implements the logic described in algorithm to find inorder predecessor
of a given node */
Node *inorderPredecessor(Node *root, int K){
 
    Node *predecessor 	= NULL;
    Node *current  		= root;
    
    if(!root)
        return NULL;
 
    while(current && current->value != K){
         /* Else take left turn and no need to update predecessor pointer */
        if(current->value >K){
            current= current->left;
        }
        /* If node value is less than the node which are looking for, then go to right sub tree
        Also when we move right, update the predecessor pointer to keep track of last right turn */
        else{
            predecessor = current;
            current = current->right;
        }
    }
    /*Once we reached at the node for which inorder predecessor is to be found,
    check if it has left sub tree, if yes then find the maximum in that right sub tree and return that node 
    Else last right turn taken node is already stored in predecessor pointer and will be returned*/
    if(current && current->left){
        predecessor = findMaximum(current->left);
    }
    return predecessor;
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
  int n = 0;
  //Creating a binary tree
  root = addNode(root,30);
  root = addNode(root,20);
  root = addNode(root,15);
  root = addNode(root,25);
  root = addNode(root,40);
  root = addNode(root,37);
  root = addNode(root,45);
  
  Node *predecessor = inorderPredecessor(root, 40);
  printf("\n Inorder successor node is : %d ",predecessor ? predecessor->value: 0);
  
  return 0;
}
