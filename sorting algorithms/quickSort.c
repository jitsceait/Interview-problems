#include <stdio.h>

void swap(int a[], int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int a[], int start, int end){
	
	int pivot = a[start];
	int i  = start+1;
	int j  = end;
	
	while(i < j){
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
	
		if(i < j) {
			swap(a, i, j);
		}
	}
	swap(a, start, j);
	return j;
}

void quickSort(int a[], int start, int end){
	if(start < end){
		int p = partition(a, start, end);
		quickSort(a,start, p-1);
		quickSort(a, p+1, end);
	}
}

int main(void) {
	int a[]= {4,3,2,5,6,8,1};
	int size = sizeof(a)/sizeof(a[0]);
	
	quickSort(a, 0, size-1);
	
	for(int i=0; i< size; i++){
		printf(" %d", a[i]);
	}
	return 0;
}
