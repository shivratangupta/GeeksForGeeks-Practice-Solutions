/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20
*/

#include<vector>
using namespace std;

struct TrieNode{
    vector<TrieNode*> children;
    bool isEndOfWord;
};

void insert(TrieNode* root, string s){
    TrieNode* temp;
    temp = root;
    
    for(int i=0; i<s.size(); i++){
        int index;
        index = s[i] - 'a';
        
        if(temp->children[index] == NULL){
            TrieNode* temp1 = new TrieNode();
            for(int i=0; i<26; i++)
                temp1->children.push_back(NULL);
            temp1->isEndOfWord = false;
            
            temp->children[index] = temp1;
        }
        
        temp = temp->children[index];
    }
    
    temp->isEndOfWord = true;
}

bool search(TrieNode* root, string s){
    TrieNode* temp;
    temp = root;
    
    for(int i=0; i<s.size(); i++){
        int index;
        index = s[i] - 'a';
        
        if(temp->children[index] == NULL)
            return false;
        
        temp = temp->children[index];
    }
    
    return temp != NULL && temp->isEndOfWord;
}

int main()
 {
	//code
	TrieNode* root = new TrieNode();
	for(int i=0; i<26; i++)
	    root->children.push_back(NULL);
	
    root->isEndOfWord = false;
	    
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    for(int i=0; i<n; i++){
	        string s;
	        cin>>s;
	        insert(root, s);
	    }
	    
	    string s1;
	    cin>>s1;
	    cout<<search(root, s1)<<endl;
	}
	return 0;
}