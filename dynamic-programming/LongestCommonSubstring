#include <stdio.h>
#include <string.h>

int max(int a, int b){
	return a>b ? a:b;
}
 int longestCommonSubstring(char * A, char * B){
 	int lenA = strlen(A);
 	int lenB = strlen(B);
	
	int LCS[lenA+1][lenB+1];
	
	for (int i=0; i <= lenA; i++){
		LCS[i][0] = 0;
	}
	
	for (int j=0; j <= lenB; j++){
		LCS[0][j] = 0;
	}
	
	int maxLength = 0;
	
	for (int i=1; i<= lenA; i++){
		for (int j=1; j <= lenB; j++){
			if (A[i] == B[j]){
				LCS[i][j] = 1 + LCS[i-1][j-1];		
				maxLength = max( maxLength, LCS[i][j] );
			} 
			else {
				LCS[i][j] = 0;
			}
	    }
	}
	
	for (int i=0; i<= lenA; i++){
		printf("\n");
		for (int j=0; j <= lenB; j++){
			printf("%d ", LCS[i][j]);
		}
	}
	return maxLength;
}

int main(void) {
	char *a = "ABCDEFGSE";
	char *b = "EBCDEFGV";
	
	printf("\n Longest common substring : %d",
			longestCommonSubstring(a,b));
	
	return 0;
}
