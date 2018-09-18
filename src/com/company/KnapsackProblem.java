package com.company;

/**
 * Created by sangar on 19.8.18.
 */
public class KnapsackProblem {
    static int knapSack(int W, int[] weights, int[] val, int n) {

        System.out.println("Called with  W = " + W + " and n = "+ n);
            /*
            If there is no item or weight that can be carried is zero,
            return zero
             */
        if (n < 0 || W == 0)
            return 0;

            /* If weight of the nth item is more than Knapsack capacity W, then
            this item cannot be included in the optimal solution
            */
        if (weights[n] > W)
            return knapSack(W, weights, val, n - 1);

            /* Consider two cases, including the item and excluding the item.*/
        else return Integer.max((val[n] + knapSack(W - weights[n], weights, val, n - 1)),
                knapSack(W, weights, val, n - 1)
        );
    }

    public static int knapsackDP(int W, int[] weights, int[] val, int n) {
        int[][] V = new int[n+1][W + 1];
        V[0][0] = 0;
        for(int i = 1 ; i < V[0].length; i++){
            /*
                If weight of item is less than current value
                we can achieve minimum value V[i] with 1..i items
            */
            if(weights[0] <= i){
                V[0][i] = val[0];
            }else{
                V[0][i] = 0;
            }
        }

        //Loop for all items
        for (int i = 1; i < V.length; i++) {
            for (int j = 1; j < V[i].length; j++) {
            // if a weight is more than the allowed weight, that weight cannot be picked.
            if(weights[i] > j){
                V[i][j] = V[i-1][j];
            }else{
                V[i][j] = Math.max(V[i-1][j], val[i] + V[i-1][j-weights[i]]);
            }
        }
    }
    return V[V.length-1][W];
}

    public static void main(String args[]) {
        int[] val = {60, 100, 120};
        int[] wt = {10, 20, 30};
        int W = 50;

        int n = val.length;
        System.out.println(knapsackDP(W, wt, val, n - 1));
    }
}
