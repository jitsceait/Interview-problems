package com.company;

/**
 * Created by sangar on 20.8.18.
 */
public class KadaneAlgorithm {

    public static int largestSumSubarray (int[] a){

        int maxSum = Integer.MIN_VALUE;

        for(int i=0; i<a.length; i++){
            int currentSum = 0;
            for(int j=i; j<a.length; j++){
                currentSum+= a[j];
                if(maxSum < currentSum){
                    maxSum = currentSum;
                }
            }
        }
        return maxSum;

    }

    public static int kadaneAlgorithm (int[] a){

        int maxSum = a[0];
        int currentSum = a[0];

        for(int i=1; i<a.length; i++) {
            currentSum = Integer.max(a[i], currentSum + a[i]);

            if (maxSum < currentSum) {
                maxSum = currentSum;
            }
        }
        return maxSum;

    }
    public static void main(String args[]) {
        int[] a = {-1, 3, -5, 4, 6, -1, 2, -7, 13, -3};

        System.out.println(kadaneAlgorithm(a));
    }
}
