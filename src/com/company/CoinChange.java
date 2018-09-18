package com.company;

/**
 * Created by sangar on 5.5.18.
 */
public class CoinChange {

    public static int coinChange(int value, int[] coins, int consideredCoin){
        /* If value to be changed is negative, since coins are positives,
        there is no way to change them
         */
        if(value < 0) return 0;

        /*When there may or may not be coins, and no value is
        required, there is one solution which is not to include any
        coin */
        if(value == 0) return 1;

        /* When there is value required by no coins left,
           there is not solution
         */
        if(value > 0 && consideredCoin == coins.length) return 0;
                // When coin is included
        return coinChange(value-coins[consideredCoin],coins, consideredCoin)
               //When coin is not included
            + coinChange(value,coins, consideredCoin + 1);
    }

    static long getWays(int value, long[] coins){
        long[][] numWays = new long[value+1][coins.length+1];

        for(int i = 0; i <= coins.length; i++ ){
            numWays[0][i] = 1L;
        }

        for(int i = 1; i <= value; i++ ){
            numWays[i][0] = 0L;
        }

        for(int i = 1; i <= value; i++){
            for(int j = 1; j <= coins.length; j++){
                long remainingValue = (long)i - coins[j-1];
                numWays[i][j] = ( remainingValue >= 0 ? numWays[(int)remainingValue][j] : 0L )
                        + numWays[i][j-1];
            }
        }

        return numWays[value][coins.length];
    }

    public static int coinChangeDP(int value, int[] coins){

        int[][] numWays = new int[value+1][coins.length+1];

        for(int i = 0; i <= coins.length; i++ ){
            numWays[0][i] = 1;
        }

        for(int i = 1; i <= value; i++ ){
            numWays[i][0] = 0;
        }

        for(int i = 1; i <= value; i++){
            for(int j = 1; j <= coins.length; j++){
                numWays[i][j] = (i -coins[j-1] >= 0 ? numWays[i-coins[j-1]][j] : 0 )
                                 + numWays[i][j-1];
            }
        }

        return numWays[value][coins.length];
    }

    public  static void main(String[] args){
        int value = 4;
        long[] coins = {1L,2,3};

        long count = getWays(value, coins);

        System.out.println(count);
    }
}
