/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Input:
The first line of input contains an integer T denoting the number of test cases. There will be a single line for each testcase which contains N.

Output:
Print all binary numbers with decimal values from 1 to N in a single line.

Constraints:
1 ≤ T ≤ 106
1 ≤ N ≤ 106
*/

#include<queue>
using namespace std;

void generateBinary(int n){
    if(n == 0){
        cout<<0;
        return;
    }
    
    queue<string> q;
    q.push("1");
    
    while(n > 0){
        string s;
        s = q.front();
        q.pop();
        
        cout<<s<<" ";
        q.push(s + "0");
        q.push(s + "1");
        
        n--;
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    
	    generateBinary(n);
	    cout<<endl;
	}
	return 0;
}