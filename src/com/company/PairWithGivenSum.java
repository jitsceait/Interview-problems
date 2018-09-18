package com.company;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by sangar on 5.4.18.
 */
public class PairWithGivenSum {
    public static ArrayList<Pair<Integer, Integer>> pairWithGivenSum(int[] a, int sum){
        int left = 0;
        int right = a.length - 1;

        ArrayList<Pair<Integer, Integer>> resultList = new ArrayList<>();

        while(left < right){
            /*If sum of two elements is greater than
              sum required, move towards left */
            if(a[left] + a[right] > sum) right--;
            /*
              If sum of two elements is less than
              sum required, move towards right
            */
            if(a[left] + a[right] < sum) left++;
            if(a[left] + a[right] == sum){
                resultList.add(new Pair(left, right));
                right--;
            }
        }
        return resultList;
    }

    public static ArrayList<Pair<Integer, Integer>> pairsWithGivenSum2(int[] a, int sum){
        int index = 0;
        ArrayList<Pair<Integer, Integer>> resultList = new ArrayList<>();

        HashMap<Integer, Integer> pairMap = new HashMap<>();
        for(int i=0; i< a.length; i++){
            if(pairMap.containsKey(a[i])){
                resultList.add(new Pair(pairMap.get(a[i]), i));
            }
            pairMap.put(sum-a[i], i);
        }
        return resultList;
    }
    public static void main(String[] args) {
        int a[] = new int[] {10, 20, 30, 40, 50};

        ArrayList<Pair<Integer, Integer>> result = pairsWithGivenSum2(a,50);
        for (Pair<Integer, Integer> pair : result ) {
            System.out.println("("+ pair.getKey() + "," + pair.getValue()  + ")");
        }
    }
}
