/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is 

1 2 3 4 5 6 7 8 9

Then the rotated array becomes: 

7 4 1 8 5 2 9 6 3

Input:

The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains an integer 'N' denoting the size of the 2D square matrix.

And in the second line, the elements of the matrix A[][], each separated by a space in row major form.


Output:

For each test case, print the elements of the rotated array row wise, each element separated by a space. Print the output of each test case in a new line.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 10
1 ≤ A [ i ][ j ] ≤ 100


Example:

Input:

2
3
1 2 3 4 5 6 7 8 9
2
56 96 91 54

Output:

7 4 1 8 5 2 9 6 3
91 56 54 96
*/


void rotateArray(vector<vector<int> > &nums){
    int n;
    n = nums.size();
    
    if(n == 0)
        return;
        
    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int temp;
            temp = nums[i][j];
            nums[i][j] = nums[n-1-j][i];
            nums[n-1-j][i] = nums[n-1-i][n-1-j];
            nums[n-1-i][n-1-j] = nums[j][n-1-i];
            nums[j][n-1-i] = temp;
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
	    
	    vector<vector<int> > nums(n, vector<int> (n));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            int num;
	            cin>>num;
	            nums[i][j] = num;
	        }
	    }
	    
	    rotateArray(nums);
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++)
	            cout<<nums[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}
	return 0;
}