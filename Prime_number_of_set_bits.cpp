/*
Given two integers ‘L’ and ‘R’, write a program that finds the count of numbers having prime number of set bits in their binary representation in the range [L, R].

Input:
The first line consists of an integer T i.e number of test cases. The first and only line of each test case consists of two integers L and R. 

Output:
Print the required output.

Constraints: 
1<=T<=100
1<=L<=R<=100000

Example:
Input:
2
6 10
10 15 

Output:
4
5
*/


int primeNumberSetBits(int l, int r){
    int count, totalbits;
    count = 0;
    
    vector<bool> prime(33, true);
    prime[0] = false;
    prime[1] = false;
    
    for(int i=2; i*i<=32; i++){
        if(prime[i]){
            for(int j=i*i; j<=32; j+=i)
                prime[j] = false;
        }
    }
    
    for(int i=l; i<=r; i++){
        totalbits = __builtin_popcount(i);
        
        if(prime[totalbits])
            count++;
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int l, r;
	    cin>>l>>r;
	    
	    cout<<primeNumberSetBits(l, r)<<endl;
	}
	return 0;
}