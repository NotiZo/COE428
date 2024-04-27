#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
		int temp, j;
		for(int i=first; i<=last; i++){//from first index to last index
			temp=array[i];
			j=i-1;//one less than i
			
			//loops until it finds a index where the number stored at array[j] is bigger than the one that was at array[i], and then inserts it into the right spot
			for (j = i - 1; j >= 0 && myCompare(array[j], temp) > 0; j--){//my compare method checks array[j]-temp, less than 1 means smaller, 0 means equal, greater than 1 means bigger
         		
				mySwap(&array[j + 1], &array[j]);//swaps the two values
				}

		//inserts temp into the correct position, j is the index of the last element that was compared with temp
		//for example [5,2,4,3,1]->[5,5,4,3,1] after the inner loop->[2,5,4,3,1] after the myCopy method
		myCopy(&temp, &array[j + 1]);//copies temp into array[j+1] e.g. array[j+1]=temp
				
		}
    }
