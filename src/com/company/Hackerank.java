package com.company;



import java.util.*;
/**
 * Created by sangar on 27.3.18.
 */
public class Hackerank {

        public static void main(String args[] ) throws Exception {
            Scanner scanner = new Scanner(System.in);

            int soldiers = scanner.nextInt();
            int[] powers = new int[soldiers];

            for(int i=0; i<soldiers; i++){
                powers[i] = scanner.nextInt();
            }

            int rounds = scanner.nextInt();
            int[] roundPower = new int[rounds];
            for(int i=0; i<rounds; i++){
                roundPower[i] = scanner.nextInt();
            }

            System.out.println("Rounds: " + rounds);
            Arrays.sort(powers);

            for(int i=0; i<rounds; i++){
                int soldiersToFight = BinarySearcchAlgorithm.findFirstElementEqualOrGreater(powers, 0, powers.length-1, roundPower[i]);
                soldiersToFight = soldiersToFight < 0  ? powers.length : soldiersToFight;
                int sum = 0;
                for(int j=0; j<soldiersToFight; j++){
                    sum+= powers[j];
                }

                System.out.println(soldiersToFight + " " + sum);
            }

        }
}
