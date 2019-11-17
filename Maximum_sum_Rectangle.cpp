/*
Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum subarray is highlighted with blue rectangle and sum of this subarray is 29.

                                                          

Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29
*/


using namespace std;

int kadane(vector<int> &arr, int &start, int &finish){
    if(arr.size() == 0)
        return 0;
        
    int curr, best, st;
    curr = 0;
    best = INT_MIN;
    st = 0;
    
    for(int i=0; i<arr.size(); i++){
        curr += arr[i];
        
        if(curr < 0){
            curr = 0;
            st = i + 1;
        }
        
        if(curr > best){
            best = curr;
            start = st;
            finish = i;
        }
    }
    
    if(finish != -1)
        return best;
        
    best = arr[0];
    start = 0;
    finish = 0;
    
    for(int i=1; i<arr.size(); i++){
        if(arr[i] > best){
            best = arr[i];
            start = i;
            finish = i;
        }
    }
    
    return best;
}

int maximumSumRectangle(vector<vector<int> > &nums){
    if(nums.size() == 0)
        return 0;
    
    int m, n, left, right, top, bottom, maxsum;
    m = nums.size();
    n = nums[0].size();
    maxsum = INT_MIN;
    
    for(int i=0; i<n; i++){
        vector<int> arr(m);
        for(int j=i; j<n; j++){
            
            for(int k=0; k<m; k++)
                arr[k] += nums[k][j];
                
            int sum, start, finish;
            
            sum = kadane(arr, start, finish);
            
            if(sum > maxsum){
                maxsum = sum;
                left = i;
                right = j;
                top = start;
                bottom = finish;
            }
        }
    }
    
    return maxsum;
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
	    
	    cout<<maximumSumRectangle(matrix)<<endl;
	}
	return 0;
}