/*
You are given a sorted array containing only numbers 0 and 1. Find the transition point efficiently. Transition point is a point where "0" ends and "1" begins.

Input:

You have to complete the method which takes 2 argument: the array arr[] and size of array N. You should not read any input from stdin/console. There are multiple test cases. For each test cases, this method will be called individually.

Output:

Your function should return transition point.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500000
0 ≤ C[i] ≤ 1
*/

int transitionPoint(int arr[],int n)
{
// Your code goes here
    if(n == 0)
        return 0;
        
    int l, r, mid;
    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    
    while(l <= r){
        if(arr[mid] == 0 && (mid == n - 1 || arr[mid + 1] == 1))
            return mid + 1;
            
        else if(arr[mid] == 0)
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
    }
    
    return 0;
}