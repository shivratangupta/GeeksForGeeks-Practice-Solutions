/*
Given a 32 bit number x, reverse its binary form and print the answer in decimal.

Input:
The first line of input consists T denoting the number of test cases. T testcases follow. Each test case contains a single 32 bit integer

Output:
For each test case, in a new line, print the reverse of integer.

Constraints:
1 <= T <= 100
0 <= x <= 4294967295

Example:
Input:
2
1
5
Output:
2147483648
2684354560

Explanation:
Testcase1:
00000000000000000000000000000001 =1
10000000000000000000000000000000 =2147483648
*/


uint32_t reverseBits(uint32_t n){
    uint32_t reverse;
    int count;
    reverse = n;
    count = 31;
    
    n >>= 1;
    while(n){
        reverse <<= 1;
        reverse |= n & 1;
        n >>= 1;
        count--;
    }
    
    reverse <<= count;
    
    return reverse;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    uint32_t n;
	    cin>>n;
	    
	    cout<<reverseBits(n)<<endl;
	}
	return 0;
}