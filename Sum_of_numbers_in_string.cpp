/*
Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105
*/

using namespace std;

int sumNumbers(string s){
    int result, i;
    result = 0;
    i = 0;
    
    while(i < s.size()){
        int num = 0;
        while(i <s.size() && !isdigit(s[i]))
            i++;
            
        while(i < s.size() && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            i++;
        }
        
        result += num;
    }
    
    return result;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    string s;
	    cin>>s;
	    cout<<sumNumbers(s)<<endl;
	}
	return 0;
}