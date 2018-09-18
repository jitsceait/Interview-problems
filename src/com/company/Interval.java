package com.company;

/**
 * Created by sangar on 8.4.18.
 */
public class Interval {
    
    private int startTime;
    private int endTime;


    public Interval(int startTime, int endTime){
        this.startTime = startTime;
        this.endTime = endTime;
    }
    
    public int getStartTime(){
        return this.startTime;
    }
    
    public int getEndTime(){
        return this.endTime;
    }
}
