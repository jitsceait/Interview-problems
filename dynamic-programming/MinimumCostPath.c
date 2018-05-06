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
