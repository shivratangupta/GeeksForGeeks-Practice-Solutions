/*
Given a string s, find out the count of all contiguous substrings whose starting and ending are same character.
Note: string contains lowercase English alphabets only.

Example

Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab"
a, ab, abc, abca, abcab, b, bc, bca
bcab, c, ca, cab, a, ab, b
Out of the above substrings, there 
are 7 substrings : a, abca, b, bcab, 
c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba

Input:
The first line of each test case contains an integer T denoting the number of test cases. Then T test cases follows. The first line of each test case contains a number N denoting the length of the string (S). Then the next line contains the string S.

Output:
For each test case output a new line containing a single integer, denoting the count of all the substrings whose first and last character are same.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
5
abcab
13
geeksforgeeks
Output:
7
22
*/


int subWithSimilarAndLastChar(string s){
    if(s.size() == 0)
        return 0;
        
    vector<int> count(26, 0);
    
    for(int i=0; i<s.size(); i++)
        count[s[i] - 'a']++;
        
    int result;
    result = s.size();
    
    for(int i=0; i<26; i++){
        int n;
        n = count[i];
        
        if(n >= 2)
            result += (n * (n - 1) / 2);
    }
    
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    string s;
	    cin>>s;
	    
	    cout<<subWithSimilarAndLastChar(s)<<endl;
	}
	return 0;
}	