#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 🔴 Approach 1: Brute Force (Using Vector)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        preorder(root, nodes);
        
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
    }
};

// 🟡 Approach 2: Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// 🟢 Approach 3: Morris Traversal / Reverse Preorder
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution3 {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

// 🟡 Approach 2: Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
