/*
Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, print number of shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.
*/


void dfs(vector<vector<char> > &arr, vector<vector<bool> > &visited, int i, int j){
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
        return;
        
    if(visited[i][j])
        return;
    
    if(arr[i][j] != 'X')
        return;
        
    visited[i][j] = true;
    
    dfs(arr, visited, i + 1, j);
    dfs(arr, visited, i - 1, j);
    dfs(arr, visited, i, j + 1);
    dfs(arr, visited, i, j - 1);
}

int countIslands(vector<vector<char> > &arr){
    if(arr.size() == 0)
        return 0;
    
    int m, n, count;
    m = arr.size();
    n = arr[0].size();
    
    vector<vector<bool> > visited(m, vector<bool> (n, false));
    count = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'X' && !visited[i][j]){
                dfs(arr, visited, i, j);
                count++;
            }
        }
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int m, n;
	    cin>>m>>n;
	    
	    vector<vector<char> > arr(m, vector<char> (n));
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            char c;
	            cin>>c;
	            arr[i][j] = c;
	        }
	    }
	    
	    cout<<countIslands(arr)<<endl;
	}
	return 0;
}