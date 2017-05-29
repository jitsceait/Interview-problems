#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;


void print_k_nodes(Node * node, int *K){
	if(node == NULL || (*K) == 0) return;
	
	print_k_nodes(node->right, K);
	printf("%d ", node->value);
    (*K)--;
	print_k_nodes(node->left, K);
}

void inorder(Node * root){
	if ( !root ) return;
	
	inorder(root->left);
	printf("%d ", root->value );
	inorder(root->right);
	
}

void preorder(Node * root){
	if ( !root ) return;
	printf("%d ", root->value );
	
	preorder(root->left);

	preorder(root->right);
	
}

Node * create_node(int value){
        Node * temp =  (Node *)malloc(sizeof(Node));
        temp->value = value;
        temp->right= NULL;
        temp->left = NULL;
        return temp;
}
Node * addNode(Node *node, int value){
        if(node == NULL){
        	return create_node(value);
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
        Node * last = NULL;
        Node *ptrToHead = NULL;
        //Creating a binary tree
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);
        
        int K =4;
        print_k_nodes(root, &K);
        return 0;
}