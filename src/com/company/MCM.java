package com.company;

/**
 * Created by sangar on 31.12.17.
 */
public class MCM {

    public static int matrixChainMultiplication(int[] P, int i, int j){
        int count = 0;
        int min = Integer.MAX_VALUE;

        System.out.println("("+ i + "," + j + ")");
        if(i==j) return 0; // No cost of multiplying zero matrix

        for(int k=i; k<j; k++){
            System.out.println("Parent : ("+ i + "," + j + ")");
            count = matrixChainMultiplication(P,i, k)
                    + matrixChainMultiplication(P, k+1, j)
                    +   P[i-1]*P[k]*P[j];

            min =  Integer.min(count, min);
        }

        return min;
    }

    public  static  int matriChainMultiplicationDP(int[] P){
        int n = P.length;

        int[][] M = new int[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                M[i][j] = 0;
            }
        }

        for(int L=2; L<n; L++){
            /* For every position i, we check every chain of len L */
            for(int i=1; i<n-L+1; i++){
                int j = i+L-1;
                M[i][j] = Integer.MAX_VALUE;

                /* For matrix i to j, check every split K */
                for(int k=i; k<j; k++){
                    int temp = M[i][k] + M[k+1][j] + P[i-1] * P[k] * P[j];
                    /* Check if the current count is less than minimum */
                    M[i][j] = Integer.min(temp, M[i][j]);
                }
            }
        }

        return M[1][n-1];
    }
    public static void main(String[] args) {
        int arr[] = new int[] {10, 20, 30, 40, 50};
        int n = arr.length;

        System.out.println("Minimum number of multiplications is "+
                matriChainMultiplicationDP(arr));
    }
}
