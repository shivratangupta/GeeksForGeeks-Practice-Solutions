/*
Given a binary string S. The task is to count the number of substrings that starts and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string S containing 0's and 1's.

Output:
For each test case, output a single line denoting number of substrings possible.

Constraints:
1 <= T <= 100
1 <= Length of String <= 100

Example:
Input:
1
10101

Output:
3

Explanation:
Testcase 1: First substring from index 0 to 2 starts and ends with 1. Second substring starts from index 2 and ends at index 4. Last substring is the whole string from index 0 to 4.
*/



int countSub(string s){
    if(s.size() < 2)
        return 0;
        
    int n;
    n = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1')
            n++;
    }
    
    return n * (n - 1) / 2;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<countSub(s)<<endl;
	}
	return 0;
}