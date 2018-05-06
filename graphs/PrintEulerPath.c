#include <stdio.h>

#define min(a,b) a>b ? b:a

typedef struct node{
    int value;
    struct node *next;

}Node;

Node *graph[NUM_NODE];

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
    currentNode = graph[j];
    if(!currentNode){
        graph[j] = createNode(i);
    }
    else{
        while(currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(i);
    }
}
//This function removes a specific edge from undirected graph
void removeEdge(int start, int end){
    Node * current  = graph[start];
    Node * prev = current;
    Node * temp = NULL;
    if(current->value == end){
        graph[start] = current->next;
    }
    else{
        while(current && current->value != end){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }
    free(current);

    current = graph[end];
    prev = current;
    if(current->value == start){
        graph[end] = current->next;
    }
    else{
        while(current && current->value != start){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }
    free(current);
}

// Creating status for finding bridges in graph after removal of edge
int DFSUtil(int u, int low[],int d[], int parent[], int *time){
    Node * current  = graph[u];
    Node * v = NULL;
    d[u] = low[u] = ++(*time);
    visited[u] = TRUE;
    for(v = current; v != NULL; v = v->next){
        if(visited[v->value] != TRUE){
            parent[v->value] = u;
            DFSUtil(v->value,low,d, parent,time);

            low[u] = min(low[u], low[v->value]);
        }
        if(v->value != parent[u])
            low[u] = min(low[u], low[v->value]);
    }
}

Node * getValidNode(int source, int low[], int d[], int visited[]){
    int i =0;
    Node * temp = graph[source];
    // Find non bridge edge first, if not avaialble then take any edge.
    while(temp){
        if(low[temp->value] <= d[source]){
            return temp;
        }
        temp = temp->next;
    }
    temp = graph[source];
    return temp;
}

void dfs(int current, int low[], int d[], int parent[]){
    int time =0;
    int i;
    //Traversing the node 
    printf("\nCurent : %d" , current);
    // Getting the next edge to be traversed. It should not be a bridge
    Node *temp = getValidNode(current, low, d, visited);
    while(temp){
        int a = temp->value;
        // Remove the edge which we have traverse from the graph
        remove_edge(current, temp->value);
        for(i=1; i<=NUM_NODE; i++){
            parent[i] = -1;
            low[i] = -1;
            d[i] = -1;
            visited[i] = FALSE;
        }
        // After removal of node, find if calculation for finding if edge is bridge or not.
        DFSUtil(a, low, d, parent, &time);
        // Again go down to the edge which is eligible
        dfs(a, low, d,parent);
        // Find next eligible edge
        temp = getValidNode(current, low, d, visited);
    }
}

int isStrongComponenetpart(Node * graph[], int degree[]){
    int i;
    for(i=1; i<=NUM_NODE; i++){
        if(degree[i] != 0)
            break;
    }
    if(i== NUM_NODE) return TRUE;

    dfs(graph[0]);

    for(i=1; i<=NUM_NODE; i++){
        if(degree[i] !=0 && visited[i]== FALSE)
            return FALSE;
    }
    return TRUE;
}

int EulerPathExists(Node * graph[]){
    int degree[NUM_NODE+1];
    int count =0;

    for(int i=1; i<=NUM_NODE; i++){
        degree[i] =0;
    }
    for(int i=1; i<=NUM_NODE; i++){
        count =0;
        Node * current  = graph[i];
        while(current){
            current = current->next;
            count++;
        }
        degree[i] = count;
    }
    int connected  = isStrongComponenetpart(graph, degree);
    count=0;
    for(int i=1; i<=NUM_NODE; i++){
        if(degree[i]%2){
            count++;
        }
    }
    if(count !=0 && count !=2 && !connected) return FALSE;

    return TRUE;

}

// Main function to print Euler path
void printEulerPath(Node * graph[]){
	
    int startNode = EulerPathExists(graph);
    
    int parent[NUM_NODE +1];
    int low[NUM_NODE +1];
    int d[NUM_NODE +1];
    int time=0;
  
    for(int i=1; i<=NUM_NODE; i++){
        parent[i] = -1;
        low[i] = -1;
        d[i] = -1;
        visited[i] = FALSE;
    }
    // Create book keeping to fin if edge is a bridge or not.
    DFSUtil(startNode, low, d, parent, &time);
    dfs(startNode,low, d, parent);
}

int main(){
  addEdge(1,2);
  addEdge(1,3);
  addEdge(2,3);
  addEdge(2,4);
  addEdge(2,4);
  addEdge(3,4);
  addEdge(1,5);
  addEdge(5,6);
  addEdge(6,4);
  addEdge(6,3);
    
  printEulerPath(graph);
  return 0;
}
