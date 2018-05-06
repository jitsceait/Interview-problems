#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {  return (a > b) ? a : b; }
 
int longestZigzagSubsequence(int A[], int n)
{
    int Table[n][2];
 
    for (int i=0; i<n; i++){
    	Table[i][0] = 1; 
    	Table[i][1] = 1;
    }
 
    int result = 1;
 
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++){
        	// If A[i] is greater than last element in subsequence, 
        	//then check with Table[j][1]
        	if (A[j] < A[i] && Table[i][0] < Table[j][1] + 1)
        		Table[i][0] = Table[j][1] + 1;
 
            // If A[i] is smaller than last element in subsequence, 
            //then check with Table[j][0]
            if( A[j] > A[i] && Table[i][1] < Table[j][0] + 1)
                Table[i][1] = Table[j][0] + 1;
        }
 
        /* Pick maximum of both values at index i  */
        if (result < max(Table[i][0], Table[i][1]))
            result = max(Table[i][0], Table[i][1]);
        printf("\n %d", result);
    }
 
    return result;
}

int main(void) {
	// your code goes here
	int A[] = { 1,7,4,9,2,5 };
	int size = sizeof(A)/sizeof(A[0]);
	printf("\n Length of longest zigzag subsequence : %d", longestZigzagSubsequence(A,size));
	return 0;
}
