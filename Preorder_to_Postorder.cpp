/*
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40
*/

using namespace std;

void preToPost(vector<int> pre, int minval, int maxval, int &index){
    if(index == pre.size())
        return;
        
    if(pre[index] < minval || pre[index] > maxval)
        return;
        
    int val;
    val = pre[index];
    index++;
    
    preToPost(pre, minval, val, index);
    preToPost(pre, val, maxval, index);
    
    cout<<val<<" ";
}

void preorderToPostorder(vector<int> pre){
    int index;
    index = 0;
    
    preToPost(pre, INT_MIN, INT_MAX, index);
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    vector<int> pre;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        pre.push_back(num);
	    }
	    
	    preorderToPostorder(pre);
	    
	    cout<<endl;
	}
	return 0;
}