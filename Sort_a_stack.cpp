/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer N denoting the size of the stack. Then in the next line are N space separated values which are pushed to the the stack. 

Output:
For each test case output will be the popped elements from the sorted stack.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input:
2
3
3 2 1
5
11 2 32 3 41

Output:
3 2 1
41 32 11 3 2

Explanation:
For first test case stack will be
1
2
3
After sorting 
3
2 
1

When elements  popped : 3 2 1
*/

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void sortStack(int n, stack<int> &s){
    if(s.empty() || s.top() < n)
        s.push(n);
        
    else{
        int temp;
        temp = s.top();
        s.pop();
        sortStack(n, s);
        s.push(temp);
    }
}
void SortedStack :: sort()
{
   //Your code here
   if(!s.empty()){
       int temp;
       temp = s.top();
       s.pop();
       
       sort();
       sortStack(temp, s);
   }
}