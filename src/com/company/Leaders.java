package com.company;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by sangar on 7.4.18.
 */
public class Leaders {

    public static ArrayList<Integer> findLeaders(int[] a){
        ArrayList<Integer> leaders = new ArrayList<>();

        for(int i=0; i<a.length; i++){
            int j = 0;
            for(j=i+1; j<a.length; j++){
                if(a[i] < a[j]){
                    break;
                }
            }
            if(j==a.length) leaders.add(a[i]);
        }

        return  leaders;

    }

    public  static ArrayList<Integer> findLeadersWithoutExtraSpace(int[] a){
        ArrayList<Integer> leaders =new ArrayList<>();

        int currentMax = Integer.MIN_VALUE;
        for(int i=a.length-1; i>=0; i--){
            if(a[i] > currentMax ){
                currentMax = a[i];
                leaders.add(a[i]);
            }
        }

        return leaders;
    }
    public static ArrayList<Integer> findLeadersUsingStack(int[] a){
        ArrayList<Integer> leaders =new ArrayList<>();

        Stack<Integer> s = new Stack();
        s.push(a[0]);

        for(int i=1; i<a.length; i++){
            while(s.peek() < a[i]){
                s.pop();
            }
            s.push(a[i]);
        }

        while (!s.empty()){
            leaders.add(s.pop());
        }
        return leaders;
    }
    public static void main(String[] args) {
        int a[] = new int[]{90, 20, 30, 40, 50};
        ArrayList<Integer> inversions = findLeadersWithoutExtraSpace(a);
        System.out.print("Leaders : " + inversions);
    }
}
