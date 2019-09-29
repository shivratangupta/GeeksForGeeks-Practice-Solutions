/*
Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc

*/

using namespace std;

int countSubsequences(string s){
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'a')
            a = 1 + 2 * a;
        
        else if(s[i] == 'b')
            b = a + 2 * b;
            
        else if(s[i] == 'c')
            c = b + 2 * c;
    }
    
    return c;
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
	    string s;
	    cin>>s;
	    cout<<countSubsequences(s)<<endl;
	}
	return 0;
}