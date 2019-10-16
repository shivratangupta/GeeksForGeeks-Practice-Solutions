/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.
*/

using namespace std;

struct meet{
    int start;
    int end;
    int pos;
};

bool comparison(meet a, meet b){
    return a.end < b.end;
}

void meetings(vector<int> &startM, vector<int> &finishM){
    int n;
    n = startM.size();
    
    if(n == 0)
        return;
        
    vector<meet> pairs;
    for(int i=0; i<n; i++){
        meet m;
        m.start = startM[i];
        m.end = finishM[i];
        m.pos = i + 1;
        
        pairs.push_back(m);
    }
    
    sort(pairs.begin(), pairs.end(), comparison);
    
    int endtime;
    endtime = pairs[0].end;
    cout<<pairs[0].pos<<" ";
    
    for(int i=1; i<n; i++){
        if(pairs[i].start > endtime){
            cout<<pairs[i].pos<<" ";
            endtime = pairs[i].end;
        }
    }
}

int main()
 {
	//code
    int t;
    cin>>t;
    
    for(int l=0; l<t; l++){
        int n;
        cin>>n;
        
        vector<int> startM;
        vector<int> finishM;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            startM.push_back(num);
        }
        
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            finishM.push_back(num);
        }
        
        meetings(startM, finishM);
        
        cout<<endl;
    }
	return 0;
}