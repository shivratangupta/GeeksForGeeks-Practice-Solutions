/*
Given an array of n words. Some words are repeated twice, we need count such words.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of words in the string. The next line contains n space separated words forming the string.

Output:
Print the count of the words which are repeated twice in the string.

Constraints:
1<=T<=105  
1<=no of words<=105
1<=length of each word<=105
*/

using namespace std;

int countRepeatedWords(vector<string> &words){
    if(words.size() == 0)
        return 0;
        
    unordered_map<string, int> m;
    int count;
    count = 0;
    
    for(int i=0; i<words.size(); i++)
        m[words[i]]++;
        
    unordered_map<string, int> :: iterator it;
    
    for(it = m.begin(); it != m.end(); it++){
        if(it->second == 2)
            count++;
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    vector<string> words;
	    for(int i=0; i<n; i++){
	        string s;
	        cin>>s;
	        words.push_back(s);
	    }
	    
	    cout<<countRepeatedWords(words)<<endl;
	}
	return 0;
}