#include<stdio.h>
#include<string.h>

int min(int a, int b) {
	int min = a > b ? b : a;
	return min;
}

int editDistance(char *s1, char *s2, int length1, int length2){
	
	printf("\nlength1 = %d, length2 = %d" , length1, length2);
	
	if(length1 == 0 && length2 == 0) return 0;
	
	if(length1 == 0) return length2;
	
	if(length2 == 0) return length1;
	
	int isCharacterEqual = s1[length1] == s2[length2] ? 0 : 1;
        return min(min( (1+ editDistance(s1,s2, length1-1, length2)),
        		( 1+ editDistance(s1,s2,length1, length2-1))),
        		( isCharacterEqual + editDistance(s1,s2, length1-1,length2-1)) );
}
//Driver program
int main(){

    char *s = "EXPONENTIAL";
    char *d = "POLYNOMIAL";
    printf("Minimum distance between two strings is : %d", editDistance(s,d, strlen(s), strlen(d)));
    return 0;
}
