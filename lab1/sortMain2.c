#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
int main(int argc, char * argv[])
{
int data[100000]; /* Array of ints to sort */
int nDataItems; /* number of actual items in the array */
int i;

/*wroked on with aadil bholat, i woked on the index while aadil worked on the for loops*/
if (argc>1){
	nDataItems=argc-1;
		for(i=0;i<nDataItems; i++){
			data[i]=atoi(argv[i+1]);}/*converts string to integer representatin*/

	mySort(data, nDataItems);
		for (i=0; i<nDataItems; i++){
		printf("%d\n", data[i]);}
	exit(0);
	}/*end of if statment*/

else{
/* Test data */
nDataItems = 4;
data[0] = 10;
data[1] = 20;
data[2] = 30;
data[3] = 40;
mySort(data, nDataItems);

/* Check that the data array is sorted. */
for(i = 0; i < nDataItems-1; i++) {
if (data[i] > data[i+1]) {/*if the data in the index is greater than the next data in the next index then there is an error*/
fprintf(stderr, "Sort error: data[%d] (= %d)"
" should be <= data[%d] (= %d)- -aborting\n",
i, data[i], i+1, data[i+1]);
exit(1);
}
}


/* Print sorted array to stdout */
for(i = 0; i < nDataItems; i++) {/*for loop that goes through the array*/
printf("%d\n", data[i]);
}
exit(0);
}
}/*end of else*/
