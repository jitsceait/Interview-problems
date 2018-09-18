package com.company;

/**
 * Created by sangar on 5.1.18.
 */
public class DutchNationalFlag {

    public static void swap(int[] input, int i, int j){
        int temp =  input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    public static void dutchNationalFalgAlgorithm(int [] input){

        //initialize all variables
        int reader = 0;
        int low = 0;
        int high = input.length - 1;

        while(reader <= high){
            if(input[reader] == 0){
                /*When element at reader is 0, swap element at reader with
                element at index low and increment reader and low*/
                swap(input, reader, low);
                reader++;
                low++;
            }
            else if(input[reader] == 1){
                /* if element at reader is just increment reader by 1 */
                reader++;
            }
            else if(input[reader] == 2){
                /* If element at reader is 2, swap element at reader
                 with element at high and decrease high by 1 */
                swap(input, reader, high);
                high--;
            }
        }

    }
    public static void main(String[] args) {
        int[] input = {2,2,1,1,0,0,0,1,1,2};

        dutchNationalFalgAlgorithm(input);

        for(int i=0; i<input.length; i++){
            System.out.print(" " + input[i]);
        }
    }
}

