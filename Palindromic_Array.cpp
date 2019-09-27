/*
You are given an array A of size N. Your task is to find the minimum number of operations needed to convert the given array to 'Palindromic Array'.

Palindromic Array:
[23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.

The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, where N is the size of array.
The second line of each test case contains N space separated integers which is the input for the array.

Output:
Output the minimum number of operations required to make the given array a palindromic array.

Constraints:
1<=T<=100
1<=N<=100
*/

#include<vector>
using namespace std;

int palindromeOp(vector<int> &nums){
    int n, result, i, j;
    n = nums.size();
    if(n == 0 || n == 1)
        return 0;
    
    result = 0;
    i = 0;
    j = n - 1;
    
    while(i < j){
        if(nums[i] == nums[j]){
            i++;
            j--;
        }
        
        else if(nums[i] < nums[j]){
            i++;
            nums[i] += nums[i - 1];
            result++;
        }
        
        else{
            j--;
            nums[j] += nums[j + 1];
            result++;
        }
    }
    
    return result;
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
	    
	    cout<<palindromeOp(nums)<<endl;
	}
	return 0;
}