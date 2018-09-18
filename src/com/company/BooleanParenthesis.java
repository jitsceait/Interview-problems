package com.company;

/**
 * Created by sangar on 31.12.17.
 */
public class BooleanParenthesis {

    public static int calculateNumberOfWays(String operators, String operands){
        int numOperands = operands.length();


        int[][] F = new int[numOperands][numOperands];
        int[][] T = new int [numOperands][numOperands];

        for (int i=0; i<numOperands; i++){
            System.out.println(operands.charAt(i));
            F[i][i] = (operands.charAt(i) == 'F')? 1: 0;
            T[i][i] = (operands.charAt(i) == 'T')? 1: 0;
            System.out.println(T[i][i]);
        }

        for (int L=1; L<numOperands; L++) {
            for (int i=0; i<numOperands-L; ++i){
                int j = i+L;
                T[i][j] = F[i][j] = 0;
                for (int k=i; k<j; k++){
                    int totalIK = T[i][k] + F[i][k];
                    int totalKJ = T[k+1][j] + F[k+1][j];
                    if (operators.charAt(k) == '&') {
                        T[i][j] += T[i][k]*T[k+1][j];
                        F[i][j] += (totalIK *totalKJ - T[i][k]*T[k+1][j]);
                    }
                    if (operators.charAt(k) == '|'){
                        F[i][j] += F[i][k]*F[k+1][j];
                        T[i][j] += (totalIK*totalKJ - F[i][k]*F[k+1][j]);
                    }
                    if (operators.charAt(k) == '^'){
                        T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                        F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                    }
                }
            }
        }
        for(int i=0; i<numOperands; i++){
            for(int j=0; j<numOperands; j++){
                System.out.println("(" + i + "," + j + ") :"  + T[i][j]);
            }
        }
        return T[0][numOperands-1];
    }

    public static void main(String[] args) {

        String operands = "TTFT";
        String operators = "|&^";

        System.out.println("Number of ways to parenthisize expression : " +
                calculateNumberOfWays(operators, operands));

    }
}
