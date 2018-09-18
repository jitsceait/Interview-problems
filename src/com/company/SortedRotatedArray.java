package com.company;

/**
 * Created by sangar on 22.3.18.
 */
public class SortedRotatedArray {

    public static int findMinimumIterative(int[] input, int start, int end) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (input[mid] <= input[mid+1]
                    && input[mid] < input[mid-1]) return mid;

            else if (input[mid] > input[mid]) {
                 /* Array is rotated more than half, hence minimum
                 should be in right sub-array
                  */
                start  = mid + 1;
            } else {
                 /* Array is rotated less than half, hence minimum
                 should be in left sub-array
                  */
                end  = mid - 1;
            }
        }
        return start;
    }

    public static int findMinimumRecursive(int[] input, int start, int end){

        if(start < end){
            int mid = start + (end - start) / 2;

            if(mid == 0 || mid == end || (input[mid] < input[mid-1]
                            && input[mid] <= input[mid+1] ) ) return mid;

            else if(input[mid] >= input[end] && input[mid] >= input[start]){
                /* Array is rotated more than half and hence,
                search in right sub array */
                return findMinimumRecursive(input, mid+1, end);
            }else {
                return findMinimumRecursive(input, start, mid);
            }
        }
        return start;
    }


    public static int findElementIteratve(int[] input, int start, int end, int key) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (input[mid] == key) return mid;

            else if (input[start] <= input[mid]) {
                /*Left sub array is sorted, check if
                key is with A[start] and A[mid] */
                if (input[start] <= key && input[mid] > key) {
                    /*
                      Key lies with left sorted part of array
                     */
                    end = mid - 1;
                } else {
                    /*
                    Key lies in right subarray
                     */
                    start  = mid + 1;
                }
            } else {
                /*
                 In this case, right subarray is already sorted and
                 check if key falls in range A[mid+1] and A[end]
                 */
                if (input[mid + 1] <= key && input[end] > key) {
                    /*
                      Key lies with right sorted part of array
                     */
                    start = mid + 1;
                } else {
                    /*
                    Key lies in left subarray
                     */
                    end  = mid - 1;
                }
            }
        }
        return -1;
    }

    public static int findElementRecursive(int[] input, int start, int end, int key){

        if(start <= end){
            int mid = start + (end - start) / 2;

            if(input[mid] == key) return mid;

            else if(input[start] <= input[mid]){
                /*Left sub array is sorted, check if
                key is with A[start] and A[mid] */
                if(input[start] <= key && input[mid] > key){
                    /*
                      Key lies with left sorted part of array
                     */
                    return findElementRecursive(input, start, mid - 1, key);
                }else{
                    /*
                    Key lies in right subarray
                     */
                    return findElementRecursive(input, mid + 1, end, key);
                }
            }else {
                /*
                 In this case, right subarray is already sorted and
                 check if key falls in range A[mid+1] and A[end]
                 */
                if(input[mid+1] <= key && input[end] > key){
                    /*
                      Key lies with right sorted part of array
                     */
                    return findElementRecursive(input, mid + 1 , end, key);
                }else{
                    /*
                    Key lies in left subarray
                     */
                    return findElementRecursive(input, start, mid - 1, key);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] input = {0,1,2,2,2,2,2,2};

        int index = findMinimumRecursive(input,0, input.length-1);
        System.out.print(index == -1 ? "Element not found" : "Element found at : " + index);

    }
}
