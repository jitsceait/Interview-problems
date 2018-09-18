package com.company;

/**
 * Created by sangar on 5.1.18.
 */
public class LCS {

    public  static int longestCommonSubstring(String A, String B){
        int lenA = A.length();
        int lenB = B.length();

        int [][] LCS = new int[lenA][lenB];

        for (int i=0; i<lenA; i++){
            LCS[i][0] = 0;
        }

        for (int j=0; j<lenB; j++){
            LCS[0][j] = 0;
        }

        int maxLength = 0;
        for (int i=1; i<lenA; i++){
            for (int j=1; j<lenB; j++){
                if (A.charAt(i) == B.charAt(j)){
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                    maxLength = Integer.max(maxLength, LCS[i][j]);
                }
                else {
                    LCS[i][j] = 0;
                }
            }
        }

        for (int i=0; i<lenA; i++){
            System.out.println();
            for (int j=0; j<lenB; j++){
                System.out.print(" " + LCS[i][j]);
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
	    String a = "ABCDEFGS";
	    String b = "EBCDEFG";

        System.out.println("Longest common substring :" +
                longestCommonSubstring(a,b));
    }
}
