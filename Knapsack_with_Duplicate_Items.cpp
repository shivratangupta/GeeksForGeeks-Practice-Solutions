/*
Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1 
4 8
1 4 5 7
1 3 4 5
Output:
3
11
*/


int knapsackWithDuplicate(vector<int> &values, vector<int> &weights, int w){
    if(values.size() == 0)
        return 0;
        
    int n;
    n = values.size();
    
    vector<int> dp(w + 1);
    
    for(int i=0; i<=w; i++){
        for(int j=0; j<n; j++){
            if(i >= weights[j])
                dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
        }
    }
    
    return dp[w];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, w;
	    cin>>n>>w;
	    
	    vector<int> values;
	    vector<int> weights;
	    
	    for(int i=0; i<n; i++){
	        int value;
	        cin>>value;
	        values.push_back(value);
	    }
	    
	    for(int i=0; i<n; i++){
	        int weight;
	        cin>>weight;
	        weights.push_back(weight);
	    }
	    
	    cout<<knapsackWithDuplicate(values, weights, w)<<endl;   
	}
	return 0;
}