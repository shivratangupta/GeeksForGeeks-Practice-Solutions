/*
Given an integer X within the range of 0 to 9, and given two positive integers as upper and lower bounds respectively, find the number of times X occurs as a digit in an integer within the range, excluding the bounds. Print the frequency of occurrence as output.

Input:
The first line of input is an integer T, denoting the number of test cases. For each test case, there are two lines of input, first consisting of the integer X, whose occurrence has to be counted. Second, the lower and upper bound, L and U which are positive integers, on the same line separated by a single space, respectively.

Output:
For each test case, there is only one line of output, the count of the occurrence of X as a digit in the numbers lying between the lower and upper bound, excluding them.

Constraints:
1<=T<=100
0<=X<=9
0<L<U<=10^5
*/

using namespace std;

int countRange(int x, int a, int b){
    int n, count;
    count = 0;
    for(int i=a+1; i<b; i++){
        n = i;
        while(n != 0){
            if(n % 10 == x)
                count++;
            
            n /= 10;
        }
    }
    
    return count;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int x, a, b;
	    cin>>x;
	    cin>>a>>b;
	    
	    cout<<countRange(x, a, b)<<endl;
	}
	return 0;
}