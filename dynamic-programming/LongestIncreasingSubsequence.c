#include<stdio.h>
#include<stdlib.h>

int ceilElement(int a[],int start,int end,int key){
	while(end-start > 1){
		int mid = start +(end - start)/2;
		if(a[mid]>=key){
			end = mid;
		}
		else{
			start = mid;
		}
	}
	return end;
}

int longestIncreasingSubsequence(int input[], int size)
{
	if(!size)
		return 0;

	int a[size];
	int length=1;
	
	a[0] = input[0];

	for(int i=1; i<size; i++)
	{
		if(input[i]< a[0]){
			a[0]=input[i];
		}
		else if(input[i]>a[length-1]){
			a[length++]=input[i];
		}
		else
			a[ ceilElement(a,-1,length-1,input[i]) ]= input[i];
	}
	return length;
}

int main() {
	int a[]={0,8,4,12,2,10,6,14,1,9,5,13,1,7,15};
	int size =sizeof(a)/sizeof(a[0]);
	
	printf("Longest Increasing Sub-sequence is = %d",longestIncreasingSubsequence(a,size));
	return 0;
}
