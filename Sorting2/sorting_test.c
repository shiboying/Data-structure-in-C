#include "sorting.h"

void printlist(int d[], int n){
	int i;
	for(i=0;i<6;i++){
		printf("(%d)",d[i]);
	}
	printf("\n");
}


int main(int argc, const char * argv[]){
    int d[8]={4,3,6,2,1,5};
	
	printlist(d,6);
	
	// Insert_Sort_Better(d,6);
	// printlist(d,6);

	// Insert_Shell_Sort(d,6);
	// printlist(d,6);

	// Bubble_Sort(d,6);
	// printlist(d,6);

	// Bubble_Sort2(d,6);
	// printlist(d,6);

	//     MergeSort(d,6);
	// printlist(d,6);
	
	Quick_Sort(d,0,5);
	printlist(d,6);
}
