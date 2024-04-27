#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
static int size=0;
static int heap[100];

void swap(int i, int j)
{
  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void maxheapify(int i){
  int l=2*i
  int r=2*i+1
  int largest=i;

  if(l<size && heap[l]>heap[largest]){//comparing value of left child with value of largest
    largest=l;
  }
  if(r<size && heap[r]>heap[largest]){//comparing value of right child with value of largest
    largest=r;
  }
  if(largest!=i){//if the largest is no longer value of i, then swap the largest with it
    swap(i,largest);
    maxheapify(largest);//recursive call at the new largest as i
  }
  
}
/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  if(size==0){
    fprintf(stderr, "Heap underflow.");
    return -1;
  }
  int biggest=heap[0];
  heap[0]=heap[size-1];//-1 is needed cus 0 indice
  size--;//decrement
  maxheapify(0);
  return biggest;  //returns the biggest integer in the heap and removes it
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  heap[size]=thing2add;
  size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  //A dummy return statement
}
