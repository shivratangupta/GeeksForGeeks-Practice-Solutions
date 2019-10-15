/*
You are given an array A of size N. Replace every element with the next greatest element (greatest element on its right side) in the array. Also, since there is no element next to the last element, replace it with -1.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line is N, the size of tha array. The second line contains N space separated integers.

Output:
For each testcase, print the modified array.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= Ai <= 1000

Example:
Input:
2
6
16 17 4 3 5 2
4
2 3 1 9

Output:
17 5 5 5 2 -1
9 9 9 -1

Explanation:
Testcase1: For 16 the greatest element on its right is 17. For 17 it's 5. For 4 it's 5. For 3 it's 5. For 5 it's 2. For 2 it's -1(no element to its right). So the answer is 17 5 5 5 2 -1
*/


void greaterRightSide(vector<int> &nums){
    if(nums.size() == 0)
        return;
        
    int rightmax, n;
    n = nums.size();
    rightmax = nums[n - 1];
    nums[n - 1] = -1;
    
    for(int i=n-2; i>=0; i--){
        int temp;
        temp = nums[i];
        nums[i] = rightmax;
        
        if(temp > rightmax)
            rightmax = temp;
    }
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
	    
	    greaterRightSide(nums);
	    
	    for(int i=0; i<n; i++)
	        cout<<nums[i]<<" ";
	        
	    cout<<endl;
	}
	return 0;
}