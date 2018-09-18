package com.company;

import java.util.Arrays;

/**
 * Created by sangar on 4.5.18.
 */
public class ScheduleWeightedJobs {

    public static int optimalScheduling(Job[] jobs, int[] nonConflictJobs, int j){
        if(j == -1){
            return 0;
        }

        return Integer.max(optimalScheduling(jobs, nonConflictJobs, nonConflictJobs[j]) + jobs[j].getValue(),
                            optimalScheduling(jobs, nonConflictJobs, j-1));
    }

    public static int optimalSchedulingDP(Job[] jobs, int[] nonConflictJobs){
        int[] optimalValue = new int[jobs.length];

        optimalValue[0] = jobs[0].getValue();

        for(int i = 1; i < jobs.length; i++){
            optimalValue[i] = Integer.max(optimalValue[nonConflictJobs[i]] + jobs[i].getValue(),
                                optimalValue[i-1]);
        }

        return optimalValue[jobs.length-1];

    }

    public static void main(String[] args) {

        Job[] jobs = new Job[4];
        jobs[0] = new Job(1, 3, 50);
        jobs[1] = new Job(3, 5, 20);
        jobs[2] = new Job(6, 9, 100);
        jobs[3] = new Job(3, 12, 200);

        Arrays.sort(jobs, (o1, o2) -> o1.getEndTime() - o2.getEndTime());

        int[] nonConflictingJobs = new int[jobs.length];

        for (int j = 0; j < jobs.length; j++) {
            nonConflictingJobs[j] = -1;
            for(int i = j-1; i >= 0; i--) {
                if(jobs[i].getEndTime() <= jobs[j].getStartTime()) {
                    nonConflictingJobs[j] = i;
                    break;
                }
            }
        }

        int maxValue = optimalSchedulingDP(jobs,nonConflictingJobs);

        System.out.println(maxValue);
    }
}
