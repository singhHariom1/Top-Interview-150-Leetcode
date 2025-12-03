#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
  public:
    // Array for children nodes of each node
    TrieNode *children[26];

    // for end of word
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

};
  // Method to insert a key into the Trie
void insert(TrieNode *root, const string &key){
    TrieNode* curr =root;
    for(char c:key){
        if(curr->children[c-'a']==nullptr){
            TrieNode* newNode =new TrieNode();
            curr->children[c-'a']=newNode;
        }
        curr=curr->children[c-'a'];
    }
    curr->isLeaf=true;
}

// Method to search a key in the Trie
bool search(TrieNode *root, const string &key){
    if(root==nullptr){
        return false;
    }

    TrieNode* curr= root;
    for(char c:key){
        if(curr->children[c-'a']==nullptr){
            return false;
        }
        curr=curr->children[c-'a'];
    }
    return curr->isLeaf;
}

// Method to check if a prefix exists in the Trie
bool isPrefix(TrieNode *root, const string &prefix){
    if(root==nullptr){
        return false;
    }

    TrieNode* curr=root;
    for(char c:prefix){
        if(curr->children[c-'a']==nullptr){
            return false;
        }
        curr=curr->children[c-'a'];
    }
    return true;
}

void deleteKey(TrieNode *root, const string &key){
    if(root==nullptr){
        return;
    }

    TrieNode* curr=root;
    for(char c:key){
        if(curr->children[c-'a']==nullptr){
            return;
        }
        curr=curr->children[c-'a'];
    }
    curr->isLeaf=false;
}

int main()
{

    // Create am example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};
    for (const string &s : arr)
    {
        insert(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout<<"\n";

    // One by one search for prefixes
    vector<string> prefixKeys = {"ge", "ba", "do", "de"};
    for (string &s : prefixKeys){
        
        if (isPrefix(root, s))
            cout << "true ";
        else
            cout << "false ";
    }
    cout<<"\n";

    deleteKey(root, "do");

    // One by one search strings
    vector<string> searchKeys2 = {"do", "gee", "bat"};
    for (string &s : searchKeys2){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout<<"\n";

    return 0;
}