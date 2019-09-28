/*
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the window size k.

Output:
Print the space separated negative integer starting from the first till the end for every window size k. If a window does not contain a negative integer , then print 0 for that window.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n
*/

#include<vector>
#include<list>
#include<queue>
using namespace std;

void negSlidingWin(vector<int> &nums, int k){
    queue<int> q;
    
    for(int i=0; i<k; i++){
        if(nums[i] < 0)
            q.push(i);
    }
    
    if(q.empty())
        cout<<0<<" ";
    
    else
        cout<<nums[q.front()]<<" ";
    
    for(int i=k; i<nums.size(); i++){
        if(nums[i] < 0){
            q.push(i);
        }
        
        if(!q.empty() && i - q.front() >= k)
            q.pop();
            
        if(q.empty())
            cout<<0<<" ";
            
        else
            cout<<nums[q.front()]<<" ";
    }
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
	    for(int i=0;i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    cin>>k;
	    
	    negSlidingWin(nums, k);
	    cout<<endl;
	}
	return 0;
}