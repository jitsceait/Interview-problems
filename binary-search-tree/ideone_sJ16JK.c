#include <stdio.h>
#include <stdlib.h>

#define HD_OFFSET 16

struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
 

void verticalSum(Node *node, int hd, int sum[], int *min, int *max){

    /* We are offseting the index to access array correctly.
    Root will be at HD_OFFSET/2 index and all vertical lines on left will
    be at 0 to HD_OFFSET/2 and right side will be on HD_OFFSET/2 to HD_OFFSET */
    
    int index = hd + HD_OFFSET/2;

    if(!node) return;
    
    /* to keep track of min and max index filled in sum array */
    if(index > (*max)) (*max) = index;
    if(index < (*min)) (*min) = index;

    sum[index]+= node->value;
    /*If we are moving on the left side, 
    we will pass index as one less the current */
    verticalSum(node->left, hd-1, sum, min, max);
    
    /*If we are moving on the right side, 
    we will pass index as one more the current */
    verticalSum(node->right, hd+1, sum, min, max);
}

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

//Driver program
int main(){
    int i;
    int sum[100] ={0, };
    int min = HD_OFFSET;
    int max = 0;

    Node *root = NULL;
    //Creating a binary tree
    root = addNode(root,6);
    root = addNode(root,3);
    root = addNode(root,2);
    root = addNode(root,1);
    root = addNode(root,7);
    root = addNode(root,5);
    root = addNode(root,9);

    verticalSum(root, 0, sum, &min, &max);
    for(i=min;i<=max; i++){
    	printf("Sum at vertical line %d : %d\n", i-min, sum[i]);
    }

    return 0;
}