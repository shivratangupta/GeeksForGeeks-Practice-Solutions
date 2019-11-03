/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings in a sequence and the second line contains N space separated strings.

Output:
For each test case, in a new line print the second most repeated string.

Constraints:
1<=T<=100
3<=N<=103
1<=|String length|<=100

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for
*/


string secondMostRepeat(vector<string> &words){
    if(words.size() == 0)
        return "";
        
    unordered_map<string, int> m;
    
    for(int i=0; i<words.size(); i++)
        m[words[i]]++;
        
    int maxrepeat, secondmax;
    string s1, s2;
    maxrepeat = INT_MIN;
    secondmax = INT_MIN;
    unordered_map<string, int> :: iterator it;
    
    for(it = m.begin(); it != m.end(); it++){
        if(it->second >= maxrepeat){
            secondmax = maxrepeat;
            maxrepeat = it->second;
            s2 = s1;
            s1 = it->first;
        }
        
        else if(it->second > secondmax){
            secondmax = it->second;
            s2 = it->first;
        }
    }
    
    return s2;
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
	        string s;
	        cin>>s;
	        words.push_back(s);
	    }
	    
	    cout<<secondMostRepeat(words)<<endl;
	}
	return 0;
}