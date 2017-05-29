#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node{
        int value;
        struct node *left;
        struct node *right;
};
typedef struct node Node;

int replace_sum(Node *root){
	if (!root)
	    return 0;
	int left_sum =  replace_sum(root->left);
	int right_sum = replace_sum(root->right);
	if(left_sum + right_sum != 0){
		root->value = left_sum + right_sum;
	}
	return root->value;
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
        
        inorder(root);
        int sum = 0;
        replace_sum(root);
        printf("\n");
        
        inorder(root);
        return 0;
}
