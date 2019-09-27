/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a string, which contains only I's and D's in capital letter.

Output:
Print the minimum number following that pattern.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of String ≤ 8
*/

using namespace std;

void numberPattern(string s){
    int last, max_num;
    last = 0;
    max_num = 0;
    
    for(int i=0; i<s.size(); i++){
        int nd, j;
        nd = 0;
        
        if(s[i] == 'I'){
            j = i + 1;
        
            while(j < s.size() && s[j] == 'D')
                j++;
            
            nd = j - i - 1;
            
            if(i == 0){
                max_num = nd + 2;
                
                cout<<++last;
                cout<<max_num;
                
                last = max_num;
            }
            
            else{
                max_num += nd + 1;
                
                last = max_num;
                cout<<last;
            }
            
            for(int k=0; k<nd; k++){
                cout<<--last;
                i++;
            }
        }
        
        else{
            if(i == 0){
                j = i + 1;
                while(j < s.size() && s[j] == 'D')
                    j++;
                    
                nd = j - i - 1;
                
                max_num = nd + 2;
                cout<<max_num<<max_num - 1;
                
                last = max_num - 1;
            }
            
            else{
                cout<<last - 1;
                last--;
            }
        }
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	   string s;
	   cin>>s;
	   
	   numberPattern(s);
	   cout<<endl;
	}
	return 0;
}