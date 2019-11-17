/*
For a given string delete the elements which are appearing more than once consecutively. All letters are of lowercase.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases,  a string will be inserted.


Output:
In each seperate line the modified string should be output.


Constraints:
1<=T<=31
1<=length(string)<=100


Example:
Input:
1
aababbccd

Output:
ababcd
*/



string consecutiveElement(string s){
    if(s.size() == 0)
        return s;
        
    int n, j;
    n = s.size();
    j = 0;
    
    for(int i=0; i<n - 1; i++){
        if(s[i] != s[i + 1]){
            s[j] = s[i];
            j++;
        }
    }
    
    s[j] = s[n - 1];
    j++;
    
    s.erase(j, n - j);
    
    return s;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    string s;
	    cin>>s;
	    
	    cout<<consecutiveElement(s)<<endl;
	}
	return 0;
}