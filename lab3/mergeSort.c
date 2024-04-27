#include "mySort.h"
void merge(int array[], int left, int middle, int right){
    int temp[MAX_SIZE_N_TO_SORT];
    int first=left;
    int second=middle+1;
    int tindex=0;

    //merge temporary arrays into one
    while (first<=middle&&second<=right) {
        if (myCompare(array[first], array[second]) < 0) {
            temp[tindex]=array[first];
            tindex++;
            first++;
        } else {
            temp[tindex]=array[second];
            tindex++;
            second++;
        }
    }

    //copy remaining elements of left
    while (first <= middle) {
        myCopy(&array[first], &temp[tindex]);
        tindex++;
        first++;
    }
    //copy remaining elements of Right
    while (second <= right) {
        myCopy(&array[second], &temp[tindex]);
        tindex++;
        second++;
    }

    //swaps the array and temp index's
    for(int i=0; i<tindex;i++){
        mySwap(&array[left+i],&temp[i]);
    }
}
void mySort(int array[], unsigned int first, unsigned int last)
    {
        int middle;
        if(first<last){
            middle=(first+last)/2;

            //sort first&second halves
            mySort(array,first,middle);
            mySort(array,middle+1,last);

            //merge
            merge(array,first,middle,last);
        }
        
    }
