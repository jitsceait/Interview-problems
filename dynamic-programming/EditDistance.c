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

int editDistance(char *s1, char *s2){
	int n = strlen(s1);
	int m = strlen(s2);
 
    int minimumDistance = 0;
    int currentMinimum  = 0;
    int Table[n+1][m+1] ;
    
    memset(Table,0, sizeof(Table));
    
    //Intitialization
    for(int i=0; i<=n; i++)
        Table[i][0] =i;

    for(int i=1; i<=m; i++)
        Table[0][i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            //Case 3 : Possibility 1 :If X[i] == Y[j] 
            if(s1[i-1] == s2[j-1]){
                currentMinimum = Table[i-1][j-1];
            }
            //Case 3 : Possibility 2 :If X[i] != Y[j] 
            else{
                currentMinimum =  Table[i-1][j-1] + 1;
            }
            //Case 1 : Deletion of character from S1 
            if(Table[i][j-1] > Table[i-1][j]){
                minimumDistance = Table[i-1][j] + 1;
            }
            //Case 2 : Addition of character on S1 
            else {
                minimumDistance = Table[i][j-1] + 1;
            }

            if(currentMinimum < minimumDistance){
            	minimumDistance = currentMinimum;
            }
            Table[i][j] = minimumDistance;
        }
    }
    return Table[n-1][m-1];
}

int main(){

    char *s = "EXPONENTIAL";
    char *d = "POLYNOMIAL";
    printf("Minimum distance between two strings is : %d", editDistance(s,d, strlen(s), strlen(d)));
    return 0;
}
