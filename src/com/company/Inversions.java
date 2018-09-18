package com.company;

/**
 * Created by sangar on 6.4.18.
 */
public class Inversions {
    public static int findInversions(int[] a){
        int count = 0;
        for(int i=0; i<a.length; i++){
            for(int j=i+1;  j<a.length; j++){
                if(a[i] > a[j]) count++;
            }
        }
        return count;
    }

    public  static int mergeAndCount(int[] a, int low, int mid, int high){
        int count  =  0;
        int[] temp = new int[high-low+1];

        int i = low;
        int j = mid+1;
        int k = 0;
        /*
            There are elements on both side of array
        */
        while(i<=mid && j<=high){

            if(a[i] > a[j]){
                //Number of elements remaining on left side.
                count+= (mid - i + 1);
                temp[k++] = a[j++];
            }
            else{
                temp[k++] = a[i++];
            }
        }
        while(i<=mid){
            temp[k++] = a[i++];
        }
        while(j<=high) {
            temp[k++] = a[j++];
        }

        for(i=low; i<k+low; i++){
            a[i] = temp[i-low];
        }

        return count;
    }

    public static int countInversions(int[] a, int low, int high){
        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        int inversionsLeft = countInversions(a, low, mid);
        int inversionsRight = countInversions(a, mid+1, high);
        int inversionsMerge = mergeAndCount(a, low, mid, high);

        return inversionsLeft + inversionsRight + inversionsMerge;
    }


    public static void main(String[] args) {
        int a[] = new int[]{90, 20, 30, 40, 50};
        int inversions = findInversions(a);
        System.out.print("Inversions : " + inversions);
    }
}
