package com.company.BST;

/**
 * Created by sangar on 11.5.18.
 */
public class NumberOfBST {

    public static int numberOfTrees(int n){
        if(n <= 1) return 1;

        int sum = 0;
        int left = 0, right = 0;

        for(int i=1; i<=n; i++){
            left = numberOfTrees(i-1);
            right = numberOfTrees(n-i);
            sum +=  (left * right);
        }
        return sum;
    }

    public static int numberOfTreesDP(int n){
        if(n <= 1) return 1;

        int[] T = new int[n+1];
        T[1] = T[0] = 1;

        for(int i=2; i<=n; i++){
            int sum = 0;
            for(int j=0; j<i; j++){
                sum += T[j] * T[i-j-1];
            }
            T[i] = sum;
        }
        return T[n];
    }

    public static void main (String[] args){
        System.out.print("Number of tress possible :" + numberOfTreesDP(4));
    }
}
