#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define MAX(a, b) a > b ? a:b

int longestSubstringWithoutRepeatingCharacters(char *s) {
	int n = strlen(s);
	unsigned int table[255];
	
	for(int i=0; i<255; i++){
		table[i] = false;
	}
	
	int maxLength = 0, i = 0, j = 0;
	for (int j = 0, i = 0; j < n; j++) {
		if (table[s[j]-'a']) {
			int currentIndex = table[s[j]-'a'];
			i = MAX(currentIndex, i);
		}
		int currentLenght = j - i + 1;
		maxLength = MAX(maxLength, currentLenght);
            table[s[j]-'a'] = j + 1;
	}
	return maxLength;
}

int main(void) {
	
	char *s ="abcabcbb";
	printf("Longest substting without repeating characters : %d", 
				longestSubstringWithoutRepeatingCharacters(s));
	
	return 0;
}

