package com.company;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Stack;

/**
 * Created by sangar on 8.4.18.
 */
public class OverlappingIntervals {
    public  static ArrayList<Interval>
        mergeOverlappingIntervals(ArrayList<Interval> intervals){

        ArrayList<Interval> mergedIntervals = new ArrayList<>();
        Stack<Interval> s = new Stack();

        //Sort the arraylist of interval based on start time.
        Collections.sort(intervals, Comparator.comparing(p -> p.getStartTime()));
        for(Interval currentInterval : intervals){
            if(s.empty())s.push(currentInterval);
            else {
                Interval previousInterval = s.pop();
                if(previousInterval.getEndTime() > currentInterval.getStartTime()){
                    /*
                    If current interval's start time is less than end time of
                    previous interval, find max of end times of two intervals
                    and push new interval on to stack.
                     */
                    int endTime = Integer.max(previousInterval.getEndTime(), currentInterval.getEndTime());
                    /* Notice that we have created new interval and did not update the old one
                       This concept is called as immutability of class
                     */
                    s.push(new Interval(previousInterval.getStartTime(), endTime));
                }
                else{
                    s.push(previousInterval);
                    s.push(currentInterval);
                }
            }
        }
        while(!s.empty()){
            mergedIntervals.add(s.pop());
        }

        return mergedIntervals;
    }

    public static void main(String[] args) {
        ArrayList<Interval> intervals = new ArrayList<>();

        intervals.add(new Interval(1,3));
        intervals.add(new Interval(2,4));
        intervals.add(new Interval(5,8));
        intervals.add(new Interval(6,9));
        ArrayList<Interval> mergedIntervals = mergeOverlappingIntervals(intervals);
        for (Interval interval : mergedIntervals){
            System.out.print("(" + interval.getStartTime() +"," + interval.getEndTime() + ")");
        }

    }
}
