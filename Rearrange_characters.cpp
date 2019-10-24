/*
Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.
*/

using namespace std;

bool rearrangeChar(string s){
    if(s.size() == 0)
        return true;
    
    int n;
    n = s.size();
    
    vector<int> count(26);
    for(int i=0; i<n; i++)
        count[s[i] - 'a']++;
        
    priority_queue<pair<int, char> > h;
    
    for(int i=0; i<26; i++){
        if(count[i] > 0){
            char c;
            c = i + 'a';
            h.push(make_pair(count[i], c));
        }
    }
    
    s = "";
    pair<int, char> prev;
    prev = make_pair(-1, '#');
    
    while(!h.empty()){
        pair<int, char> p;
        p = h.top();
        h.pop();
        
        s += p.second;
        p.first = p.first - 1;;
        
        if(prev.first > 0)
            h.push(prev);
            
        prev = p;
    }
    
    return s.size() == n;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<rearrangeChar(s)<<endl;
	}
	return 0;
}