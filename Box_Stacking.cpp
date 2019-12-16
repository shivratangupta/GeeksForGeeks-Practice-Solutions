/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Input:
The first line of input contains an integer T denoting the number of test cases then T test cases follow. Each test case contains an integer N denoting the total no of boxes available. In the next line are 3*N space separated values denoting the height, width and length of the N boxes.

Output:
For each test case in a new line output will be the highest possible stack height which could be formed.

Constraints:
1<=T<=100
1<=N<=100
1<=l,w,h<=100

Example (To be used for expected output) :
Input:
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

Output
60
15
*/


determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct Box{
    int h;
    int w;
    int l;
};

int compare(void const *a, void const *b){
    return ((*(Box *)b).l * (*(Box *)b).w) - ((*(Box *)a).l * (*(Box *)a).w);
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    Box arr[3 *n];
    int index;
    index = 0;
    
    for(int i=0; i<n; i++){
        arr[index].h = height[i];
        arr[index].w = max(width[i], length[i]);
        arr[index].l = min(width[i], length[i]);
        index++;
        
        arr[index].h = width[i];
        arr[index].w = max(height[i], length[i]);
        arr[index].l = min(height[i], length[i]);
        index++;
        
        arr[index].h = length[i];
        arr[index].w = max(height[i], width[i]);
        arr[index].l = min(height[i], width[i]);
        index++;
    }
    int m;
    m = 3 * n;
    
    qsort(arr, m, sizeof(arr[0]), compare);
    
    vector<int> dp(m);
    
    for(int i=0; i<m; i++)
        dp[i] = arr[i].h;
    
    for(int i=1; i<m; i++){
        for(int j=0; j<i; j++){
            if(arr[i].w < arr[j].w && arr[i].l < arr[j].l && dp[i] < dp[j] + arr[i].h)
                dp[i] = dp[j] + arr[i].h;
        }
    }
    
    int maxheight;
    maxheight = dp[0];
    
    for(int i=1; i<m; i++){
        if(dp[i] > maxheight)
            maxheight = dp[i];
    }
    
    return maxheight;
}