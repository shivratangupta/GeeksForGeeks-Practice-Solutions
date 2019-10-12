/*
Given a pattern as below and an integer n your task is to decode it and print nth row of it. The pattern follows as :
1
11
21
1211
111221
............

Input:
The first line of input is the number of test cases .  Then T test cases follow . The first line of each test case is an integer N.

Output:
For each test case print the required nth row of the pattern.

Constraints:
1<=T<=20
1<=N<=20
*/

using namespace std;

void decodePattern(int n){
    string s, s1;
    int count;
    count = 1;
    s = "1";
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<s.size(); j++){
            if(s[j] == s[j - 1])
                count++;
                
            else{
                s1 += count + '0';
                s1 += s[j - 1];
                count = 1;
            }
        }
        
        s1 += count + '0';
        s1 += s[s.size() - 1];
        s = s1;
        s1 = "";
        count = 1;
    }
    
    cout<<s;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    decodePattern(n);
	    cout<<endl;
	}
	return 0;
}