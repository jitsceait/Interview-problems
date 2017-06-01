#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define INT_MIN -32999
#define INT_MAX 32999

struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

int isBSTHelper(Node *root, int max, int min){
    if(!root) return true;

    if(root->value < min || root->value > max){
        return false;
    }

    return isBSTHelper(root->left, root->value, min) &&
           isBSTHelper(root->right, max, root->value);
}

int isBST(Node *root){
    return isBSTHelper(root, INT_MAX, INT_MIN);
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
