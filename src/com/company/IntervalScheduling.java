package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by sangar on 25.4.18.
 */
public class IntervalScheduling {
    public static ArrayList<Interval> intervalScheduling(ArrayList<Interval> intervals){
        Collections.sort(intervals, Comparator.comparing(p -> p.getEndTime()));

        ArrayList<Interval> resultList = new ArrayList<>();

        for(Interval currentInterval : intervals) {
            if(resultList.isEmpty()) resultList.add(currentInterval);
            else{
                if(currentInterval.getStartTime() > resultList.get(resultList.size()-1).getEndTime()){
                    resultList.add(currentInterval);
                }
            }
        }
        return resultList;
    }

    public static boolean predicate(ArrayList<Interval> intervals, long candidateClassRooms){

        int i = 0;

        PriorityQueue<Interval> queue =
                new PriorityQueue<Interval>(intervals.size(), Comparator.comparing(p -> p.getEndTime()));

        for(Interval currentInterval : intervals){
            if(queue.isEmpty()) queue.add(currentInterval);
            else{
                if(queue.peek().getEndTime() > currentInterval.getStartTime()){
                    queue.add(currentInterval);
                }
                else{
                    queue.remove();
                    queue.add(currentInterval);
                }
            }
        }

        return queue.size() <= candidateClassRooms;
    }

    public static void main(String args[] ) throws Exception {
        ArrayList<Interval> intervals = new ArrayList<>();

        intervals.add(new Interval(930,1100));
        intervals.add(new Interval(930,1300));
        intervals.add(new Interval(930,1100));
        intervals.add(new Interval(1130,1300));
        intervals.add(new Interval(1100,1400));
        intervals.add(new Interval(1330,1500));
        intervals.add(new Interval(1330,1500));
        intervals.add(new Interval(1430,1700));
        intervals.add(new Interval(1530,1700));


        ArrayList<Interval> compatibleIntervals = intervalScheduling(intervals);

        for(Interval interval : compatibleIntervals) {
            System.out.println("(" + interval.getStartTime() + "," + interval.getEndTime() + ")");
        }
    }
}
