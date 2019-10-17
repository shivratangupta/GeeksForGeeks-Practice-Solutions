/*
Given an array of integers, and an integer  ‘K’ , find the count of pairs of elements in the array whose sum is equal to 'K'.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains 2 space separated integers N and K denoting the size of array and the sum respectively. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
Print the count of pairs of elements in the array whose sum is equal to the K.

Constraints:
1<=T<=50
1<=N<=50
1<=K<=50
1<=A[i]<=100

Example:
Input
2
4 6
1  5  7 1
4 2
1 1 1 1
Output
2
6
*/


int countPairs(vector<int> &nums, int k){
    if(nums.size() == 0)
        return 0;
        
    unordered_map<int, int> m;
    int result;
    result = 0;
    
    for(int i=0; i<nums.size(); i++)
        m[nums[i]]++;
        
    for(int i=0; i<nums.size(); i++){
        if(m.find(k - nums[i]) != m.end())
            result += m[k - nums[i]];
            
        if(k - nums[i] == nums[i])
            result--;
    }
    
    return result / 2;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, k;
	    cin>>n>>k;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<countPairs(nums, k)<<endl;
	}
	return 0;
}