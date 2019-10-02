/*
Given two strings s1 and s2, remove those characters from first string which are present in second string. Both the strings are different and contain only lowercase characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is s1,s1 is first string.
The second line of each test case contains s2,s2 is second string.

Output:

Print the modified string(s1). For each test case, print the output in a new line.

Constraints:

1 ≤ T ≤ 15
1 ≤ s2 < s1 ≤ 50

*/

using namespace std;

string removeChar(string s1, string s2){
    if(s2.size() == 0)
        return s1;
    
    unordered_set<char> s;
    
    for(int i=0; i<s2.size(); i++)
        s.insert(s2[i]);
        
    for(int i=0; i<s1.size(); i++){
        if(s.find(s1[i]) != s.end()){
            s1.erase(i, 1);
            i--;
        }
    }
    
    return s1;
}

int main()
{
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s1, s2;
	    cin>>s1;
	    cin>>s2;
	    
	    cout<<removeChar(s1, s2)<<endl;
	}
	return 0;
}