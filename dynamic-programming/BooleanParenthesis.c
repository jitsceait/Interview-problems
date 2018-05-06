#include<stdio.h>
#include<string.h>
 
int countNumberOfWaysToParenthesize(char operands[], char operators[], int n)
{
    int F[n][n], T[n][n];
 
    for (int i=0; i<n; i++){
        F[i][i] = (operands[i] == 'F')? 1: 0;
        T[i][i] = (operands[i] == 'T')? 1: 0;
    }
 
    for (int L=1; L<n; L++) {
    	for (int i=0, j=L; j<n; ++i, ++j){
            T[i][j] = F[i][j] = 0;
            for (int count=0; count<L; count++){
                int k = i + count;
                int totalIK = T[i][k] + F[i][k];
                int totalKJ = T[k+1][j] + F[k+1][j];
                if (operators[k] == '&') {
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (totalIK *totalKJ - T[i][k]*T[k+1][j]);
                }
                if (operators[k] == '|'){
                    F[i][j] += F[i][k]*F[k+1][j];
                    T[i][j] += (totalIK*totalKJ - F[i][k]*F[k+1][j]);
                }
                if (operators[k] == '^'){
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
            }
        }
    }
    return T[0][n-1];
}
 
// Driver program to test above function
int main()
{
    char operands[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(operands);
 
    printf ("\n Number of ways to parenthisize expression : %d", 
                 countNumberOfWaysToParenthesize(operands, operators, n));
    return 0;
}

