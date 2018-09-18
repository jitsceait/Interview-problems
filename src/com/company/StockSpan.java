package com.company;

import java.util.Arrays;
import java.util.Stack;

/**
 * Created by sangar on 18.9.18.
 */
public class StockSpan {
    public static int[] stockSpan(int[] prices){

        Stack<Integer> s = new Stack();
        int[] span = new int[prices.length];

        span[0] = 1;
        s.push(0);

        for(int i=1; i<prices.length; i++){
            while(!s.empty() && prices[i] > prices[s.peek()])
                s.pop();

            if(s.empty())
                span[i] = i;
            else
                span[i] =  i - s.peek();

            s.push(i);
        }

        return span;
    }

    public static void main(String args[]){
        int prices[] = {100, 60, 70, 65, 80, 85, 45, 77, 56, 98, 200};
        int[] span = stockSpan(prices);

        Arrays.stream(span).forEach(System.out::println);

    }
}
