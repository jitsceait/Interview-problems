#include <stdio.h>
#include <stdlib.h>

int min( int a, int b){
	if(a > b) return b;
	return a;
}

int findMinimumCostPath(int Cost[3][3], int i, int j){
	
	if( i == 0 && j == 0 )
		return Cost[0][0];
	
	if( i == 0 )
	  return findMinimumCostPath(Cost,i, j-1) + Cost[i][j];
  if( j == 0) 
    return findMinimumCostPath(Cost,i-1, j) + Cost[i][j];
    	
   return min(findMinimumCostPath(Cost,i-1, j), 
    		   findMinimumCostPath(Cost,i, j-1)) + Cost[i][j];
}

int findMinimumCostPath(int Cost[3][3], int M, int N){
	
	int MinCost[M][N]; //declare the minCost matrix

    MinCost[0][0] = Cost[0][0];

    // initialize first row of MinCost matrix
    for (int i=1; i<N; i++){
        MinCost[0][i] = MinCost[0][i-1] + Cost[0][i];
    }

    for (int i=1; i<M; i++){
        MinCost[i][0] = MinCost[i-1][0] + Cost[i][0];
    }
    
    for (int i=1;i<M; i++){
    	for (int j=1; j<N; j++){
           MinCost[i][j] = min(MinCost[i-1][j],MinCost[i][j-1]) + Cost[i][j];
        }
    }

    return MinCost[M-1][N-1];
    
}

int main()
{
    int M,N; 
    
    M = N = 3; 
    int Cost[3][3] = {
    	1,3,4,
    	5,3,2,
    	3,4,5
    };
    printf("Minimum cost of path : %d" , findMinimumCostPath(Cost, M-1, N-1));
    
}
