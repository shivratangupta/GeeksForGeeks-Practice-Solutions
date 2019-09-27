/*
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the matrix. Then the next line contains the n x n elements in row wise order.

Output:
Print the elements of the matrix in sorted order.

Constraints:
1<=T<=100
1<=n<=100
1<=a[n][n]<=100
*/

#include<vector>
#include<algorithm>
using namespace std;

void sortMatrix(vector<vector<int> > nums){
    int n;
    n = nums.size();
    
    vector<int> arr;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            arr.push_back(nums[i][j]);
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n*n; i++)
        cout<<arr[i]<<" ";
}

int main()
 {
	//code
	int t;
	cin>>t;
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    vector<vector<int> > nums(n, vector<int> (n));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            int num;
	            cin>>num;
	            nums[i][j] = num;
	        }
	    }
	    
	    sortMatrix(nums);
	    cout<<endl;
	}
	return 0;
}