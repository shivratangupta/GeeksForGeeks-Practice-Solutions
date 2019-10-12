/*
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is N.

Output:
For each testcase, in a new line, print the total count of all bits.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103

Example:
Input:
2
4
17
Output:
5
35

Explanation:
Testcase1:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0
0 0 1 = 1
0 1 0 = 1
0 1 1 = 2
1 0 0 = 1
Therefore , the total number of bits is 5.
*/

using namespace std;

int countBits(int n){
    if(n == 0)
        return 0;
    
    n++;
    int power, count;
    power = 2;
    count = n / 2;
    
    while(power <= n){
        int pairs;
        pairs = n / power;
        
        count += (pairs / 2) * power;
        
        count += (pairs & 1) ? (n % power) : 0;
        
        power <<= 1;
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    cout<<countBits(n)<<endl;
	}
	return 0;
}