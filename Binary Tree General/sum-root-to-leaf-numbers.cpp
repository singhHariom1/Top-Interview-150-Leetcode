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

// � Approach 1: Brute Force (Store Paths as Strings)
// Time Complexity: O(n * h) - string concatenation takes O(h)
// Space Complexity: O(n * h) - storing all paths
class Solution {
public:
    void findAllPaths(TreeNode* root, string currentPath, vector<string>& paths) {
        if (!root) return;
        
        currentPath += to_string(root->val);
        
        if (!root->left && !root->right) {
            paths.push_back(currentPath);
            return;
        }
        
        findAllPaths(root->left, currentPath, paths);
        findAllPaths(root->right, currentPath, paths);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<string> paths;
        findAllPaths(root, "", paths);
        
        int totalSum = 0;
        for (const string& path : paths) {
            totalSum += stoi(path);
        }
        return totalSum;
    }
};

// 🟢 Approach 2: Recursive DFS (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(n) - worst case (skewed tree)
class Solution2 {
public:
    int dfs(TreeNode* root, int currentSum) {
        if (!root) return 0;
        
        currentSum = currentSum * 10 + root->val;
        
        if (!root->left && !root->right) {
            return currentSum;
        }
        
        return dfs(root->left, currentSum) + dfs(root->right, currentSum);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

// 🟡 Approach 3: Iterative BFS (Queue)
// Time Complexity: O(n)
// Space Complexity: O(n) - max width of tree
class Solution3 {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int totalSum = 0;
        
        while (!q.empty()) {
            auto [node, currentSum] = q.front();
            q.pop();
            
            if (!node->left && !node->right) {
                totalSum += currentSum;
            }
            
            if (node->left) {
                q.push({node->left, currentSum * 10 + node->left->val});
            }
            if (node->right) {
                q.push({node->right, currentSum * 10 + node->right->val});
            }
        }
        
        return totalSum;
    }
};
