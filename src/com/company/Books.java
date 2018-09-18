package com.company;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by sangar on 28.3.18.
 */
public class Books {
    public static boolean predicate(long[] books, long candidate, int days){

        long currentPages = 0;
        int studentRequired = 1;
        int i = 0;

        while(i<books.length){
            if(books[i] > candidate){
                return false;
            }
            if(currentPages + books[i] <= candidate){
                currentPages+=books[i];
                i++;
            }else{
                currentPages = 0;
                studentRequired++;
            }
        }
        return days >= studentRequired;
    }

    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);

        int books = scanner.nextInt();
        int students = scanner.nextInt();

        long [] pages = new long[books];

        for(int i=0; i<books; i++){
            pages[i] = scanner.nextLong();
        }

        long low = 0;
        long high = Arrays.stream(pages).sum();

        while(low < high){
            long mid  = low + ( (high - low) >> 1);

            if(predicate(pages, mid, students)){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        System.out.println(low);
    }
}
