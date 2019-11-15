/*
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/


void swap(vector<int> &nums, int i, int j){
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortArray(vector<int> &nums){
    if(nums.size() == 0)
        return;
        
    int x, y, z;
    x = 0;
    y = 0;
    z = nums.size() - 1;
    
    while(y <= z){
        if(nums[y] == 0){
            swap(nums, x, y);
            x++;
            y++;
        }
        
        else if(nums[y] == 1)
            y++;
            
        else{
            swap(nums, y, z);
            z--;
        }
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
	    
	    sortArray(nums);
	    
	    for(int i=0; i<n; i++)
	        cout<<nums[i]<<" ";
	        
	    cout<<endl;
	}
	return 0;
}