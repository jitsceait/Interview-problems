#include<stdlib.h>
#include<stdio.h>

#define true 1
#define false 0
int isSubsetSum(int arr[], int n, int sum ){
	printf("\nCalled with sum : %d, N = %d", sum, n );
	if(!sum){
		return true;
	}
	if(sum < 0) return false;
	
	if(n <= 0  && sum > 0)  return false;
	return isSubsetSum(arr, n-1, sum-arr[n])  
         + isSubsetSum(arr, n-1, sum );
}

/* Driver program */
int main(){

  int set[] = {1,3,5,4,6};
  int n  =  sizeof(set)/sizeof(set[0]);
 
  printf("\n Is there issubset with given sum  : %s",
              isSubsetSum(set, n-1, 10 ) ? "Yes" : "No");
  return 0;
}
