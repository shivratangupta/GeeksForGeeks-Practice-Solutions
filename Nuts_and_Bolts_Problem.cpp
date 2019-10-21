/*
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of nuts/bolts. Then follows the array of nuts, each element separated by a space. And finally the bolts array, again, each element is separated by a space here. Array of Nuts/Bolts can only consist of the following elements:{'@', '#', '$', '%', '^', '&', '~', '*', '!'}. And no element can be repeated.

Output:
For each test case, output the matched array of nuts and bolts in separate lines, where each element in the array is separated by a space. Print the elements in the following order ! # $ % & * @ ^ ~ 

Constraints:
1 <= T <= 70
1 <= N <= 9

Example:
Input:
2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ~ !
~ # @ % & * $ ^ ! 

Output:
# $ % @ ^
# $ % @ ^
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~
*/

using namespace std;

void nutsAndBolts(vector<char> &nuts, vector<char> &bolts){
    sort(nuts.begin(), nuts.end());
    sort(bolts.begin(), bolts.end());
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    
	    vector<char> nuts;
	    vector<char> bolts;
	    
	    for(int i=0; i<n; i++){
	        char c;
	        cin>>c;
	        nuts.push_back(c);
	    }
	    
	    for(int i=0; i<n; i++){
	        char c;
	        cin>>c;
	        bolts.push_back(c);
	    }
	    
	    nutsAndBolts(nuts, bolts);
	    
	    for(int i=0; i<n; i++)
	        cout<<nuts[i]<<" ";
	    
	    cout<<endl;
	    
	    for(int i=0; i<n; i++)
	        cout<<bolts[i]<<" ";
	        
	    cout<<endl;
	}
	return 0;
}