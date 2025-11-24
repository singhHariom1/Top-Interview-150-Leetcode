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

// 🟢 Approach 1: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        if (!root->left && !root->right && targetSum - root->val == 0) {
            return true;
        }
        
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};

// 🟡 Approach 2: Iterative DFS (Stack)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        stack<pair<TreeNode*, int>> s;
        s.push({root, targetSum - root->val});
        
        while (!s.empty()) {
            auto [node, currSum] = s.top();
            s.pop();
            
            if (!node->left && !node->right && currSum == 0) return true;
            
            if (node->right) s.push({node->right, currSum - node->right->val});
            if (node->left) s.push({node->left, currSum - node->left->val});
        }
        
        return false;
    }
};
