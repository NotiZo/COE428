Assuming the betterSort method is a better sorting algorithm than the one used in my code, which was bubble sorting, we can call this method in the mySort method since it can't be called through the main method. Coded in the mySort method, it will look like the following down below.

void mySort(int d[], unsigned int n){
first = 0;
last = n-1;
betterSort(d, first, last);
}

first is set to 0 due to the first index in an array always starting at 0. Then last set to n-1 because I don't want to go out of bounds of the nessecary indices of the array causing an error possibly.

references:
(referenced for mySort.c)
GeeksforGeeks. (2023, November 21). Bubble sort - data structure and algorithm tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/bubble-sort/ 

collaborated with Aadil for sortMain2.c in the if statement section