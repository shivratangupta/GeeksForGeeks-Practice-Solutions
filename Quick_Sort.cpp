/*
Given an array arr[] of size N. The task is to complete partition() function which is used to implement Quick Sort.

Input Format:
First line of the input denotes number of test cases 'T'. First line of the test case is the size of array and second line consists of array elements.

Output Format:
For each testcase, in a new line, print the sorted array.

Your Task:
This is a function problem. You only need to complete the function partition(). The printing is done automatically by the driver code.

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation:
Testcase 1: Elements in sorted form are 1 3 4 7 9.
*/


void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/
/* This function takes last element as pivot, places  the pivot element 
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int arr[], int low, int high)
{
   // Your code here
    if(low == high)
        return arr[low];
        
    int i, pivot;
    i = low - 1;
    pivot = arr[high];
    
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }    
    }
    i++;
    
    int temp;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    
    return i;
}