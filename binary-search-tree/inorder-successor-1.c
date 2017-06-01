#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;


//this function finds the minimum node in given tree rooted at node root
Node * findMinimum(Node *root){
    if(!root)
        return NULL;
   // Minimum node is left most child. hence traverse down till left most node of tree.
    while(root->left) root = root->left;
   // return the left most node
    return root;
}
/* This function implements the logic described in algorithm to find inorder successor
of a given node */
Node *inorderSuccessor(Node *root, int K){
 
    Node *successor = NULL;
    Node *current  = root;
    if(!root)
        return NULL;
 
    while(current->value != K){
        /* If node value is greater than the node which are looking for, then go to left sub tree
        Also when we move left, update the successor pointer to keep track of lst left turn */
        
        if(current->value >K){
            successor = current;
            current= current->left;
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->right;
    }
    /*Once we reached at the node for which inorder successor is to be found,
    check if it has right sub tree, if yes then find the minimum in that right sub tree and return taht node 
    Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->right){
        successor = findMinimum(current->right);
    }
 
    return successor;
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
  
  Node *successor = inorderSuccessor(root, 40);
  printf("\n Inorder successor node is : %d ",successor ? successor->value: 0);
  
  return 0;
}
