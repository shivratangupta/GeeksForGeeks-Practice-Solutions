/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

For Example:
If the matrix is    

1 2 3
4 5 6
7 8 9
The output should Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
i.e print the elements of array diagonally.

Note: The input array given is in single line and you have to output the answer in one line only.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.


Output:

Print the elements of matrix diagonally in separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 20
0 ≤ A[i][j] ≤ 9
*/

#include<vector>
using namespace std;

void printDiagonally(vector<vector<int> > &matrix){
    if(matrix.size() == 0)
        return;
    
    int n, i, j;
    n = matrix.size();
    
    for(int l=1; l<n*2; l++){
        i = 0;
        if(l > n)
            i = l - n;
            
        j = n - 1;
        if(l < n)
            j = l - 1;
            
        while(i < n && j >= 0){
             cout<<matrix[i][j]<<" ";
             i++;
             j--;
        }
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    vector<vector<int> > matrix(n, vector<int> (n));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            int num;
	            cin>>num;
	            matrix[i][j] = num;
	        }
	    }
	    
	    printDiagonally(matrix);
	    cout<<endl;
	}
	return 0;
}