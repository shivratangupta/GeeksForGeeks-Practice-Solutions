/*
Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers N and M. Second line of each test case contains N space separated integers denoting the elements of first array. Third line of each test case contains M space separated integers denoting the elements of second array.

Output:
For each test case, print 1 if there exists any such pair otherwise print -1.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= M <= 104
0 <= elements <= 104

Example:
Input:
2
6 4
4 1 2 1 1 2
3 6 3 3
4 4
5 7 4 6
1 2 3 8

Output:
1
1

Explanation:
Testcase 1: 1 and 3 are two such values one from first array other from second one, if we swap these two values then we will get both arrays sum as equal.
*/

using namespace std;

int getTarget(vector<int> &nums1, vector<int> &nums2){
    int sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    
    for(int i=0; i<nums1.size(); i++)
        sum1 += nums1[i];
    
    for(int i=0; i<nums2.size(); i++)
        sum2 += nums2[i];
    
    if((sum1 - sum2) % 2 != 0)
        return 0;
        
    return (sum1 - sum2) / 2;
}

int findPair(vector<int> &nums1, vector<int> &nums2){
    if(nums1.size() == 0 || nums2.size() == 0)
        return -1;
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int target;
    target = getTarget(nums1, nums2);
    
    if(target == 0)
        return -1;
    
    int i, j, m, n;
    i = 0;
    j = 0;
    m = nums1.size();
    n = nums2.size();
    
    while(i < m && j < n){
        int diff;
        diff = nums1[i] - nums2[j];
        
        if(diff == target)
            return 1;
        
        else if(diff < target)
            i++;
        
        else
            j++;
    }
    
    return -1;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int m, n;
	    cin>>m>>n;
	    
	    vector<int> nums1;
	    vector<int> nums2;
	    
	    for(int i=0; i<m; i++){
	        int num;
	        cin>>num;
	        nums1.push_back(num);
	    }
	    
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums2.push_back(num);
	    }
	    
	    cout<<findPair(nums1, nums2)<<endl;
	}
	return 0;
}