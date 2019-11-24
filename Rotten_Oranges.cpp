/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next line contains space separated r*c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Constraints:
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will rot oranges at {0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time. And, during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}. Hence, total 2 unit of time is required to rot all oranges.
*/

using namespace std;

bool isValid(pair<int, int> p){
    if(p.first == -1 && p.second == -1)
        return false;
        
    return true;
}

void rottenOranges(vector<vector<int> > &matrix){
    if(matrix.size() == 0)
        return;
        
    queue<pair<int, int> > q;
    int m, n, result;
    m = matrix.size();
    n = matrix[0].size();
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    
    q.push(make_pair(-1, -1));
    bool flag;
    flag = false;
    result = 0;
    
    while(!q.empty()){
        
        flag = false;
        
        while(isValid(q.front())){
            pair<int, int> p;
            p = q.front();
        
            if(p.first + 1 < m && matrix[p.first + 1][p.second] == 1){
                if(!flag){
                    flag = true;
                    result++;
                }
            
                matrix[p.first + 1][p.second] = 2;    
                q.push(make_pair(p.first + 1, p.second));
            }
        
            if(p.first - 1 >= 0 && matrix[p.first - 1][p.second] == 1){
                if(!flag){
                    flag = true;
                    result++;
                }
            
                matrix[p.first - 1][p.second] = 2;
                q.push(make_pair(p.first - 1, p.second));
            }
        
            if(p.second + 1 < n && matrix[p.first][p.second + 1] == 1){
                if(!flag){
                    flag = true;
                    result++;
                }
            
                matrix[p.first][p.second + 1] = 2;
                q.push(make_pair(p.first, p.second + 1));
            }
        
            if(p.second - 1 >= 0 && matrix[p.first][p.second - 1] == 1){
                if(!flag){
                    flag = true;
                    result++;
                }
            
                matrix[p.first][p.second - 1] = 2;
                q.push(make_pair(p.first, p.second - 1));
            }
        
            q.pop();
        }
        
        q.pop();
        
        if(!q.empty())
            q.push(make_pair(-1, -1));
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1){
                cout<<-1;
                return;
            }
        }
    }
    
    cout<<result;
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
	    
	    rottenOranges(matrix);
	    
	    cout<<endl;
	}
	return 0;
}