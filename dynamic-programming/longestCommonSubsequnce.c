#include <stdio.h>
#include <string.h>

int longestCommonSubsequnceLength(char * A, char * B) {
	int lenA = strlen(A);
 	int lenB = strlen(B);
	
	int TableA[lenA+1];
	int TableB[lenB+1];
	
	for (int i = lenA; i >= 0; i--){
		for (int j = lenB; j >= 0; j--){
			if (A[i] == '\0' || B[j] == '\0'){
				TableA[j] = 0;	
			}
			else if (A[i] == B[j]){
				TableA[j] = 1 + TableB[j+1];	
			} 
			else{
				TableA[j] = max(TableB[j], TableA[j+1]);	
			} 
	    }
	    for(int k =0; k<=lenA; k++){
	    	TableB[k] = TableA[k];
	    }
	}
	return TableA[0];
}

int max(int a, int b){
	return a>b ? a:b;
}
 int longestCommonSubsequnceLength(char * A, char * B){
 	int lenA = strlen(A);
 	int lenB = strlen(B);
	
	int Table[lenA+1][lenB+1];
	for (int i=0; i <= lenA; i++){
		Table[i][0] = 0;
	}
	
	for (int j=0; j <= lenB; j++){
		Table[0][j] = 0;
	}
	
	for (int i=1; i<= lenA; i++){
		for (int j=1; j <= lenB; j++){
			if (A[i] == B[j]){
				Table[i][j] = 1 + Table[i-1][j-1];		
			} 
			else {
				Table[i][j] = max(Table[i-1][j], Table[i][j-1]);
			}
	    }
	}
	return Table[lenA][lenB];
}

int main(void) {
	char *a = "ABCDSEFGD";
	char *b = "ACFEFXVGAB";
	
	printf("\n Longest common subsequence : %d",
			longestCommonSubsequnceLength(a,b));
	
	return 0;
}
