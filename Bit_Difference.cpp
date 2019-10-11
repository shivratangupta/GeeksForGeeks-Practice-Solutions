/*
You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is A and B separated by a space.

Output:
For each testcase, in a new line, print the number of bits needed to be flipped.

Constraints:
1 ≤ T ≤ 100
1 ≤ A, B ≤ 103
*/

using namespace std;

int countBitDiff(int a, int b){
    int n, count;
    n = a ^ b;
    count = 0;
    
    while(n){
        int x;
        x = n & 1;
        if(x)
            count++;
        
        n >>= 1;
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int a, b;
	    cin>>a>>b;
	    
	    cout<<countBitDiff(a, b)<<endl;
	}
	return 0;
}