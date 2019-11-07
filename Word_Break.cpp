/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0
*/


bool wordBreak(vector<string> &words, string s){
    unordered_set<string> st;
    
    for(int i=0; i<words.size(); i++)
        st.insert(words[i]);
    
    int n;
    n = s.size();
    
    vector<bool> dp(n + 1, false);
    
    for(int i=0; i<=n; i++){
        if(dp[i] == false && st.find(s.substr(0, i)) != st.end())
            dp[i] = true;
            
        if(dp[i] == true){
            if(i == n)
                return true;
                
            else{
                for(int j=i+1; j<=n; j++){
                    if(dp[j] == false && st.find(s.substr(i, j - i)) != st.end())
                        dp[j] = true;
                        
                    if(j == n && dp[j] == true)
                        return true;
                }
            }
        }
    }
    
    return false;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
    for(int l=0; l<t; l++){
        int n;
        cin>>n;
        
        vector<string> words;
        for(int i=0; i<n; i++){
            string word;
            cin>>word;
            words.push_back(word);
        }
        
        string s;
        cin>>s;
        
        cout<<wordBreak(words, s)<<endl;
    }
	return 0;
}