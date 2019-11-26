/*
Given an array of n integers(duplicates allowed). Print “Yes” if it is a set of contiguous integers else print “No”.


INPUT: The first line consists of an integer T i.e. the number of test cases. First line of each test case consists of an integer n, denoting the size of array. Next line consists of n spaced integers, denoting elements of array.


OUTPUT:  Print “Yes” if it is a set of contiguous integers else print “No”.

 

CONSTRAINTS:
1<=T<=100
1<=n<100000
a[i]<=105

 Example:

 2
8
5  2  3  6  4  4  6  6
7
10  14  10  12  12  13  15

Output :
 Yes
 No

Explanation:
Test Case 1 : The elements  of array form a contiguous set of integers which is {2, 3, 4, 5, 6} so the output is Yes.
Test Case 2: We are unable to form contiguous set of integers using elements of array.
*/



void checkContiguousInteger(vector<int> &nums){
    unordered_set<int> s;
    
    for(int i=0; i<nums.size(); i++)
        s.insert(nums[i]);
        
    int count, start;
    count = 1;
    start = nums[0] - 1;
    
    while(s.find(start) != s.end()){
        count++;
        start--;
    }
    
    start = nums[0] + 1;
    
    while(s.find(start) != s.end()){
        count++;
        start++;
    }
    
    if(count == s.size())
        cout<<"Yes";
        
    else
        cout<<"No";
    
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    checkContiguousInteger(nums);
	    
	    cout<<endl;
	}
	return 0;
}