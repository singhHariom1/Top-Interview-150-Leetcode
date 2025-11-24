#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 🟢 Approach 1: Level Order Traversal with Constant Space
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* curr = root; // Head of current level
        Node* dummy = new Node(0); // Dummy head for next level
        Node* prev = dummy; // Iterator for next level
        
        while (curr) {
            if (curr->left) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right) {
                prev->next = curr->right;
                prev = prev->next;
            }
            
            curr = curr->next; // Move to next node in current level
            
            if (!curr) { // End of current level
                curr = dummy->next; // Move to first node of next level
                dummy->next = nullptr; // Reset dummy
                prev = dummy; // Reset prev
            }
        }
        
        return root;
    }
};

// 🟡 Approach 2: BFS with Queue
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (prev) prev->next = curr;
                prev = curr;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        
        return root;
    }
};
