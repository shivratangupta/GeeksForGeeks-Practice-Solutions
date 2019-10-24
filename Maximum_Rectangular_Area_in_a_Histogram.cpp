/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9

Explanation:
Testcase1:

*/

using namespace std;

long long maximumRectangle(vector<long long> &nums){
    if(nums.size() == 0)
        return 0;
        
    stack<long long> s;
    long long maxArea, n, i;
    n = nums.size();
    maxArea = 0;
    i = 0;
    
    while(i < n){
        if(s.empty() || nums[i] >= nums[s.top()]){
            s.push(i);
            i++;
        }
            
        else{
            long long height, width, currArea;
            height = nums[s.top()];
            s.pop();
            
            if(s.empty())
                width = i;
                
            else
                width = i - s.top() - 1;
            
            currArea = height * width;
            
            if(currArea > maxArea)
                maxArea = currArea;
        }
    }
    
    while(!s.empty()){
        long long height, width, currArea;
        height = nums[s.top()];
        s.pop();
        
        if(s.empty())
            width = n;
            
        else
            width = n - s.top() - 1;
        
        currArea = height * width;
        
        if(currArea > maxArea)
            maxArea = currArea;
    }
    
    return maxArea;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    vector<long long> nums;
	    for(int i=0; i<n; i++){
	        long long num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<maximumRectangle(nums)<<endl;
	}
	return 0;
}