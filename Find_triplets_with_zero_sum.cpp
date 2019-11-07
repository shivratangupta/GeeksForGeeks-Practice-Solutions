/*
Given an array A[] of N elements. The task is to complete the function which returns true if triplets exists in array A whose sum is zero else returns false.

Input Format:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N, denoting the number of elements in array. The second line of each test case contains N space separated values of the array.

Output:
For each test case, output will be 1 if triplet exists else 0.

Your Task:
Your task is to complete the function findTriplets() which check if the triplet with sum 0 exists or not. This is of boolean type which returns either true of false.

Constrains:
1 <= T <= 100
1 <= N <= 106
-106 <= A <= 106

Example:
Input:
2
5
0 -1 2 -3 1
3
1 2 3

Output:
1
0

Explanation:
Testcase 1: 0, -1 and 1 forms a triplet with sum equal to 0.
Testcase 2: No triplet exists which sum to 0.
*/

using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}/*This is a function problem.You only need to complete the function given below*/

/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr, arr + n);
    
    for(int i=0; i<n-2; i++){
        int l, r, sum;
        l = i + 1;
        r = n - 1;
        
        while(l < r){
            sum = arr[i] + arr[l] + arr[r];
            
            if(sum == 0)
                return true;
                
            else if(sum < 0)
                l++;
                
            else
                r--;
        }
    }
    
    return false;
}