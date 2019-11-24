/*
You have been given an alphanumeric string S, extract maximum numeric value from that string. Alphabets will only be in lower case.

Input:
The first line contains a single integer T i.e. the number of test cases. T testcases follow. The first and only line consists of a String S.

Output: 
For each testcase, in a new line, print the Maximum number extracted from the string S.

Constraints:
1 <= T <= 100
2 <= |S| <= 200

Example:
Input:
3
100klh564abc365bg
abvhd9sdnkjdfs
abchsd0sdhs
Output:
564
9
0

Explanation:
Test Case 1: The maximum number found in the string is "564".  
*/


int extractMaximum(string s){
    if(s.size() == 0)
        return 0;
    
    int i, j, n, result;
    i = 0;
    n = s.size();
    result = 0;
    
    while(i < n){
        while(i < n && !isdigit(s[i]))
            i++;
        
        int num;
        num = 0;
        while(i< n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            i++;
        }
        
        if(num > result)
            result = num;
    }
    
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<extractMaximum(s)<<endl;
	}
	return 0;
}