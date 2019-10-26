/*
Given an array with all elements greater than or equal to zero. Return the maximum product of two numbers possible.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, size of array. The second line of each test case contains array elements.

Output:
Print the maximum product of two numbers possible.

Constraints:
1 ≤ T ≤ 100
2 ≤ N ≤ 107
0 ≤ A[i] ≤ 104

Example:
Input:
1
5
1 100 42 4 23

Output:
4200

Explanation:
Testcase 1: Two maximum numbers are 100 and 42 and their product is 4200.
*/

using namespace std;

int maximumProd(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
        
    int maximum, secondmax;
    maximum = INT_MIN;
    secondmax = INT_MIN;
    
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > maximum){
            secondmax = maximum;
            maximum = nums[i];
        }
        
        else if(nums[i] >= secondmax)
            secondmax = nums[i];
    }
    
    return maximum * secondmax;
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
	    
	    cout<<maximumProd(nums)<<endl;
	}
	return 0;
}