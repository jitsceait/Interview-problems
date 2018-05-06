#include<stdlib.h>
#include<stdio.h>

int PossiblePaths(int m,int n){
	int Table[n+1];
	int diagonalSum = 0;
	
	for(int i=0;i<=n; i++){
		Table[i] = 1;
	}
	for(int i=1; i<=m; i++ ){
		int diagonalSum = 1;
		for(int j=1; j<=n; j++){
			int temp = Table[j];
			Table[j] = Table[j] +  Table[j-1] +  diagonalSum;
			diagonalSum = temp;
		}
	}
	return Table[n];
}
 
int PossiblePaths(int i,int j, int m, int n){
	if(i > m || j > n) return 0; 
 
	if(i == m && j == n) return 1;
 
	return PossiblePaths(i+1,j, m,n) 
			+ PossiblePaths(i, j+1, m,n) 
			+ PossiblePaths(i+1, j+1,m,n);
}
 
int PossiblePaths(int m,int n){
	int Table[m+1][n+1];
	int i,j;
 
	for(i=0;i<=m; i++){
		Table[i][0] =1;
	}
	for(i=0;i<=n; i++){
		Table[0][i] =1;
	}
	for(i=1; i<=m; i++ ){
		for(j=1; j<=n; j++){
			Table[i][j] = Table[i-1][j] + Table[i][j-1] + Table[i-1][j-1];
		}
	}
	return Table[m][n];
}
 

int main(){
   printf("%d",PossiblePaths(4,4));
   return 0;
}
