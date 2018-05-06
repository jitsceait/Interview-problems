#include <stdio.h>
#include <stdlib.h>

int maximumLIS(int a[], int end, int *lis){
	for (int i=0; i<end; i++){
		if( a[i] < a[end] && lis[i] > lis[end] )
			lis[end] = lis[i];
    }
    return lis[end];
}

int lis(int a[], int size){

    int *lis = (int *)malloc(sizeof(int)*size);
    lis[0] = 1;

    for(int i=1; i<size; i++){
    	lis[i] = 1 + maximumLIS(a,i,lis);
    }
    
    int result = lis[size-1];
    free(lis);
    
    return result;
}


int main(void) {
	// your code goes here
	int a[] = { 2,4,6,3,5,7,9 };
	int size = sizeof(a)/sizeof(a[0]);
	
	printf("Length of Longest increasing subsquence : %d" , lis(a, size));
	
	return 0;
}
