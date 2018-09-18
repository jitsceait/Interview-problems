package com.company;

import java.util.Scanner;

/**
 * Created by sangar on 29.3.18.
 */
public class RoundTable {
    public static void main(String args[]) throws Exception {
        Scanner scanner = new Scanner(System.in);

        int students = scanner.nextInt();
        int queries = scanner.nextInt();

        int[] universities = new int[students];

        for (int i = 0; i < students; i++) {
            universities[i] = scanner.nextInt();
        }

        /* What will be maximum distance two students ca be at?
         Minimum distance will be 0 and maximum possible distance will be
         number of students;
         */
        int low = 0;
        int steps = students / 2;

    }
}
