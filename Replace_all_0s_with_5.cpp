/*
You are given an integer n. You need to convert all zeroes of n to 5.

Input Format:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow . Each test case contains a single integer n denoting the number.

Output Format:
The output of the function will be an integer where all zero's are converted to 5 .

Your Task:
Your task is to complete the function convertFive which takes an integer n as argument and replaces all zeros in the number n with 5 .Your function should return the converted number .

Constraints:
1 <= T < 100
1 <= n <= 10000

Example:
Input
2
1004
121
Ouput
1554
121
*/

int convertFive(int n);
 
// Driver program to test above function
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	cout<<convertFive(n)<<endl;
    }
}/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
int convertFive(int n)
{
//Your code here

    if(n == 0)
        return 5;
        
    string s;
    s = to_string(n);
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0')
            s[i] = '5';
    }
    
    return stoi(s);
}