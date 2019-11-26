/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
geeksforgeeks
qwertqwer

Output:
7
5
*/


int lengthOfLongestSubstring(string s){
    if(s.size() == 0)
        return 0;
        
    int n, length, start, st, currlen;
    unordered_map<char, int> m;
    n = s.size();
    st = 0;
    length = INT_MIN;
    
    for(int i=0; i<n; i++){
        if(m.find(s[i]) == m.end())
            m[s[i]] = i;
            
        else{
            if(m[s[i]] >= st){
                currlen = i - st;
                if(currlen > length){
                    length = currlen;
                    start = st;
                }
                
                st = m[s[i]] + 1;
            }
            
            m[s[i]] = i;
        }
    }
    
    if(n - st > length){
        length = n - st;
        start = st;
    }
    
    return length;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<lengthOfLongestSubstring(s)<<endl;
	}
	return 0;
}