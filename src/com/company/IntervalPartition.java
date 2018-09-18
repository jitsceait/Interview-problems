package com.company;

import java.util.*;

/**
 * Created by sangar on 24.4.18.
 */
public class IntervalPartition {

    public static int findIntervalPartitions(ArrayList<Interval> intervals){
        PriorityQueue<Interval> queue =
                new PriorityQueue<Interval>(intervals.size(), Comparator.comparing(p -> p.getEndTime()));

        for(Interval currentInterval : intervals) {
            if (queue.isEmpty()) queue.add(currentInterval);
            else {
                if (queue.peek().getEndTime() > currentInterval.getStartTime()) {
                    queue.add(currentInterval);
                } else {
                    queue.remove();
                    queue.add(currentInterval);
                }
            }
        }
        return queue.size();
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

        long low = 0;
        long high = intervals.size();

        Collections.sort(intervals, Comparator.comparing(p -> p.getStartTime()));

        low = findIntervalPartitions(intervals);

/*        while(low < high){
            long mid  = low + ( (high - low) >> 1);

            if(predicate(intervals, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }*/

        System.out.println(low);
    }

}
