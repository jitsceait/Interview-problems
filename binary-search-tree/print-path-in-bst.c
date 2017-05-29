#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

void printPath(Node * node, int sum, int path[], int pathLen){
	
	if(!node)
		return;
	
	int subSum = sum - node->value;
	path[pathLen] = node->value;
	
	int isLeaf = !( node->left || node->right );
        if(isLeaf && subSum == 0){
        	printf(" Path with given sum is: " );
			for(int i=0; i<=pathLen; i++)
               	printf("%d, ", path[i]);
           	printf("\n");
        }  
        printPath(node->left, subSum, path, pathLen+1);
        printPath(node->right, subSum, path, pathLen+1);
        return ;
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
  int path[100];
  printPath(root, 115, path, 0);
  
  return 0;
}
