/*
Given a string, eliminate all “b” and “ac” in the string, replace them in-place and iterate over the string once.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string of length N.

Output:
Print the resultant substring after removing 'b' and 'ac' from string.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 200

Example:
Input:
2
acbac
aababc

Output:

aaac
*/


string removeString(string s){
    if(s.size() == 0)
        return s;
    
    int j, n;
    n = s.size();
    j = 0;
    
    for(int i=0; i<n; i++){
        if(s[i] != 'a' && s[i] != 'b'){
            s[j] = s[i];
            j++;
        }
        
        else if(i < n - 1 && s[i] == 'a' && s[i + 1] == 'c')
            i++;
            
        else if(s[i] == 'a'){
            s[j] = s[i];
            j++;
        }
    }
    
    s.erase(j, n - j);
    
    return s;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<removeString(s)<<endl;
	}
	return 0;
}