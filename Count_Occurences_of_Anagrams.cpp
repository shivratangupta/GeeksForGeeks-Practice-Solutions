/*
Given a word S and a text C. Return the count of the occurences of anagrams of the word in the text.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a text S consisting of only lowercase characters.
The second line contains a word consisting of only lowercase characters.

Output:
Print the count of the occurences of anagrams of the word C in the text S.

Constraints:
1 <= T <= 50
1 <= |S| <= |C| <= 50
*/

#include<vector>
using namespace std;

bool isValid(vector<int> &count){
    for(int i=0; i<count.size(); i++){
        if(count[i] != 0)
            return false;
    }
    
    return true;
}

int countOfAnagrams(string s1, string s2){
    vector<int> count(26);
    int m, n, result;
    m = s1.size();
    n = s2.size();
    result = 0;
    
    for(int i=0; i<n; i++)
        count[s2[i] - 'a']++;
        
    for(int i=0; i<n; i++)
        count[s1[i] - 'a']--;
        
    if(isValid(count))
        result++;
        
    for(int i=n; i<m; i++){
        count[s1[i] - 'a']--;
        count[s1[i - n] - 'a']++;
        
        if(isValid(count))
            result++;
    }
    
    return result;
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
        
        cout<<countOfAnagrams(s1, s2)<<endl;
    }
	return 0;
}