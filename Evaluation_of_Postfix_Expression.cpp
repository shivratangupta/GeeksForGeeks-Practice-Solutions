/*
Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic operators like *,/,+ and - . 

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3
*/

#include<stack>
using namespace std;

int evalPost(string s){
    if(s.size() == 0)
        return 0;
        
    stack<int> st;
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i]))
            st.push(s[i] - '0');
            
        else{
            int a, b;
            a = st.top();
            st.pop();
            
            b = st.top();
            st.pop();
            
            if(s[i] == '+')
                st.push(b + a);
                
            else if(s[i] == '-')
                st.push(b - a);
                
            else if(s[i] == '*')
                st.push(b * a);
                
            else
                st.push(b / a);
        }
    }
    
    return st.top();
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
	    string s;
	    cin>>s;
	    
	    cout<<evalPost(s)<<endl;
	}
	return 0;
}