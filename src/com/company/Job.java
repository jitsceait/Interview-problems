package com.company;

/**
 * Created by sangar on 4.5.18.
 */
public class Job {
    private int startTime;
    private int endTime;
    private int value;


    public Job(int startTime, int endTime,int value){
        this.startTime = startTime;
        this.endTime = endTime;
        this.value = value;
    }

    public int getStartTime(){
        return this.startTime;
    }

    public int getEndTime(){
        return this.endTime;
    }

    public int getValue(){
        return this.value;
    }
}
