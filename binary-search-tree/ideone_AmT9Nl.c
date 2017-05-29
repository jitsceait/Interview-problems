struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;


Node *createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	
	return newNode;
}
Node *addNode(Node *node, int value){
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

