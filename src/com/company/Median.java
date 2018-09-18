package com.company;

/**
 * Created by sangar on 18.4.18.
 */
public class Median {

    public static double findMedian(int[] A, int[] B){
        int[] temp = new int[A.length + B.length];

        int i = 0;
        int j = 0;
        int k = 0;
        int lenA = A.length;
        int lenB = B.length;

        while(i<lenA && j<lenB){
            if(A[i] <= B[j]){
                temp[k++] = A[i++];
            }else{
                temp[k++] = B[j++];
            }
        }
        while(i<lenA){
            temp[k++] = A[i++];
        }
        while(j<lenB){
            temp[k++] = B[j++];
        }

        int lenTemp = temp.length;

        if((lenTemp)%2 == 0){
            return ( temp[lenTemp/2-1] + temp[lenTemp/2] )/2.0;
        }
        return temp[lenTemp/2];
    }

    public  static int findMedianOptimized(int[] A, int[] B){
        int i = 0;
        int j = 0;
        int k = 0;
        int lenA = A.length;
        int lenB = B.length;

        int mid = (lenA + lenB)/2;
        int midElement = -1;
        int midMinusOneElement = -1;

        while(i<lenA && j<lenB){
            if(A[i] <= B[j]){
                if(k == mid-1){
                    midMinusOneElement = A[i];
                }
                if(k == mid){
                    midElement = A[i];
                    break;
                }
                k++;
                i++;
            }else{
                if(k == mid-1){
                    midMinusOneElement = B[j];
                }
                if(k == mid){
                    midElement = B[j];
                    break;
                }
                k++;
                j++;
            }
        }
        while(i<lenA){
            if(k == mid-1){
                midMinusOneElement = A[i];
            }
            if(k == mid){
                midElement = A[i];
                break;
            }
            k++;
            i++;
        }
        while(j<lenB){
            if(k == mid-1){
                midMinusOneElement = B[j];
            }
            if(k == mid){
                midElement = B[j];
                break;
            }
            k++;
            j++;
        }

        if((lenA+lenB)%2 == 0){
            return (midElement + midMinusOneElement)/2;
        }
        return midElement;
    }

    public static double findMedianWithBinarySearch(int[] A, int[] B){

        int[] temp;

        int lenA = A.length;
        int lenB = B.length;

        /*We want array A to be always smaller than B
          so that j is always greater than zero
         */
        if(lenA > lenB){
            temp = A;
            A = B;
            B = temp;
        }

        int iMin = 0;
        int iMax = A.length;
        int midLength =  ( A.length + B.length + 1 )/2;

        int i = 0;
        int j = 0;

        while (iMin <= iMax) {
            i = (iMin + iMax) / 2;
            j = midLength - i;
            if (i < A.length && B[j - 1] > A[i]) {
                // i is too small, must increase it
                iMin = i + 1;
            } else if (i > 0 && A[i - 1] > B[j]) {
                // i is too big, must decrease it
                iMax = i - 1;
            } else {
                // i is perfect
                int maxLeft = 0;
                //If there we are at the first element on array A
                if (i == 0) maxLeft = B[j - 1];
                //If we are at te first element of array B
                else if (j == 0) maxLeft = A[i - 1];
                //We are in middle somewhere, we have to find max
                else maxLeft = Integer.max(A[i - 1], B[j - 1]);

                //If length of two arrays is odd, return max of left
                if ((A.length + B.length) % 2 == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == A.length) minRight = B[j];
                else if (j == B.length) minRight = A[i];
                else minRight = Integer.min(A[i], B[j]);

                return (maxLeft + minRight) / 2.0;
            }
        }
        return -1;
    }

    public static void main(String[] args){
        int[] a = {1,3,5,6,7,8,9,11};
        int[] b = {1,4,6,8,12,14,15,17};

        double median = findMedian(a,b);
        System.out.println("Median is " + median);
    }

}
