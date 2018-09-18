package com.company;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by sangar on 28.3.18.
 */
public class HackerRank2 {
    public static boolean predicate(long[] time, long candidateTime, int days){

        long currentTime = 0;
        int daysRequired = 1;
        int i = 0;

        while(i<time.length){
            if(time[i] > candidateTime){
                return false;
            }
            if(currentTime + time[i] <= candidateTime){
                currentTime+=time[i];
                i++;
            }else{
                currentTime = 0;
                daysRequired++;
            }
        }
        return days >= daysRequired;
    }

    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);

        int tasks = scanner.nextInt();
        int days = scanner.nextInt();

        long [] time = new long[tasks];

        for(int i=0; i<tasks; i++){
            time[i] = scanner.nextLong();
        }

        /* What will be the maximum time he has to practice?
        It will be when he has only one day and all problems needs to be solved.
        that will give us the upper bound of time.

        What will be minimum time required? When he has no problems to be solved.
        That will give us lower bound of time.

        Idea is to start with middle of lower and upper bounds.And see if all problems can be solved
        by practicing that amount of time each day. If yes, there is a possibility that it can be done
        in less than that, hence, we try to find reduce our search space from lower bound to mid. Should mid be included?

        If all problems can not be solved by practicing mid amount of time, then there is no way it can be done
        by practicing less. Hence we increase the time and start looking in mid+1 to higher bound
        */

        //first let's set lower and higher bound.
        long low = 0;
        long high = Arrays.stream(time).sum();

        while(low < high){
            long mid  = low + ( (high - low) >> 1);

            if(predicate(time, mid, days)){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        System.out.println(low);
    }
}


