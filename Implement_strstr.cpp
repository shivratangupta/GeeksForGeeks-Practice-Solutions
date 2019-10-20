/*
Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s.

Input Format:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two strings s and x.

Output Format:
For each test case, in a new line, output will be an integer denoting the first occurrence of the x in the string s. Return -1 if no match found.

Your Task:
Since this is a function problem, you don't have to take any input. Just complete the strstr() function. The function returns -1 if no match if found else it returns an integer denoting the first occurrence of the x in the string s.

Constraints:
1 <= T <= 200
1<= |s|,|x| <= 1000

Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5

Explanation:
Testcase 1: Fr is not present in the string GeeksForGeeks as substring.
Testcase 2: For is present as substring in GeeksForGeeks from index 5.
*/

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
    int m, n;
    m = s.size();
    n = x.size();
     
    if(m == 0)
        return -1;
        
    for(int i=0; i<m-n+1; i++){
        if(s[i] == x[0] && s.substr(i, n) == x)
            return i;
    }
    
    return -1;
}