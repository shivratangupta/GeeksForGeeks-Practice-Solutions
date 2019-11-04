/*
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

User Task:
The task is to complete the function reverseWords() which reverse words from the given string and prints the answer. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

Explanation:
Testcase 1: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.
*/


void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}/*This is a function problem.You only need to complete the function given below*/

/*Function to reverse words*/

void reverse(char* begin, char* end){
    char temp;
    
    while(begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char *s) {
    
    // Your code here
    char* start = NULL;
    char* temp = s;
    
    while(*temp){
        if(start == NULL && *temp != '.')
            start = temp;
            
        if(start && (*(temp + 1) == '.' || *(temp + 1) == '\0')){
            reverse(start, temp);
            start = NULL;
        }
        
        temp++;
    }
    
    reverse(s, temp - 1);
    
    printf("%s", s);
}
