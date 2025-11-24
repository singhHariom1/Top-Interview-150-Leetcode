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

// 🟢 Approach: BFS with Flag
// Time Complexity: O(n)
// Space Complexity: O(w)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine position based on current direction
                int index = leftToRight ? i : (size - 1 - i);
                currentLevel[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
            leftToRight = !leftToRight; // Toggle direction
        }
        
        return result;
    }
};
