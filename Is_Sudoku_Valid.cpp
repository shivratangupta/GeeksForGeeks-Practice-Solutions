/*
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to check if the configuration has a solution or not. 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.

Output:
For each test case in a new line print 1 if the sudoku configuration is valid else print 0.

Constraints:
1<=T<=10
0<=mat[]<=9

Example:
Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 4 3 0 7 

Output:
1
0
*/

using namespace std;

bool notInRow(vector<vector<int> > &board, int row){
    unordered_set<int> s;
    
    for(int i=0; i<9; i++){
        if(s.find(board[row][i]) != s.end())
            return false;
            
        if(board[row][i] != 0)
            s.insert(board[row][i]);
    }
    
    return true;
}

bool notInCol(vector<vector<int> > &board, int col){
    unordered_set<int> s;
    
    for(int i=0; i<9; i++){
        if(s.find(board[i][col]) != s.end())
            return false;
            
        if(board[i][col] != 0)
            s.insert(board[i][col]);
    }
    
    return true;
}

bool notInGrid(vector<vector<int> > &board, int row, int col){
    unordered_set<int> s;
    
    for(int i=row; i<row+3; i++){
        for(int j=col; j<col+3; j++){
            if(s.find(board[i][j]) != s.end())
                return false;
                
            if(board[i][j] != 0)
                s.insert(board[i][j]);
        }
    }
    
    return true;
}

bool isValidSudoku(vector<vector<int> > &board){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!(notInRow(board, i) && notInCol(board, j) && notInGrid(board, i - i % 3, j - j % 3)))
                return false;
        }
    }
    
    return true;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    vector<vector<int> > board(9, vector<int> (9));
	    for(int i=0; i<9; i++){
	        for(int j=0; j<9; j++){
	            int num;
	            cin>>num;
	            board[i][j] = num;
	        }
	    }
	    
	    cout<<isValidSudoku(board)<<endl;
	}
	return 0;
}