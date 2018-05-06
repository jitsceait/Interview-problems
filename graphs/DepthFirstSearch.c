#include<stdio.h>
#include<stdlib.h>

#define NUM_NODE 7
#define true 1
#define false 0
 
typedef struct node{
    int value;
    int wt;
    struct node *next;
}Node;
 
Node *graph[NUM_NODE + 1];
int visited[NUM_NODE + 1];

int onStack[NUM_NODE + 1];

typedef struct node{
        int value;
        struct node *next;
}Node;
 
typedef struct stack{
        int top;
        Node *items[NUM_NODE];
}stack;
 
void push(stack *ms, Node *item){
   if(ms->top < NUM_NODE-1){
       ms->items[++(ms->top)] = item;
   }
   else {
       printf("Stack is full\n");
   }
}
 
Node * pop (stack *ms){
   if(ms->top > -1 ){
       return ms->items[(ms->top)--];
   } 
   else{
       printf("Stack is empty\n");
   }
}

int isEmpty(stack ms){
   if(ms.top < 0) return 1;
   else return 0;
}

void dfs(Node * current){

	stack s;
	s.top = -1;
	
	push(&s, current);
	
	while(!isEmpty(s)){
		Node * currentNode = pop(&s);
	//	printf("%d ", currentNode->value);
		
		if( !visited[currentNode->value] ) {
			printf("%d ", currentNode->value);
			visited[currentNode->value] = true;
			
			Node * current  = graph[currentNode->value];		
			while( current ){
        		push(&s, current);
        		current = current->next;
        	}
		}
	}
}


void dfs(Node * current){
        if(!current) return;
        onStack[current->value] = true;
        visited[current->value] = true;
        Node *temp = current->next;
        while(temp){
                if(onStack[temp->value] == true){
                        printf("\n Cycle detected at node %d", temp->value);
                }
                else if(visited[temp->value] != true){
                        dfs(graph[temp->value]);
                }
                temp = temp->next;
        }
        onStack[current->value] = false;
}
Node * createNode(int j){
 
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode){
        newNode->value = j;
        newNode->next = NULL;
    }
    else{
        printf("\n Node cannot be allocated");
    }
    return newNode;
}
 
void addEdge(int i, int j){
 
    Node * currentNode = graph[i];
    if(!currentNode){
        graph[i] = createNode(j);
    }
    else{
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(j);
    }
}
//Driver program
int main(){

	for(int i=1; i<=NUM_NODE; i++){
		graph[i] = createNode(i);
	}
	
	addEdge(1,2);
	addEdge(1,5);
	addEdge(2,3);
	addEdge(2,4);
	addEdge(4,1);
	addEdge(3,4);
	addEdge(4,6);
	addEdge(5,4);
	addEdge(5,6);

    for(int i=1; i<=NUM_NODE; i++){
        visited[i] = false;
	}
	dfs(graph[1]);

	return 0;
}
