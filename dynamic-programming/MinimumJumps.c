#include<stdio.h>
#define INFINITY 9999

int minimumJumps(int a[], int size){

    int max=0,count=0;

    for(int i=0; i<size; ){
        count++;
        max = 0;
        for(int j =0; j< a[i]; j++){
            if(max < j+a[i+j]){
                max = j + a[i+j];
            }
        }
        if(max == 0) return INFINITY;
    
        i = i+max;
    }
    return count;
}
//driver program
int main(){
    int a[] = {1,1,2,3,1,4};
    int size = sizeof(a)/sizeof(a[0]);
    printf("Minum Jump : %d", minimumJumps(a, size));
    return 0;
}
