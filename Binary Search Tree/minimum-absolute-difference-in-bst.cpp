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

// 🟢 Approach: In-order Traversal
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1;

    void inOrder(TreeNode* root) {
        if (!root) return;
        
        inOrder(root->left);
        
        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;
        
        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};
