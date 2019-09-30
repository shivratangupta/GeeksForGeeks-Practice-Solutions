/*
Given 3 characters a, b, c. Find the number of strings of length n that can be formed from these 3 characters. Given that : we can use ‘a’ as many times as we want, ‘b’ maximum once, and ‘c’ maximum twice.

Input:
The first line of input contains an integer T denoting the number of test cases. The first and last line of each test case consists of an integer n. 

Output:
Print the total number of string that can be formed.

Constraints: 
1<=T<=20
1<=N<=20
*/

using namespace std;

int totalStrings(int n){
    return (1 + 2 * n + (n * (n * n - 1)) / 2);
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    cout<<totalStrings(n)<<endl;
	}
	return 0;
}