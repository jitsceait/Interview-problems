#include <iostream>
#include <algorithm>
using namespace std;

typedef struct box {
    int width;
    int depth;
    int height;
} Box;

bool boxComparator(Box b1, Box b2) {
    return ( b1.depth * b1.width > b2.depth * b2.width );
}
 
int findMaxHeightBoxStack(Box boxes[], int n)
{
	int H[n];
	for(int i=0; i<n; i++){
		H[i] = boxes[i].height;
	}
    for(int i=1; i<n; i++){
    	for( int j=i-1; j>=0; j--){
    		if(boxes[j].width > boxes[i].width 
    		   && boxes[j].depth > boxes[i].depth 
    		   && H[j] + boxes[i].height){
    		   	H[i] = H[j] + boxes[i].height;
    		}
    	}
    }
	
	int maxHeight = 0 ;
	for(int i=0; i<n; i++){
		if(maxHeight < H[i]){
			maxHeight = H[i];
		}
	}
	return maxHeight;
}

int boxStacking(Box boxes[], int n)
{
	
	Box orientations[3*n]; //for rotations
	int index = 0;
	for(int i=0; i<n; i++){
		orientations[index] = boxes[i]; // first one as such
		index++;
		
		orientations[index].height = boxes[i].width;
		orientations[index].width = max( boxes[i].height, boxes[i].depth) ;
		orientations[index].depth = min( boxes[i].height, boxes[i].depth);
		
		index++;
		orientations[index].height = boxes[i].depth;
		orientations[index].width = max( boxes[i].height, boxes[i].width) ;
		orientations[index].depth = min( boxes[i].height, boxes[i].width) ;
		index++;
	}
	n = 3*n;

    sort(orientations, orientations+n, boxComparator);
	return findMaxHeightBoxStack( orientations, n);
}
 
// Driver program
int main()
{
    //Job jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    Box boxes[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(boxes)/sizeof(boxes[0]);
    cout << "Maximum height is " << boxStacking(boxes, n);
    return 0;
}
