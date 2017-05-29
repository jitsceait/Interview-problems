#include <stdio.h>
int number_of_trees(int n)
{
	int i, j;
    // Table to store results of subproblems
    int Trees[n+1];
 
    // Initialize first two values in table
    Trees[0] = Trees[1] = 1;
 
    for (i=2; i<=n; i++)
    {
        Trees[i] = 0;
        for (j=0; j<i; j++)
            Trees[i] += Trees[j] * Trees[i-j-1];
    }
    return Trees[n];
}

int main(void) {
	printf("\n No. of trees: %d", number_of_trees(3));
	return 0;
}
