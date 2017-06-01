#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

/* This function calculates the size of tree rooted at Node */
int sizeOfLeftTree(Node *node){
  if(!node)
    return 0;

  return 1 + sizeOfLeftTree(node->left)
           + sizeOfLeftTree(node->right);
}

int findKthNode(Node *root, int K){

    if(!root)
      return 0;

    int no_left = sizeOfLeftTree(root->left); 
    /* If there are K-1 nodes in left sub tree */     
    
    if(no_left  == K-1){
      return root->value;
    }
   /* If there are more than K-1 nodes in left sub tree */
    else if(no_left > K-1){
      return findKthNode(root->left, K);
    }
    /* If there are less than K nodes in left sub tree */
    else{
      return findKthNode(root->right, K-no_left-1);
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
  
  printf("\n Kth smallest node : %d ",findKthNode(root, 4));
  
  return 0;
}
