package com.company;

import java.util.*;

/**
 * Created by sangar on 7.1.18.
 */
public class LIS {

    private static int maximumLIS(int a[], int end, int [] LIS){
        for (int i=0; i<end; i++){
            if( a[i] < a[end] && LIS[i] > LIS[end] )
            LIS[end] = LIS[i];
        }
        return LIS[end];
    }
    static int[] getMinimumDifference(String[] a, String[] b) {
        int n = a.length;
        int m = b.length;
        int[] differences = new int[n];

        //All string pairs where length is different
        for(int i=0; i<n; i++){
            if(a[i].length() != b[i].length()){
                differences[i] = -1;
            }
        }

        for(int i=0; i<n && differences[i] != -1; i++){
            HashMap<Character, Integer> characterMap = new HashMap();

            for(int j=0; j<a[i].length(); j++){
                characterMap.put(a[i].charAt(j), characterMap.containsKey(a[i].charAt(j)) ? characterMap.get(a[i].charAt(j)) + 1 : 1 );
            }

           /* for(Character key : characterMap.keySet()){
                System.out.println(key + ":" + characterMap.get(key));
            }*/
            for(int j=0; j<b[i].length(); j++){
                characterMap.put(b[i].charAt(j), characterMap.containsKey(b[i].charAt(j)) &&  characterMap.get(b[i].charAt(j)) > 0? characterMap.get(b[i].charAt(j)) - 1 : 0 );
            }

            for(Character key : characterMap.keySet()){
                System.out.println(key + ":" + characterMap.get(key));
            }
            int count = 0;
            for(Character key : characterMap.keySet()){
                count += characterMap.get(key);
            }
            System.out.println(" Count:" + count);
            differences[i] = count;
        }
        return differences;
    }

    // you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

    class Solution {
        public int solution(int[] A) {

    /* we need to find longest acending order, if we find the length and where it ends
    then we can find easily where did it start
    At each index of array, we can find the longest acending sequence till that index.
    Let's LAS(i) stores the longest subsequence till i.
    LAS(i) = longest(i-1) + 1 if A[i] > A[i-1]
    else we will update the maximum length if that's changes at i-1 and store i-1 as
    index where longest ascending order seqeuce finishes.
    Since Slice(P,P) is acending sequence, we can assume LAS(0) = 1 */

            int[] LAS = new int[A.length];

            LAS[0] = 1; // Initialized to 1 as Slice(P,P) is considered ascending
            int maxIndex = 0; // Save the end of maximum ascending order sequence
            int maxLength = 0; // save the maximum length found till now.

            for(int i=1; i<A.length; i++){
                if(A[i] > A[i-1]){
                    LAS[i] = LAS[i-1] + 1;
                }
                else{
                    maxIndex = maxLength > LAS[i-1] ? maxIndex : i-1;
                    maxLength =  Integer.max(maxLength, LAS[i-1]);
                    LAS[i] = 1;
                }
            }
            return maxIndex-maxLength;
        }
    }
        public static int solution(int[] A) {

    /* we need to find longest acending order, if we find the length and where it ends
    then we can find easily where did it start
    At each index of array, we can find the longest acending sequence till that index.
    Let's LAS(i) stores the longest subsequence till i.
    LAS(i) = longest(i-1) + 1 if A[i] > A[i-1]
    else we will update the maximum length if that's changes at i-1 and store i-1 as
    index where longest ascending order seqeuce finishes.
    Since Slice(P,P) is acending sequence, we can assume LAS(0) = 1 */

            int[] LAS = new int[A.length];

            LAS[0] = 1; // Initialized to 1 as Slice(P,P) is considered ascending
            int maxIndex = 0; // Save the end of maximum ascending order sequence
            int maxLength = 0; // save the maximum length found till now.

            for(int i=1; i<A.length; i++){
                if(A[i] > A[i-1]){
                    LAS[i] = LAS[i-1] + 1;
                }
                else{
                    maxIndex = maxLength > LAS[i-1] ? maxIndex : i-1;
                    maxLength =  Integer.max(maxLength, LAS[i-1]);
                    LAS[i] = 1;
                }
                System.out.println("i =" + i);
                System.out.println("maxLenght =" + maxLength);
                System.out.println("maxIndex =" + maxIndex);

            }
            return maxIndex-maxLength;
        }

    public static class Meeting {

            int startTime;
            int endTime;

