/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases. The next T lines contains a single integer N denoting the value of N.


Output:
Output the sum of all its digit until the result has only one digit.


Constraints:
1<=T<=30
1<=n<=10^9
*/

using namespace std;

int adddigit(int n){
    if(n / 10 == 0)
        return n;
    
    int x;    
    while(n / 10 != 0){
        x = 0;
        while(n != 0){
            x += (n % 10);
            n /= 10;
        }
        
        n = x;
    }
    
    return n;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    cout<<adddigit(n)<<endl;
	}
	return 0;
}