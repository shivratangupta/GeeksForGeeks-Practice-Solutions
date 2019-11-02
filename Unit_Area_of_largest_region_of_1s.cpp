/*
Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 6 1s (colored in Red).
*/


void dfs(vector<vector<int> > &matrix, vector<vector<bool> > &visited, int i, int j, int &count){
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        return;
    
    if(visited[i][j])
        return;
    
    if(matrix[i][j] != 1)
        return;
    
    count++;
    visited[i][j] = true;
    
    dfs(matrix, visited, i + 1, j, count);
    dfs(matrix, visited, i - 1, j, count);
    dfs(matrix, visited, i, j + 1, count);
    dfs(matrix, visited, i, j - 1, count);
    dfs(matrix, visited, i + 1, j + 1, count);
    dfs(matrix, visited, i + 1, j - 1, count);
    dfs(matrix, visited, i - 1, j + 1, count);
    dfs(matrix, visited, i - 1, j - 1, count);
}

int largestRegion(vector<vector<int> > &matrix){
    if(matrix.size() == 0)
        return 0;
    
    int m, n, maxregion;
    m = matrix.size();
    n = matrix[0].size();
    maxregion = 0;
    
    vector<vector<bool> > visited(m, vector<bool> (n, false));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1 && !visited[i][j]){
                int count;
                count = 0;
                
                dfs(matrix, visited, i, j, count);
                
                if(count > maxregion)
                    maxregion = count;
            }
        }
    }
    
    return maxregion;
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
	    
	    cout<<largestRegion(matrix)<<endl;
	}
	return 0;
}