/*
In given range, print all numbers having unique digits. e.g. In range 1 to 20 should print all numbers except 11.

Input:
First line consists of T test cases.
The only line of every test case consists of two integers m and n separated by a space.

Output:
For each test case print all unique numbers separated by space.

Constraints:
1<=T<=100
1<=m,n<1000

Example:
Input:
1
10 20
Output:
10 12 13 14 15 16 17 18 19 20
*/


void uniqueNumbers(int l, int r){
    
    for(int i=l; i<=r; i++){
        int num;
        vector<int> vis(10);
        num = i;
        
        while(num){
            if(vis[num % 10])
                break;
                
            vis[num % 10] = true;
            
            num /= 10;
        }
        
        if(num == 0)
            cout<<i<<" ";
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int l, r;
	    cin>>l>>r;
	    
	    uniqueNumbers(l, r);
	    
	    cout<<endl;
	}
	return 0;
}