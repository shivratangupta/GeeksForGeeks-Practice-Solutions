/*
Given an array you have to find  the max sum of i*A[i] where i is the index of the array obtained by rotating the element of the array one by one . Your task is to complete the function max_sum which takes one argument which is the array A [ ] and returns an integer value denoting  the required max sum .

Input:
The first line of input is the number of test cases T . Then T test cases follow . The first line of each test case is an integer N  denoting the size of the array . Then in the next line are N space separated values of the array A [ ] . 

Output:
For each test case output will be the required max sum.

Constraints:
1<=T<=100
1<=N<=100
1<=A[]<1000

Example:
Input
1
4
8 3 1 2
Output
29

Explanation
Above the configuration possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 =  11
Here the max sum is 29 
*/


int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
    int sum, result, curr;
    curr = 0;
    sum = 0;
    
    for(int i=0; i<N; i++){
        curr += i * A[i];
        sum += A[i];
    }
    
    result = curr;
    
    for(int i=1; i<N; i++){
        int next;
        next = curr + A[i - 1] * (N - 1);
        next -= (sum - A[i - 1]);
        curr = next;
        result = max(result, curr);
    }
    
    return result;
}