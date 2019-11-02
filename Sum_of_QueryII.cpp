/*
You are given an array and q queries which contains 2 positions in the array l and r.

You need to compute the following sum over q queries.

 

Array is 1-Indexed

Input:

The first line of input contains T test cases. 

The first line of each test case contains the number of elements in the array.

The second line of each test case contains the elements of the array.

The third line of each test case contains Q queries.

The final line of each test case contains the 2 *Q elements where the first element contains l and second element contains r. 

Output:

For each test case, print the required sum values in a single line seprated by blank spaces. Print the output of each test case in a new line.


Constraints:
 

1 <= T <= 100

1 <= N <= 1000

0 <= Arr[i] <= 10^6 

1 <= Q <= 1000

1 <= l <= r <= N

 Example:

Input:

1
4
1 2 3 4
2 
1 4 2 3 

Output:

10 5
*/


vector<int> sumArray(vector<int> &nums){
    int n;
    n = nums.size();
    
    vector<int> result;
    result.push_back(0);
    for(int i=0; i<n; i++)
        result.push_back(nums[i] + result[i]);
        
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n, q;
	    cin>>n;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    vector<int> result;
	    result = sumArray(nums);
	    
	    cin>>q;
	    for(int i=0; i<q; i++){
	        int l, r;
	        cin>>l>>r;
	        
	        cout<<result[r] - result[l - 1]<<" ";
	    }
	    
	    cout<<endl;
	}
	return 0;
}