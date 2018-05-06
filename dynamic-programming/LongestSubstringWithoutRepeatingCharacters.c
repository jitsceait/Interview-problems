#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define MAX(a, b) a > b ? a:b

unsigned int checkIfAllUniqueCharacters(char *s, int start, int end) {
	unsigned int table[255];
	
	for(int i=0; i<255; i++){
		table[i] = false;
	}
	for (int i = start; i < end; i++) {
		char ch = s[i];
		if (table[ch-'a']) return false;
        
        table[ch-'a'] = true;
    }
    return true;
}

int longestSubstringWithoutRepeatingCharacters(char *s) {
	int n = strlen(s);
	int maxLength = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			int length = j-i;
			if (checkIfAllUniqueCharacters(s, i, j)){
				maxLength = MAX(maxLength, length);
			}
		}
	}
	return maxLength;
}

unsigned int checkIfAllUniqueCharacters(char *s, int start, int end) {
	unsigned int table[255];
	
	for (int i = start; i < end; i++) {
		char ch = s[i];
		if (hash[ch]) return false;
        hash[ch] = true;
    }
    return true;
}

public int longestSubstringWithoutRepeatingCharacters(char *s) {
	int n = strlen(s);
	int maxLength = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j <= n; j++){
                if (allUnique(s, i, j)) ans = Math.max(ans, j - i);
		}
	}
	return maxLength;
}

char * substr(char *s, int start, int end){
	char *dest =  (char *)malloc(end-start+1);
	int k = 0;
	int i = start;
	while(i < end){
		dest[k++] = s[i++];
	}
	return dest;
}
int longestSubstringWithoutRepeatingCharacters(char *s) {
	int n = strlen(s);
	unsigned int table[255];
	
	for(int i=0; i<255; i++){
		table[i] = false;
	}
	
	int maxLength = 0, i = 0, j = 0;
	while (i < n && j < n) {
		if (!table[s[j] -'a']){
			table[s[j++] -'a'] = true;
			int length = j-i;
			maxLength = MAX(maxLength, length);
		}
		else {
			table[s[i++] -'a'] = false;
		}
	}
	return maxLength;
}

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

