/*
You are given a string S of alphabet characters and the task is to find its matching decimal representation as on the shown keypad. Output the decimal representation corresponding to the string. For ex: if you are given “amazon” then its corresponding decimal representation will be 262966.



Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing a string.

Output:
For each test case, print in a new line, the corresponding decimal representation of the given string.

Constraints:
1 ≤ T ≤ 100
1 ≤ length of String ≤ 100

Example:
Input
2
geeksforgeeks
geeksquiz

Output
4335736743357
433577849
*/


void keypadTyping(string s){
    string result;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'c')
            result += '2';
            
        else if(s[i] >= 'd' && s[i] <= 'f')
            result += '3';
            
        else if(s[i] >= 'g' && s[i] <= 'i')
            result += '4';
            
        else if(s[i] >= 'j' && s[i] <= 'l')
            result += '5';
            
        else if(s[i] >= 'm' && s[i] <= 'o')
            result += '6';
            
        else if(s[i] >= 'p' && s[i] <= 's')
            result += '7';
            
        else if(s[i] >= 't' && s[i] <= 'v')
            result += '8';
            
        else
            result += '9';
    }
    
    cout<<result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    keypadTyping(s);
	    
	    cout<<endl;
	}
	return 0;
}