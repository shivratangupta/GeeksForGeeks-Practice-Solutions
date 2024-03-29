/*
Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains T, number of test cases. First line of line each test case contains a single integer N.
Next line contains N integer array.

Output:
Print the output of each test case in a seprate line.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.
*/


int longestConsecutiveSub(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    
    unordered_set<int> s;
    
    for(int i=0; i<nums.size(); i++)
        s.insert(nums[i]);
        
    int result, count;
    result = 0;
    
    for(int i=0; i<nums.size(); i++){
        if(s.find(nums[i] - 1) == s.end()){
            count = 1;
            
            while(s.find(nums[i] + count) != s.end())
                count++;
            
            result = max(result, count);
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
	    
	    cout<<longestConsecutiveSub(nums)<<endl;
	}
	return 0;
}