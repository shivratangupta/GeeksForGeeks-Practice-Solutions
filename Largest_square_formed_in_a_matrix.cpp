/*
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0
*/


int largestSquare(vector<vector<int> > &matrix){
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 1)
                matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j]));
    
        }
    }
    
    int result;
    result = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] > result)
                result = matrix[i][j];
        }
    }
    
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int m, n;
	    cin>>m>>n;
	    
	    vector<vector<int> > matrix(m, vector<int> (n));
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            int num;
	            cin>>num;
	            matrix[i][j] = num;
	        }
	    }
	    
	    cout<<largestSquare(matrix)<<endl;
	}
	return 0;
}