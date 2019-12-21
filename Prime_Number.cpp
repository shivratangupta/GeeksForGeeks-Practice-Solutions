/*
For a given number N check if it is prime or not. A prime number is a number which is only divisible by 1 and itself.

Input:
First line contains an integer, the number of test cases 'T'. T testcases follow. Each test case should contain a positive integer N.

Output:
For each testcase, in a new line, print "Yes" if it is a prime number else print "No".

Constraints:
1 <= T <= 100
1 <= N <= 109

Example:
Input:
1
5
Output:
Yes

Explanation:
Testcase 1: 5 is the prime number as it is divisible only by 1 and 5.
*/


using namespace std;

void primeNumber(int n){
    if(n <= 1){
        cout<<"No";
        return;
    }
    
    int i;
    i = 2;
    
    while(i <= sqrt(n)){
        if(n % i == 0){
            cout<<"No";
            return;
        }
        
        else
            i++;
    }
    
    cout<<"Yes";
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    primeNumber(n);
	    
	    cout<<endl;
	}
	return 0;
}