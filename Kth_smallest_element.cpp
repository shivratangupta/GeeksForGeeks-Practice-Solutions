/*
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N
*/

#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j){
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int search(vector<int> &nums, int k, int start, int end){
    int i, pivot;
    i = start - 1;
    pivot = nums[end];
    
    for(int j=start; j<end; j++){
        if(nums[j] < pivot){
            i++;
            swap(nums, i, j);
        }
    }
    
    i++;
    swap(nums, i, end);
    
    if(i - start + 1 == k)
        return nums[i];
        
    else if(k > i - start + 1)
        return search(nums, k - i - 1 + start, i + 1, end);
        
    else
        return search(nums, k, start, i - 1);
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, k;
	    cin>>n;
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cin>>k;
	    cout<<search(nums, k, 0, n - 1)<<endl;
	}
	return 0;
}