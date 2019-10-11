/*
Given a number N. Write a program to check whether every bit in the binary representation of the given number is set or not.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains a single integer N which denotes the number to be checked.

Output:
For each test case, print "YES" without quotes if all bits of N are set otherwise print "NO".

Constraints:
1<=T<=1000
0<=N<=1000
*/

using namespace std;

void checkSetBits(int n){
    if(n == 0){
        cout<<"NO";
        return;
    }
    
    while(n != 1){
        if(n % 2 == 0){
            cout<<"NO";
            return;
        }
        
        n /= 2;
    }
    
    cout<<"YES";
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    
	    checkSetBits(n);
	    cout<<endl;
	}
	return 0;
}