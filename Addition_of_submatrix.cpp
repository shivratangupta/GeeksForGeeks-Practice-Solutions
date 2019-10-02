/*
Given a matrix C of size N x M. You are given position of submatrix as X1, Y1 and X2, Y2 inside the matrix. Find the sum of all elements inside that submatrix.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is n and m,n is the number of rows and m is the number of columns. The second line of each test case contains C[N][M]. The third line contains four value of X1, Y1, X2, Y2. X1, Y1 is the top left cell and X2, Y2 is the bottom right cell.

Output:
Print the sum of all elements inside that submatrix.

Constraints:
1 ≤ T ≤ 15
1 ≤ N, M ≤ 103
1 ≤ C[N][M] ≤ 106
1 <= X1, Y1, X2, Y2 <= M
*/

#include<vector>
using namespace std;

int sumSubMatrix(vector<vector<int> > &matrix, int x1, int y1, int x2, int y2){
    if(matrix.size() == 0)
        return 0;
    
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    
    vector<vector<int> > arr;
    
    for(int i=0; i<=m; i++){
        vector<int> temp(n + 1);
        arr.push_back(temp);
    }
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++)
             arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + matrix[i - 1][j - 1] - arr[i -1][j -1];
    }
    
    return arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int m, n, x1, x2, y1, y2;
	    cin>>m>>n;
	    
	    vector<vector<int> > matrix(m, vector<int> (n));
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            int num;
	            cin>>num;
	            matrix[i][j] = num;
	        }
	    }
	    cin>>x1>>y1>>x2>>y2;
	    
	    cout<<sumSubMatrix(matrix, x1, y1, x2, y2)<<endl;
	}
	return 0;
}