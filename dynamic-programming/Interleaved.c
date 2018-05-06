#include <stdio.h>
#include <string.h>
#define true 1
#define false 0; 
 
int isInterleaved(char *c, char *a, char *b){

    int lenA = strlen(a);
    int lenB = strlen(b);
    int i,j;

    int Table[lenA+1][lenB+1];
    // Initialization
	for(i=0; i<=lenA; i++){
        for(j=0; j<=lenB; j++){
        	Table[i][j] = false;
        }
	}
    for(i=0; i<=lenA; i++){
        for(j=0; j<=lenB; j++){
        	// Both strings are empty
            if(i==0 && j==0)
                Table[i][j] = true;
    		// string A is empty, compare characters in C and B
            if(i==0 && c[j-1] == b[j-1]){
                Table[i][j] =  Table[i][j-1];
            }
            // string B is empty, compare characters in C and A
	        else if(j==0 && c[i-1] == a[i-1]){
                Table[i][j] =  Table[i-1][j];
            }
            // Both strings are not empty
            //1. If character of A matches with character of C
            // but not of B
            else if (a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1]){
                Table[i][j] = Table[i-1][j];
            }
            //2. If character of B matches with character of C
            // but not of A
            else if (a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]){
                Table[i][j] = Table[i][j-1];
            }
            //1. If character of A matches with character of C
            // and charactetr of B also matches with C
            else if (a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]){
                Table[i][j] = Table[i-1][j] || Table[i][j-1];
            }
        }
    }
    return Table[lenA][lenB];
}


int isInterleaved(char *c, char *a, char *b){

    if(!(*c) && !(*a) && !(*b))
        return true;

    if(*c == '\0'){
        return false;
    }
	 // if character of a and c match
    return ((*c == *a) && isInterleaved(c+1,a+1,b)) || 
    		// if character of b and c match
            ((*c == *b) && isInterleaved(c+1,a,b+1)); 
}

int isInterleaved(char *c, char *a, char *b){

    while(*c != '\0'){
    	if(*c == *a){
            a++;
        }
        else if(*c == *b){
            b++;
        }
        else{
            return false;
        }
        c++;
    }
    if(*a != '\0' || b != '\0')
        return false;

    return true;
}

int main(void) {
	// your code goes here
	char *c = "abxycdz";
	char *a = "abcd";
	char *b = "xyz";
	if(isInterleaved(c,a,b)){
		printf("\n String is interleaved");
	}
	else{
		printf("\n String is not interleaved");
	}
	return 0;
}
