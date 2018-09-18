package com.company;

import java.util.HashMap;

/**
 * Created by sangar on 1.1.18.
 */
public class NonRepeatingCharacters {

    private static boolean allUniqueCharacters(String s, int start, int end) {

        HashMap<Character, Boolean> characters = new HashMap<>();

        for (char c : s.substring(start, end).toCharArray()) {
            if(characters.containsKey(c)) return false;
            characters.put(c, Boolean.TRUE);
        }
        return true;
    }

    private static int longestSubstringWithoutRepeatingCharacters(String s) {
        int len = s.length();
        int maxLength = 0;

        for (int i =0; i < len; i++){
            for (int j=i+1; j<len; j++){
                int length = j-i;
                if (allUniqueCharacters(s, i, j)){
                    maxLength = Integer.max(maxLength, length);
                }
            }
        }
        return maxLength;
    }


    public  static int longestSubstringWithoutRepeatingCharacters1(String s) {
        int len = s.length();
        HashMap<Character, Boolean> characters = new HashMap<>();

        int maxLength = 0;
        int start = 0;
        int  end = 0;
        while (start < len && end < len) {
            if(!characters.containsKey(s.charAt(end))){
                characters.put(s.charAt(end), Boolean.TRUE);
                end++;
            }
            else {
                int currentLength = end-start;
                maxLength = Integer.max(maxLength, currentLength);

                characters.remove(s.charAt(start));
                start++;
            }
        }
        return maxLength;
    }

    public static int longestSubstringWithoutRepeatingCharacters3(String s) {
        int len = s.length();
        HashMap<Character, Integer> characters = new HashMap<>();

        int maxLength = 0;

        for (int start=0, end = 0; end <len; end++) {
            if (characters.containsKey(s.charAt(end))) {
                //find the index of duplicate character.
                int currentIndex = characters.get(s.charAt(end));
                start = Integer.max(currentIndex, start) + 1;
            }
            int currentLength = end - start;
            maxLength = Integer.max(maxLength, currentLength);
            //Update new location of duplicate character
            characters.put(s.charAt(end), end );
        }
        return maxLength;
    }

    public static void main(String[] args) {

	    String s = "abcdabcbb";
        System.out.println("Longest substting without repeating characters: " +
                longestSubstringWithoutRepeatingCharacters3(s));

    }


}
