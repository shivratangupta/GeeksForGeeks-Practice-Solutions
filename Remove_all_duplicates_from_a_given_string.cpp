/*
Given a string which may contains lowercase and uppercase chracters. The task is to remove all  duplicate characters from the string and print the resultant string.  The order of remaining characters in the output should be same as in the original string.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains a string.

Output:
Print the resultant string after removing duplicate characters from string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
geeksforgeeks
HappyNewYear

Output:
geksfor
HapyNewYr

Explanation:
Testcase 1: After removing duplicate characters such as e, k, g, s, we have string as geksfor.
*/


string removeDuplicates(string s){
    if(s.size() == 0)
        return 0;
        
    unordered_set<char> st;
    int j, n;
    n = s.size();
    j = 0;
    
    for(int i=0; i<n; i++){
        if(st.find(s[i]) == st.end()){
            s[j] = s[i];
            j++;
            st.insert(s[i]);
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
	    
	    cout<<removeDuplicates(s)<<endl;
	}
	return 0;
}