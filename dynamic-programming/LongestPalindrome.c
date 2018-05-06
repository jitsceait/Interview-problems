#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int longestPalindrome(char *s){

  int i,j,k, n;
  int longestEnd =0, longestStart=0;

  n = strlen(s);
/* This is case which handles odd length string */
   for(i=0; i<n; i++){
       for(j=i-1, k=i+1; j>=0 && k<=n; ){
   /* If characters are equal, update left and right index. */
           if(s[j] == s[k] ){
                k++;
                j--;
           }
           else
                break;
       }
  /* Check if current sub-string length is greater 
    than earlier max, If yes, update it */
      if(longestEnd - longestStart < k-j)
      {
          longestEnd = k;
          longestStart = j;
      }
 }
/* This is case which handles even length string */
  for(i=1; i<n; i++){
       for(j=i, k=i+1; j>=0 && k<=n; ){
            if(s[j] == s[k] ){
                k++;
                j--;
            }
            else
                break;
       }
       if(longestEnd - longestStart < k-j)
       {
            longestEnd = k;
            longestStart = j;
       }
  }
  return longestEnd - longestStart - 1;
}

int longestPalindrome(char * s) {
  int n = strlen(s);
  
  int longestBegin = 0;
  int maxLen = 1;
  int table[n+1][n+1];
  for (int i = 0; i <= n; i++) {
  	for (int j = 0; j <= n; j++) {
  		table[i][j] = false;
  	}
  }
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  return maxLen;
}
int main()
{
    char str[] = "ABCDCBEA";
    printf("\nLength is: %d\n", longestPalindrome( str ) );
    return 0;
}
