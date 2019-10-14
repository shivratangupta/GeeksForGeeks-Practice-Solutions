/*
Given a dictionary of words and a pattern. Every character in the pattern is uniquely mapped to a character in the dictionary. The task is to complete a function findMatchedWords(dict,pattern) that returns a vector of strings matching with given pattern. The function takes two argument the first argument is an array of strings dict which denote the dictionary and the second argument is the pattern to match.

Input:
The first line of input contains an integer T denoting the number of test cases. Each testcase contains 3 lines. The first line contains an integer N denoting the number of strings in the dictionary,second line N space separated strings denoting the strings of the dictionary. The third line contains pattern.

Output:
The output for each test case will be the space separated strings that matches the given pattern in lexicographical order.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findMatchedWords()

Constraints:
1 <= T <= 100
1 <= N <= 10

Input
1
4
abb abc xyz xyy
foo

Output
abb xyy

Explanation
Testcase 1: In the above test case xyy and abb have same character at index 1 and 2 like the pattern.
*/

vector<string> findMatchedWords(vector<string> dict,
                      string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		cin>>s[i];
		
		string tt;
		cin>>tt;
		
		
		vector<string> res = findMatchedWords(s,tt);
  sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
		cout<<endl;
		
	}
}/*This is a function problem.You only need to complete the function given below*/
/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
bool check(string word, string pattern){
    if(word.size() != pattern.size())
        return false;
        
    unordered_map<char, char> m;
    
    for(int i=0; i<word.size(); i++){
        if(m.find(pattern[i]) == m.end())
            m[pattern[i]] = word[i];
            
        else if(m[pattern[i]] != word[i])
            return false;
    }
    
    return true;
}

vector<string> findMatchedWords(vector<string> dict,
                      string pattern)
{
       //Your code here
       
    if(pattern.size() == 0 || dict.size() == 0)
        return dict;
        
    vector<string> result;
    
    for(int i=0; i<dict.size(); i++){
        if(check(dict[i], pattern))
            result.push_back(dict[i]);
    }
    
    return result;
}