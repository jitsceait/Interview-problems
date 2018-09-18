package com.company;

/**
 * Created by sangar on 25.3.18.
 */
public class BinarySearcchAlgorithm {

    public  static int findPeak(int[] a){
        int low = 0;
        int high = a.length-1;

        while (low<high){
            int mid = low + (high-low)/2;
            if(mid == low ) return a[low] > a[high] ? low:high;


            if(a[mid-1] <= a[mid]
                    && a[mid] >= a[mid+1]) return mid;

            else if(a[mid-1] > a[mid]) high = mid-1;

            else low = mid+1;
        }
        return low;
    }

    private static boolean predicate(int[] a, int index, int key){
        if(a[index] > key) return true;

        return false;
    }

    public static int findFirstElementEqualOrGreater(int[] a, int start, int end, int key){

        while(start < end){
            int mid = start + (end - start) / 2;

            if(predicate(a, mid, key)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }

        if(!predicate(a,start, key)) return -1;

        return  start;

    }

    private static boolean isGreaterThanEqualTo(int[] a, int index, int key){
        if(a[index] >= key) return true;

        return false;
    }

    public static int findFirstInstance(int[] a, int start, int end, int key){

        while(start < end){
            int mid = start + (end - start) / 2;

            if(isGreaterThanEqualTo(a, mid, key)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }

        return (a[start] == key) ? start : -1;
    }

    private static boolean isLessThanEqualTo(int[] a, int index, int key){
        if(a[index] <= key) return true;

        return false;
    }

    public static int findLastInstance(int[] a, int start, int end, int key){

        while(start < end){
            int mid = start +( (end - start) + 1) / 2;

            if(isLessThanEqualTo(a, mid, key)){
                start = mid;
            }
            else{
                end = mid - 1;
            }
        }
        return (a[start] == key) ? start : -1;
    }

    public  static  int numberOfOccurrences(int[] a, int key){
        int firstInstance = findFirstInstance(a, 0, a.length-1, key);
        int lastInstance = findLastInstance(a, 0, a.length-1, key);

        return (firstInstance != -1) ? lastInstance-firstInstance + 1 : 0;
    }

    public static int findFirstInstanceRecursive(int[] a, int start, int end, int key){

        while(start < end){
            int mid = start + (end - start) / 2;

            if(isGreaterThanEqualTo(a, mid, key)){
                return findFirstInstanceRecursive(a,start,mid, key);
            }
            else{
                return findFirstInstanceRecursive(a,mid+1,end, key);
            }
        }

        return (a[start] == key) ? start : -1;
    }



    public static int binarySearchIterative(int[] a, int start, int end, int key){

        while(start <= end) {
            int mid = start + (end - start)/2;

            /*Check if element at mid index
            element we are looking for? If yes, return mid*/
            if(a[mid] == key) return mid;

            /*
            If element at mid is not equal to key
            what is relationsip between A[mid] and key.
            If A[mid] > key, we look in left subarray
            else we look into right subarray
             */
            if(a[mid] > key){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return -1;

    }
    public static int binarySearchRecursive(int[] a, int start, int end, int key){

        if (start <= end) {
            int mid = start + (end - start)/2;

            /*Check if element at mid index
            element we are looking for? If yes, return mid*/
            if(a[mid] == key) return mid;

            /*
            If element at mid is not equal to key
            what is relationsip between A[mid] and key.
            If A[mid] > key, we look in left subarray
            else we look into right subarray
             */
            if(a[mid] > key){
                return binarySearchRecursive(a,start, mid-1, key);
            }else{
                return binarySearchRecursive(a,mid+1, end, key);
            }
        }

        return -1;

    }

    public static void main(String[] args) {
        int[] input = {1,2,6,5,3,7,4};

        int index = findPeak(input);
        System.out.print("Peak found at : " + index);

    }
}
