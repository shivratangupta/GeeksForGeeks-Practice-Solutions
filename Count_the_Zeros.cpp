/*
Given an array of size N consisting of only 0's and 1's ,which is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. You have to find  the count of all the 0's.
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N, where N is the size of the array A[ ].
The second line of each test case contains N space separated integers of all 1's follwed by all the 0's, denoting elements of the array A[ ].


Output:
Print out the number of 0's in the array. 
 

Constraints:
1 <= T <= 100
1 <= N <= 30
0 <= A[i] <= 1
 

Example :

Input:
3
12
1 1 1 1 1 1 1 1 1 0 0 0 
5
0 0 0 0 0
6
1 1 1 1 1 1


Output:
3
5
0
 

Expected Complexity:

O(logN)
*/

#include<vector>
using namespace std;

int countZeros(vector<int> &nums){
    int n;
    n = nums.size();
    
    if(n == 0)
        return 0;
        
    int l, r, mid;
    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    
    while(l <= r){
        if(nums[mid] == 0 && (mid == 0 || nums[mid - 1] == 1))
            return n - mid;
            
        else if(nums[mid] == 1)
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
    }
    
    return 0;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<countZeros(nums)<<endl;
	}
	return 0;
}