        public Meeting(String meetingDetail) {

                String[] splitTimes = meetingDetail.split("-");
                int startHour = Integer.parseInt(splitTimes[0].split(":")[0]);
                int startMin = Integer.parseInt(splitTimes[0].split(":")[1]);
                this.startTime = startHour * 100 + (startMin/60)* 100;

                int endHour = Integer.parseInt(splitTimes[1].split(":")[0]);
                int endMin = Integer.parseInt(splitTimes[1].split(":")[1]);
                this.endTime = endHour * 100 + (endMin/60) * 100;
            }


        public int getStartTime(){
            return this.startTime;
        }
        public int getEndTime(){
            return this.endTime;
        }
    }

    public static int solution1(String S) {
        /* first parse the string and create and array of classes called meeting
        A[i] = (collection of meetings with their start and end time in sorted order).
        for each day, find the maximum interval James has.
        Also, check the if this maximum is greater than
        next day start + (2400 - last meeting end time ) except for sunday where we
        just check if (2400 - last meeting end time ) is maximum */

        /* every meeting details is 15 characters long, hence we will parse string that way
        HashMap<String, List<Meeting>> weekday = new HashMap(); // store meeetings on days
         */
        HashMap<String, List<Meeting>> meetings = new HashMap();

        HashMap<String, String> nextDay = new HashMap();
        nextDay.put("Mon", "Tue");
        nextDay.put("Tue", "Wed");
        nextDay.put("Wed", "Thu");
        nextDay.put("Thu", "Fri");
        nextDay.put("Fri", "Sat");
        nextDay.put("Sat", "Sun");

        String[] weekSchedule = S.split("\\r?\\n"); // This gives all the lines of meetings

        // Now for each string create a list of meeting on each day.
        for (String schedule : weekSchedule) {
            // Split on space. First string is weekday, second is timings
            String[] meetingDetails = schedule.split("\\s+");
            //Create a meeting object
            Meeting newMeeting = new Meeting(meetingDetails[1]);
            if (meetings.containsKey(meetingDetails[0])) {
                meetings.get(meetingDetails[0]).add(newMeeting);
            } else {
                List<Meeting> newList = new ArrayList<>();
                newList.add(newMeeting);
                meetings.put(meetingDetails[0], newList);
            }
        }

        //Sort each list by start time
        for (String key : meetings.keySet()) {
            Collections.sort(meetings.get(key), (Meeting a, Meeting b) -> a.getStartTime() < b.getStartTime() ? -1 : a.getStartTime() == b.getStartTime() ? 0 : 1);
        }

        int interval = 0;
        // For each one, find the maximum interval
        for (String key : meetings.keySet()) {


            List<Meeting> currentList = meetings.get(key);
            for (int i = 0; i < currentList.size() - 2; i++) {
                interval = Integer.max(interval, currentList.get(i + 1).getStartTime() - currentList.get(i).getEndTime());
            }

            if (key.equals("Sun")) {
                interval = Integer.max(interval, 2400 - currentList.get(currentList.size()-1).getEndTime());
            } else {

                List<Meeting> nextList = meetings.get(nextDay.get(key));
                interval = Integer.max(interval, nextList.get(0).getStartTime() - currentList.get(currentList.size()-1).getEndTime());
            }
        }

        return ( interval / 100  ) * 60 ;
    }

    private static int lis(int [] A){

        int [] LIS = new int[A.length];
        LIS[0] = 1;

        for(int i=1; i<A.length; i++){
            LIS[i] = 1 + maximumLIS(A,i,LIS);
        }

        return LIS[A.length - 1];
    }



    static int[] counts(int[] nums, int[] maxes) {

        int n = nums.length;
        int m = maxes.length;

        Arrays.sort(nums);
        int[] counts = new int[m];


        for(int i=0; i<m; i++){ // O(m)
            /*int count = 0;
            for(int j=0; j<n; j++){
                if(nums[j]< maxes[i]) {
                    count++;
                }
            }
            counts[i] = count; */
        }
        for(int i=0; i<m; i++){ // O(m)
            int index = Arrays.binarySearch(nums, maxes[i]);
            if(index < 0) {
                System.out.println(Math.abs(index) - 1);
            }
        }

        return counts;
    }

    public static void main(String[] args) {
        int[] a = {1,4,2,4};
        int[] b = {3,5};
        System.out.println(counts(a,b));
    }
}
