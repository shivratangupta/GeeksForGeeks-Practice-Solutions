/*
Given street of houses (a row of houses), each house having some amount of money kept inside; now there is a thief who is going to steal this money but he has a constraint/rule that he cannot steal/rob two adjacent houses. Find the maximum money he can rob.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and money.

Output:
Print maximum money he can rob.

Constraints:
1 ≤ T ≤ 100
1 ≤ money ≤ 100
1 ≤ N ≤ 1000

*/

#include<vector>
using namespace std;

int robMoney(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    
    int a, b, maxrob;
    a = nums[0];
    if(nums.size() == 1)
        return a;
        
    b = max(a, nums[1]);
    if(nums.size() == 2)
        return b;
        
    for(int i=2; i<nums.size(); i++){
        maxrob = max(a + nums[i], b);
        a = b;
        b = maxrob;
    }
    
    return maxrob;
}

int main()
{
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, money;
	    cin>>n;
	    cin>>money;
	    vector<int> nums(n, money);
	    cout<<robMoney(nums)<<endl;
	}
	return 0;
}