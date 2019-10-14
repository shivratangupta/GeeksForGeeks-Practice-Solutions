/*
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Input Format:
First line of input contains number of testcases T. For each testcase, the only line contains the number x.

Output Format:
For each testcase, print square root of given integer.

User Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Constraints:
1 ≤ T ≤ 1000
1 ≤ x ≤ 107

Example:
Input:
2
5
4

Output:
2
2

Explanation:
Testcase 1: Since, 5 is not perfect square, so floor of square_root of 5 is 2.
Testcase 2: Since, 4 is a perfect square, so its square root is 2.
*/


// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    // Your code goes here
    if(x == 0)
        return 0;
        
    long long l, r, mid;
    l = 1;
    r = x / 2;
    mid = (l + r) / 2;
    
    while(l <= r){
        if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
            return mid;
            
        else if(mid * mid < x)
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
    }
}