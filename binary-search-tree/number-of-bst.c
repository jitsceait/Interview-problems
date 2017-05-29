#include<stdio.h>

/*This function find number of binary search trees possible with n nodes.
Implementation : Recursive.
At each recursion, we take one number as root and find number of left subtrees
possible with node 1 to i and right subtrees with i+1 to n nodes
*/

int number_of_trees(int n){
    if(n <= 1) return 1;
    
    int i;
    int sum = 0;
    int left = 0;
    int right = 0;
    
    for(i=1; i<=n; i++){
        left = number_of_trees(i-1);
        right = number_of_trees(n-i);
        sum=  sum + (left * right);
    }
    
    return sum;
}

int main(){
    printf("\n%d", number_of_trees(3));
    return 0;
}
